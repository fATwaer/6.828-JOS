#ifndef JOS_KERN_E1000_H
#define JOS_KERN_E1000_H

#include <inc/types.h>

#define E1000_TCTL 0x00400/4
    #define TCTL_EN 0x2
    #define TCTL_PSP 0x8
    #define TCTL_CT 0xFF0
    #define TCTL_COLD 0x3FF000
#define E1000_TIPG 0x00410/4

#define E1000_TDBAL 0x03800/4
#define E1000_TDBAH 0x03804/4
#define E1000_TDLEN 0x03808/4
#define E1000_TDH   0x03810/4
#define E1000_TDT   0x03818/4

// command
#define TXD_STAT_DD 0x01
#define TXD_CMD_RS  0x08
#define TXD_CMD_EOP 0x01

// recv
#define RXD_STAT_DD       0x01
#define RXD_STAT_EOP      0x02

#define E1000_RCTL     0x00100/4
    #define RCTL_EN             0x00000002
    #define RCTL_LPE            0x00000020
    #define RCTL_LBM_NO         0x00000000
    #define RCTL_SZ_2048        0x00000000
    #define RCTL_SECRC          0x04000000
#define E1000_RDBAL    0x02800/4
#define E1000_RDBAH    0x02804/4
#define E1000_RDLEN    0x02808/4
#define E1000_RDH      0x02810/4
#define E1000_RDT      0x02818/4
#define E1000_MTA      0x05200/4
#define E1000_RA       0x05400/4
    #define E1000_RAV      0x80000000

struct TD //tx_desc
{
	uint64_t addr;
	uint16_t length;
	uint8_t cso;
	uint8_t cmd;
	uint8_t status;
	uint8_t css;
	uint16_t special;
}__attribute__((packed));

struct RD {
    uint64_t addr;
    uint16_t length;
    uint16_t checksum;
    uint8_t status;
    uint8_t errors;
    uint16_t special;
}__attribute__((packed));


#define PKTSIZE 2048
struct packet {
    char buf[PKTSIZE];
};

struct pci_func;
static void desc_init();
int transmit_init();
int recv_init();
int e1000_attach(struct pci_func *pcif);
int transmit(void *addr, size_t len);
int receive(void *addr,size_t len);
#endif  // SOL >= 6
