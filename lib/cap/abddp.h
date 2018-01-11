
#include <netat/appletalk.h>

OSErr DDPWriteIOV(abRecPtr abr,struct iovec *iov,int iovl);
OSErr DDPCloseSocket(int skt);
private OSErr iDDPOpenSocketIOV(int *skt, struct iovec *iov, int iovlen);
OSErr DDPOpenSocket(int *skt,ProcPtr sktlis);
