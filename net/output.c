#include "ns.h"
#include "inc/lib.h"

extern union Nsipc nsipcbuf;

void
output(envid_t ns_envid)
{
	binaryname = "ns_output";

	// LAB 6: Your code here:
	// 	- read a packet from the network server
	//	- send the packet to the device driver
    union Nsipc output;
    int perm;
    envid_t envid;
    // LAB 6: Your code here:
    //  - read a packet from the network server
    //  - send the packet to the device driver

    while (1) {
        if (ipc_recv(&envid, &nsipcbuf, &perm) != NSREQ_OUTPUT)
            continue;
        while (sys_net_transmit(nsipcbuf.pkt.jp_data, nsipcbuf.pkt.jp_len) < 0);
    }
}
