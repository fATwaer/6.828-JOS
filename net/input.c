#include "ns.h"
#include <inc/lib.h>

extern union Nsipc nsipcbuf;
#define RDBUF 128
void
input(envid_t ns_envid)
{
	binaryname = "ns_input";

	// LAB 6: Your code here:
	// 	- read a packet from the device driver
	//	- send it to the network server
	// Hint: When you IPC a page to the network server, it will be
	// reading from it for a while, so don't immediately receive
	// another packet in to the same physical page.
    int i, r;
    struct jif_pkt *head, *pkt = (struct jif_pkt*)&nsipcbuf;
    // 10 buffers
    for (i = 0; i < RDBUF; ++i)
        if ((r = sys_page_alloc(0, (void *)((uint32_t)pkt + i * PGSIZE), PTE_U | PTE_P | PTE_W)) < 0)
            panic("alloc error");

    i = 0;
    head = pkt;
    while (1) {
        while((r = sys_net_receive((void *)((uint32_t)pkt + sizeof(pkt->jp_len)), PGSIZE - sizeof(pkt->jp_len))) <= 0) {
            sys_yield();
        }
        //cprintf("r %d pkt : %x | [i] : %d  \n", r, pkt, i);
        pkt->jp_len = r;
        ipc_send(ns_envid, NSREQ_INPUT, pkt, PTE_P | PTE_U | PTE_W);
        pkt = (struct jif_pkt *)((uint32_t)pkt + PGSIZE);
        if (i++ == RDBUF-1) {
            pkt = head;
            i = 0;
        }
    }
}
