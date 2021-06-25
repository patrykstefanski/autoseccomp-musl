#include <unistd.h>
#include "syscall.h"
#include "libc.h"
#include "setxid.h"

DEF_DO_SETXID(SYS_setregid)

int setregid(gid_t rgid, gid_t egid)
{
	/* return __setxid(SYS_setregid, rgid, egid, 0); */
	__SETXID(SYS_setregid, rgid, egid, 0);
}
