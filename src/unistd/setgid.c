#include <unistd.h>
#include "syscall.h"
#include "libc.h"
#include "setxid.h"

DEF_DO_SETXID(SYS_setgid)

int setgid(gid_t gid)
{
	/* return __setxid(SYS_setgid, gid, 0, 0); */
	__SETXID(SYS_setgid, gid, 0, 0);
}
