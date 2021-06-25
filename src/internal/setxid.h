#ifndef _INTERNAL_SETXID_H
#define _INTERNAL_SETXID_H

#include <unistd.h>
#include <signal.h>
#include "syscall.h"

struct ctx {
  int id, eid, sid;
  int nr, ret;
};

#define DEF_DO_SETXID(NR)                                \
static void do_setxid_##NR(void *p)                      \
{                                                        \
  struct ctx *c = p;                                     \
  if (c->ret<0) return;                                  \
  int ret = __syscall(NR, c->id, c->eid, c->sid);        \
  if (ret && !c->ret) {                                  \
    __block_all_sigs(0);                                 \
    __syscall(SYS_kill, __syscall(SYS_getpid), SIGKILL); \
  }                                                      \
  c->ret = ret;                                          \
}

#define __SETXID(NR, ID, EID, SID) do {                                    \
  struct ctx c = { .nr = NR, .id = ID, .eid = EID, .sid = SID, .ret = 1 }; \
  __synccall(do_setxid_##NR, &c);                                          \
  return __syscall_ret(c.ret);                                             \
} while (0)

#endif
