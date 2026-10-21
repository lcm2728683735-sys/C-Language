#ifndef __STDUDP_H__
#define __STDUDP_H__

#include <stdbool.h>
#include <stddef.h>

struct StdUdp;
typedef struct StdUdp Udp;

Udp* UdpInit(const char *ip,unsigned short port);
bool UdpSend(Udp * u,void *p,size_t size,const char * destIP,unsigned short destPort);
bool UdpRecv(Udp*u,void*p,size_t size );
void ClearUdp(Udp * p);
#endif