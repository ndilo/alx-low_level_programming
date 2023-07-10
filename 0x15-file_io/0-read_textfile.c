#include "main.h"
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>

/**
 * read_textfile - reads a text file and prints it to the POSIX standard output
 * @filename: name of the file to read
 * @letters: numbers of letters it should read and print
 *
 * Return: Actual number of letters it could read and print
 *
 **/

ssize_t read_textfile(const char *filename, size_t letters)
{
	int file_d;
	ssize_t len_r, len_wr;
	char *buf;

	if (filename == NULL)
		return (0);
	file_d = open(filename, O_RDONLY);
	if (file_d == -1)
		return (0);
	buf = malloc(sizeof(char) * letters + 1);
	if (buf == NULL)
	{
		close(file_d);
		return (0);
	}
	len_r = read(file_d, buf, letters);
	close(file_d);
	if (len_r == -1)
	{
		free(buf);
		return (0);
	}
	len_wr = write(STDOUT_FILENO, buf, len_r);
	free(buf);
	if (len_r != len_wr)
		return (0);
	return (len_wr);
}
