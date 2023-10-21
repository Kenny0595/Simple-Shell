#include "shell.h"

/**
 **_strncpy - copies a string
 *@dest: the string that will be copied to
 *@src: the string source
 *@n: the number of characters that must be copied
 *Return: the concatenated string
 this code is written by KENNY and MBULA 
 wishing myself sucsess
 */
char *_strncpy(char *dest, char *src, int n)
{
	int i, j;
	char *s = dest;

	i = 0;
	while (src[i] != '\0' && i < n - 1)
	{
		dest[i] = src[i];
		i++;
	}
	if (i < n)
	{
		j = i;
		while (j < n)
		{
			dest[j] = '\0';
			j++;
		}
	}
	return (s);
}

/**
 **_strncat - combines two strings
 *@dest: the 1st str
 *@src: the 2nd  str
 *@n: the maximum number of bytes to be used
 *Return: the concatenated str
 this code is written by KENNY and MBULA 
 wishing myself sucsess
 */
char *_strncat(char *dest, char *src, int n)
{
	int i, j;
	char *s = dest;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
		i++;
	while (src[j] != '\0' && j < n)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	if (j < n)
		dest[i] = '\0';
	return (s);
}

/**
 **_strchr - finds a character within a string
 *@s: the string that will be parsed
 *@c: the character to look for
 *Return: (s) a reference to the memory space s
 this code is written by KENNY and MBULA 
 wishing myself sucsess
 */
char *_strchr(char *s, char c)
{
	do {
		if (*s == c)
			return (s);
	} while (*s++ != '\0');

	return (NULL);
}
