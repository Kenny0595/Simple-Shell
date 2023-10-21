#include "shell.h"

/**
 * _strcpy - copies a str
 * @dest: the destination
 * @src: the source
 *
 * Return: pointer to destination
 * this code is written by KENNY and MBULA 
 * wishing myself sucsess
 */
char *_strcpy(char *dest, char *src)
{
	int i = 0;

	if (dest == src || src == 0)
		return (dest);
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}

/**
 * _strdup - duplicates a str
 * @str: the str to duplicate
 *
 * Return: pointer to the duplicated str
 * this code is written by KENNY and MBULA 
 * wishing myself sucsess
 */
char *_strdup(const char *str)
{
	int length = 0;
	char *ret;

	if (str == NULL)
		return (NULL);
	while (*str++)
		length++;
	ret = malloc(sizeof(char) * (length + 1));
	if (!ret)
		return (NULL);
	for (length++; length--;)
		ret[length] = *--str;
	return (ret);
}

/**
 *_puts - prints an input str
 *@str: the str to be printed
 *
 * Return: Nothing
 * this code is written by KENNY and MBULA 
 * wishing myself sucsess
 */
void _puts(char *str)
{
	int i = 0;

	if (!str)
		return;
	while (str[i] != '\0')
	{
		_putchar(str[i]);
		i++;
	}
}

/**
 * _putchar - stdout receives the character c
 * @c: The character to print
 *
 * Return: On success, 1 is returned; on failure, -1 is returned, and errno is set appropriately.
 * this code is written by KENNY and MBULA 
 * wishing myself sucsess
 */
int _putchar(char c)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(1, buf, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buf[i++] = c;
	return (1);
}
