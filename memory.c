#include "shell.h"

/**
 * bfree - NULLs the address and frees a pointer
 * @ptr: address of the free pointer
 *
 * Return: If freed, 1; else, 0.
 * this code is written by KENNY and MBULA 
 * wishing myself sucsess
 */
int bfree(void **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
		return (1);
	}
	return (0);
}
