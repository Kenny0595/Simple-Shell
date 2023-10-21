#include "shell.h"

/**
 **_memset - fills memory with a single byte
 *@s: the memory area's pointer
 *@b: the byte to fill *s with
 *@n: the number of bytes that must be filled
 *Return: (s) a pointer to the memory area s
 *this code is written by KENNY and MBULA 
 wishing myself sucsess
 */
char *_memset(char *s, char b, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
		s[i] = b;
	return (s);
}

/**
 * ffree - frees a string of strings
 * @pp: string of strings
 * this code is written by KENNY and MBULA 
 * wishing myself sucsess
 */
void ffree(char **pp)
{
	char **a = pp;

	if (!pp)
		return;
	while (*pp)
		free(*pp++);
	free(a);
}

/**
 * _realloc - reallocates a block of memory
 * @ptr: a pointer to the previously malloc'd block
 * @old_size: byte size of previous 
 * @new_size: byte size of new block
 *
 * Return: nameen is a pointer to the old block
 * this code is written by KENNY and MBULA 
 * wishing myself sucsess
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *p;

	if (!ptr)
		return (malloc(new_size));
	if (!new_size)
		return (free(ptr), NULL);
	if (new_size == old_size)
		return (ptr);

	p = malloc(new_size);
	if (!p)
		return (NULL);

	old_size = old_size < new_size ? old_size : new_size;
	while (old_size--)
		p[old_size] = ((char *)ptr)[old_size];
	free(ptr);
	return (p);
}
