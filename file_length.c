/*
	EMS - file_length.c
	POSIX Style text file length search
	Copyright (C) 2021 Naive-C <naive.c.cell@gmail.com>
*/

#include <sys/stat.h>

size_t file_length(const int fd)
{
	struct stat st;
	fstat(fd, &st);
	size_t size = st.st_size;

	return size;
}
