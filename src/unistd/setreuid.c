#include <unistd.h>
#include "syscall.h"
#include "libc.h"
#include "setxid.h"

DEF_DO_SETXID(SYS_setreuid)

int setreuid(uid_t ruid, uid_t euid)
{
	/* return __setxid(SYS_setreuid, ruid, euid, 0); */
	__SETXID(SYS_setreuid, ruid, euid, 0);
}
