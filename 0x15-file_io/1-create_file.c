#include "main.h"
/**
 * create_file -that creates a file.
 *
 * @text_content: text ti be inputed.
 * @filename: name of file to be created
 *
 * Return: 1 on success, -1 on failure
 */
int create_file(const char *filename, char *text_content)
{
	int file, w, len = 0;

	if (!filename)
		return (-1);

	if (text_content)
	{
		for (len = 0; text_content[len];)
			len++;
	}

	file = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0600);
	w = write(o, text_content, len);

	if (file == -1 || w == -1)
		return (-1);

	close(file);

	return (1);
}
