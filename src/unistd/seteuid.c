#include <unistd.h>
#include "syscall.h"
#include "libc.h"
#include "setxid.h"

DEF_DO_SETXID(SYS_setresuid)

int seteuid(uid_t euid)
{
	/* return __setxid(SYS_setresuid, -1, euid, -1); */
	__SETXID(SYS_setresuid, -1, euid, -1);
}
