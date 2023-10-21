#include "shell.h"

/**
 * _strlen - returns a string's length
 * @s: the string whose length should be checked
 *
 * Return: integer length of string
 * this code is written by KENNY and MBULA 
 * wishing myself sucsess
 */
int _strlen(char *s)
{
	int i = 0;

	if (!s)
		return (0);

	while (*s++)
		i++;
	return (i);
}

/**
 * _strcmp - compares two strangs lexicographically.
 * @s1: the first strang
 * @s2: the second strang
 *
 * Return: If s1 s2, it is negative; if s1 > s2, it is positive; and if s1 == s2 it is zero.
 * this code is written by KENNY and MBULA 
 * wishing myself sucsess
 */
int _strcmp(char *s1, char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	if (*s1 == *s2)
		return (0);
	else
		return (*s1 < *s2 ? -1 : 1);
}

/**
 * starts_with - checks if needle starts with haystack
 * @haystack: string to search
 * @needle: the substring to find
 *
 * Return: address of next char of haystack or NULL
 * this code is written by KENNY and MBULA 
 * wishing myself sucsess
 */
char *starts_with(const char *haystack, const char *needle)
{
	while (*needle)
		if (*needle++ != *haystack++)
			return (NULL);
	return ((char *)haystack);
}

/**
 * _strcat - concatenates two strings
 * @dest: the destination buff
 * @src: the source buff
 *
 * Return: pointer to destination buff
 * this code is written by KENNY and MBULA 
 * wishing myself sucsess
 */
char *_strcat(char *dest, char *src)
{
	char *ret = dest;

	while (*dest)
		dest++;
	while (*src)
		*dest++ = *src++;
	*dest = *src;
	return (ret);
}
