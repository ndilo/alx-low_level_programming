#include "main.h"
#include <stdio.h>
#include <stdlib.h>

char *create_buffer(char *fd);
void close_file(int file);

/**
 * create_buffer - Allocates 1024 bytes for buffer.
 * @fd: file to be created.
 *
 * Return: pointer to the newly-allocated buffer.
 */
char *create_buffer(char *fd)
{
	char *buff;

	buff = malloc(sizeof(char) * 1024);

	if (!buff)
	{
		dprintf(STDERR_FILENO,
			"Error: Can't write to %s\n", fd);
		exit(99);
	}

	return (buff);
}

/**
 * close_file - Closes file descriptors.
 * @file: file descriptor to be closed.
 */
void close_file(int file)
{
	int c;

	c = close(file);

	if (c == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", file);
		exit(100);
	}
}

/**
 * main - Copies the contents of a file to another file.
 * @agc: number of arguments to be used.
 * @agv: array of pointers to the arguments.
 *
 * Return: 0 on success.
 */

int main(int agc, char *agv[])
{
	int fd_from, fd_to, r, w;
	char *buff;

	if (agc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	buff = create_buffer(agv[2]);
	fd_from = open(agv[1], O_RDONLY);
	r = read(fd_from, buff, 1024);
	fd_to = open(agv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);

	do {
		if (fd_from == -1 || r == -1)
		{
			dprintf(STDERR_FILENO,
				"Error: Can't read from file %s\n", agv[1]);
			free(buff);
			exit(98);
		}

		w = write(fd_to, buff, r);
		if (fd_to == -1 || w == -1)
		{
			dprintf(STDERR_FILENO,
				"Error: Can't write to %s\n", agv[2]);
			free(buff);
			exit(99);
		}

		r = read(fd_from, buff, 1024);
		fd_to = open(agv[2], O_WRONLY | O_APPEND);

	} while (r > 0);

	free(buff);
	close_file(fd_from);
	close_file(fd_to);

	return (0);
}
