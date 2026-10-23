#ifndef __STDTCP_H__
#define __STDTCP_H__

#include <stdbool.h>
#include <stddef.h>

struct StdTcpServer;
typedef struct StdTcpServer TcpS;

TcpS* TcpServerInit(const char *ip,unsigned short port);
int TcpServerAccept(TcpS * s);
bool TcpServerSend(int clientSock,void * p,size_t size);
bool TcpServerRecv(int clientSock,void * p,size_t size);
void ClearTcpServer(TcpS * s);

struct StdTcpClient;
typedef struct StdTcpClient TcpC;
TcpC* TcpClientInit(const char *ServerIP,unsigned short ServerPort);
bool TcpClientSend(TcpC *c,void *p,size_t size);
bool TcpClientRecv(TcpC *c,void *p,size_t size);
void ClearTcpClient(TcpC * c);

#endif