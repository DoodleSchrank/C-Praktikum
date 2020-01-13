#include <assert.h>
#include <fcntl.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

void read_file(int fd)
{
	int buf, cnt = 0, ret;
	FILE *outfile = fopen("output", "w");

	lseek(fd, 0, SEEK_SET);

	ret = read(fd, &buf, sizeof(int));
	while(ret == sizeof(int))
	{
		if(buf != 0)
			fprintf(outfile, "int=%d at offset=%lu\n", buf, cnt);
		cnt += sizeof(int);
		ret = read(fd, &buf, sizeof(int));
	}
	fclose(outfile);
	fflush(outfile);
}

int main(void)
{
	int fd;

	fd = open("myfile", O_RDWR | O_CREAT, 0600);
	assert(fd != -1);
	assert(pwrite(fd, &fd, sizeof(fd), 1048576) == sizeof(fd));
	read_file(fd);
	assert(pwrite(fd, &fd, sizeof(fd), 1024) == sizeof(fd));
	read_file(fd);
	assert(pwrite(fd, &fd, sizeof(fd), 524288) == sizeof(fd));
	read_file(fd);
	assert(close(fd) == 0);
	assert(unlink("myfile") == 0);

	return 0;
}
