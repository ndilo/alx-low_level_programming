#include "main.h"
#include <stdlib.h>

/**
 * read_textfile- function that reads a text file
 * and prints it to the POSIX standard output.
 * @filename: text file
 * @letters: number of letters to be read
 * Return: the actual number of letters it could read and print
 *        filename is NULL return 0
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	char *ton;
	ssize_t file;
	ssize_t w;
	ssize_t r;

	file = open(filename, O_RDONLY);
	if (filename == NULL)
		return (0);

	if (file == -1)
		return (0);
	ton = malloc(sizeof(char) * letters);
	r = read(file, ton, letters);
	w = write(STDOUT_FILENO, ton, r);

	free(ton);
	close(file);
	return (w);
}
