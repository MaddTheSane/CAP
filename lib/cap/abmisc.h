
#ifndef __ABMISC_H__
#define __ABMISC_H__

#include "abasp.h"

void cpyc2pstr(char *ps,char *cs);

void cpyp2cstr(char*cs,char*ps);
void pstrncpy(byte *d, byte *s, int n);
int pstrlen(byte *s);
int pstrcmp(byte *s1, byte *s2);
int dbugarg(char *s);
int setup_bds(BDS bds[], int numbds, int segsize, char *buf, int bufsiz, atpUserDataType userdata);
int sizeof_bds(BDS bds[], int numbds);
void IniIndStr(byte *istr);
void AddIndStr(char *src,byte *istr);
void GetIndStr(char *dest,byte *istr,int idx);
int IndStrCnt(byte *istr);
int strcmpci(const u_char *s, const u_char *t);
int strncmpci(const char *s,const char *t, size_t n);

#endif
