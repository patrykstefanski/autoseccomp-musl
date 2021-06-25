#include <unistd.h>
#include "libc.h"
#include "syscall.h"
#include "setxid.h"

DEF_DO_SETXID(SYS_setresgid)

int setegid(gid_t egid)
{
	/* return __setxid(SYS_setresgid, -1, egid, -1); */
	__SETXID(SYS_setresgid, -1, egid, -1);
}
