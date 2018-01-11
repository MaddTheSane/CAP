/*
 * $Author: djh $ $Date: 91/02/15 22:58:37 $
 * $Header: abqueue.h,v 2.1 91/02/15 22:58:37 djh Rel $
 * $Revision: 2.1 $
*/

#ifndef __CAP_ABQUEUE_H__
#define __CAP_ABQUEUE_H__

/*
 * abqueue.h - header file for abqueue and abqueue users 
 *
 * AppleTalk package for UNIX (4.2 BSD).
 *
 * Copyright (c) 1986 by The Trustees of Columbia University in the
 * City of New York.
 *
 * Edit History:
 *
 *  July  1, 1986    Schilit    Created
 *
 */

#include <stdbool.h>

typedef struct qelem {
  struct qelem *q_forw;
  struct qelem *q_back;
} QElem, *QElemPtr, **QHead;

#define NILQ ((QElemPtr) 0)
#define NILQHEAD ((QHead) 0)

void q_head(QElemPtr *head,QElemPtr nhead);
void q_tail(QElemPtr *head,QElemPtr ntail);
QElemPtr dq_head(QHead head);
QElemPtr dq_tail(QElemPtr *head);
QElemPtr q_next();
QElemPtr q_prev();
QElemPtr q_mapf(QElemPtr head,bool (*filter)(QElemPtr step, void *arg),void *arg);
void dq_elem(QHead head,QElemPtr item);

#endif
