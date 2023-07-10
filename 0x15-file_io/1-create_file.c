#include "main.h"
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

/**
 * _strlen - finds the length of a string
 * @str: pointer to the string
 *
 * Return: ;ength of the string
 *
 **/

size_t _strlen(char *str)
{
	size_t j;

	for (j = 0; str[j]; j++)
		;
	return (j);
}

/**
 * create_file - creates a file
 * @filename: name of the file to create
 * @text_content: NULL terminated string to write to the file
 *
 * Return: 1 on success, -1 on fail
 *
 **/

int create_file(const char *filename, char *text_content)
{
	int file_d;
	ssize_t length = 0;

	if (filename == NULL)
		return (-1);

	file_d = open(filename, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
	if (file_d == -1)
		return (-1);
	if (text_content != NULL)
		length = write(file_d, text_content, _strlen(text_content));
	close(file_d);
	if (length == -1)
		return (-1);
	return (1);

