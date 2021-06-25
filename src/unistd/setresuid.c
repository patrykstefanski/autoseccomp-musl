#define _GNU_SOURCE
#include <unistd.h>
#include "syscall.h"
#include "libc.h"
#include "setxid.h"

DEF_DO_SETXID(SYS_setresuid)

int setresuid(uid_t ruid, uid_t euid, uid_t suid)
{
	/* return __setxid(SYS_setresuid, ruid, euid, suid); */
	__SETXID(SYS_setresuid, ruid, euid, suid);
}
