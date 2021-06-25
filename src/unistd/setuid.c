#include <unistd.h>
#include "syscall.h"
#include "libc.h"
#include "setxid.h"

DEF_DO_SETXID(SYS_setuid)

int setuid(uid_t uid)
{
	/* return __setxid(SYS_setuid, uid, 0, 0); */
	__SETXID(SYS_setuid, uid, 0, 0);
}
