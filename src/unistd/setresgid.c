#define _GNU_SOURCE
#include <unistd.h>
#include "syscall.h"
#include "libc.h"
#include "setxid.h"

DEF_DO_SETXID(SYS_setresgid)

int setresgid(gid_t rgid, gid_t egid, gid_t sgid)
{
	/* return __setxid(SYS_setresgid, rgid, egid, sgid); */
	__SETXID(SYS_setresgid, rgid, egid, sgid);
}
