#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "main.h"

unsigned long int _strlen(char *str);

/**
 * create_file - creates a new file
 * @filename: Name of the text file to be created
 * @text_content: Text that should be placed in the new file
 *
 * Return: 1 if success or -1 if failure.
 */

int create_file(const char *filename, char *text_content)
{
	int file_d, bytes_written;

	if (!filename)
		return (-1);

	file_d = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0600);
	if (file_d == -1)
		return (-1);

	if (text_content)
	{
		bytes_written = write(file_d, text_content, _strlen(text_content));
		if (bytes_written == -1)
		{
			close(file_d);
			return (-1);
		}

		if ((size_t)bytes_written != _strlen(text_content))
		{
			close(file_d);
			return (-1);
		}
	}

	close(file_d);
	return (1);
}

/**
 * _strlen - Finds the length of a non-empty array.
 * @str: Array to be counted
 *
 * Return: Number of characters.
 */

unsigned long int _strlen(char *str)
{
	unsigned long int length;

	for (length = 0; str[length]; length++)
	{};

	return (length);
}
