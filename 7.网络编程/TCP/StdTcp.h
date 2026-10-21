#ifndef __STDTCP_H__
#define __STDTCP_H__

#include <stdbool.h>
#include <stddef.h>

struct StdTcp;
typedef struct StdTcp TcpS;

TcpS* TcpServerInit(const char *ip,unsigned short port);
int TcpServerAccept(TcpS * s);
bool TcpServerSend(TcpS * s,void * p,size_t size);

#endif