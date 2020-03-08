#include <kern/e1000.h>
#include <kern/pmap.h>
#include <kern/pci.h>

#include <inc/string.h>

// LAB 6: Your driver code here
struct TD transmit_desc_list[32] __attribute__ ((aligned (PGSIZE))) = { 0 };
struct RD receive_desc_list[128] __attribute__ ((aligned (PGSIZE))) = { 0 };
struct packet tbuf[32] __attribute__ ((aligned (PGSIZE))) =  { 0 };
struct packet rbuf[128] __attribute__ ((aligned (PGSIZE))) =  { 0 };
volatile uint32_t *mmio_e1000;

static void
pciw(int index, int value) {
   mmio_e1000[index] = value;
   mmio_e1000[index];
}

int
e1000_attach(struct pci_func *pcif)
{
    //negotiates an MMIO region
    pci_func_enable(pcif);
    desc_init();

    //map to MMIOBASE
    mmio_e1000 = mmio_map_region(pcif->reg_base[0], pcif->reg_size[0]);
    //cprintf("base: %x size: %x \n", pcif->reg_base[0], pcif->reg_size[0]);
    //cprintf("E1000 STATUS REGISTER VALUE: %x\n", *(mmio_e1000+2));

    //ex5: transmition initilizes
    transmit_init();
    recv_init();
    return 1;
}

static void
desc_init()
{

    int i;
    for(i = 0; i < 32; ++i) {
        memset(&transmit_desc_list[i], 0, sizeof(struct TD));
        transmit_desc_list[i].addr = PADDR(&tbuf[i]);
        transmit_desc_list[i].status = TXD_STAT_DD;
        transmit_desc_list[i].cmd =  TXD_CMD_RS | TXD_CMD_EOP;
    }
    // receive
    for (i = 0; i < 128; ++i) {
        memset(&receive_desc_list[i], 0, sizeof(struct RD));
        receive_desc_list[i].addr = PADDR(&rbuf[i]);
    }
}

int
transmit_init()
{
    //TD Base Address register
    pciw(E1000_TDBAL, PADDR(transmit_desc_list));
    pciw(E1000_TDBAH, 0);

    //TD Descriptor Length register
    pciw(E1000_TDLEN, 32 * sizeof(struct TD));

    //TD head and tail register
    pciw(E1000_TDH, 0x0);
    pciw(E1000_TDT, 0x0);

    //TD control register
    pciw(E1000_TCTL, TCTL_EN | TCTL_PSP | (TCTL_CT & (0x10 << 4)) | (TCTL_COLD & (0x40 << 12)));

    //Transmit Inter Packets Gap register
    pciw(E1000_TIPG, 10 | (8 << 10) | (12 << 20));
    return 0;
}

int
recv_init()
{
    //Receive Address Register
    //pciw(E1000_RA, 0x52540012);
    pciw(E1000_RA, 0x12005452);
    pciw(E1000_RA+1, 0x5634 | E1000_RAV);

    //Multicast Table Array
    for (int i = 0; i < 128; i++)
        pciw(E1000_MTA+i, 0);
    //Base Address register
    pciw(E1000_RDBAL, PADDR(receive_desc_list));
    pciw(E1000_RDBAH, 0);

    // Descriptor Length
    pciw(E1000_RDLEN, sizeof(struct RD) * 128);

    // head and tail register
    pciw(E1000_RDH, 0);
    pciw(E1000_RDT, 128-1);

    pciw(E1000_RCTL, RCTL_EN | RCTL_LPE | RCTL_LBM_NO | RCTL_SZ_2048 | RCTL_SECRC);

    return 0;
}

int
transmit(void *addr, size_t len)
{
    uint32_t tail = mmio_e1000[E1000_TDT];
    struct TD *next_desc = &transmit_desc_list[tail];

    if ((next_desc->status & TXD_STAT_DD) != TXD_STAT_DD)
        return -1;
    if (len > PKTSIZE)
        len = PKTSIZE;

    memmove(&tbuf[tail], addr, len);
    next_desc->length = len;
    next_desc->status &= !TXD_STAT_DD;
    mmio_e1000[E1000_TDT] = (tail+1) % 32;
    //cprintf("send : %s\n", addr);
    return 0;

}


// return -1 if state != RXD_STAT_DD
int
receive(void *addr,size_t len)
{
    uint32_t tail = (mmio_e1000[E1000_RDT] + 1) % 128;
    struct RD *next_desc = &receive_desc_list[tail];


    if ((next_desc->status & RXD_STAT_DD) != RXD_STAT_DD)
        return -1;

    //cprintf("tail value :%d\n", tail) ;
    //cprintf("buflen %d desclen %d\n", len, next_desc->length);
    if (next_desc->length < len)
        len = next_desc->length;

    memcpy(addr, &rbuf[tail], len);
    next_desc->status &= !RXD_STAT_DD;
    mmio_e1000[E1000_RDT] = tail;
    return next_desc->length;
}
