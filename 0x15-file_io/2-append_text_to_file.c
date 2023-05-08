#include "main.h"

/**
 * append_text_to_file - appends a text at end of file.
 * @filename: name of file
 * @text_content: string to be added at the end of file
 *
 * Return: 1 on success and -1 on failure
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int file, w, string = 0;

	if (!filename)
		return (-1);
	file = open(filename, O_WRONLY | O_APPEND);
	if (file == -1)
		return (-1);
	if (text_content)
	{
		for (string = 0; text_content[string];)
			string++;
	}
	w = write(file, text_content, string);

	if (file == -1 || w == -1)
		return (-1);

	close(file);

	if (string == -1)
		return (-1);
	return (1);
}
