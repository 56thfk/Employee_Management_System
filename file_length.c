#include <sys/stat.h>

size_t file_length(const int fd)
{
	struct stat st;
	fstat(fd, &st);
	size_t size = st.st_size;

	return size;
}
