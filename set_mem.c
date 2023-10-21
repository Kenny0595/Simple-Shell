#include "shell.h"

/**
 * set_mem - fills memory with constant byte
 * @ptr: the pointer ot the memory
 * @b: the byte to fill *ptr with
 * @n: the number of bytes to be filled
 * Return: a pointer to the memory
 */

char *set_mem(char *ptr, char b, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
		ptr[i] = b;
	return (ptr);
}
