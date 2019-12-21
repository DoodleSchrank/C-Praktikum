
#ifdef POSIX
	#define _POSIX_C_SOURCE
#endif
#ifdef GNU
	#define _GNU_SOURCE
#endif
#ifdef BSD
	#define _BSD_SOURCE
#endif
#ifdef XOPEN
	#define _XOPEN_SOURCE
#endif

#include <fcntl.h>

int main(void)
{
	return 0;
}
