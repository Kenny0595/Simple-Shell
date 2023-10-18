#include "shell.h"

/**
 * _putchar - ...
 * @c: ...
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
*/
int _putchar(char c)
{
return (write(1, &c, 1));
}


/**
  * _puts - prints a string
  * @str: the string to be printed
  *
  * Return: void
*/
void _puts(char *str)
{
while (*str)
{
_putchar(*str);
str++;
}

_putchar('\n');
}

/**
  * _strncmp - ...
  * @s1: ...
  * @s2: ...
  * @len: ...
  *
  * Return: int value
*/
int _strncmp(const char *s1, const char *s2, size_t len)
{
unsigned int pos = 0;
int diff = 0;

while (pos < len)
{
if (s1[pos] == s2[pos])
{
pos++;
continue;
}
else
{
diff = s1[pos] - s2[pos];
break;
}

pos++;
}

return (diff);
}

/**
  * _realloc - ...
  * @ptr: ...
  * @old_size: ...
  * @new_size: ...
  *
  * Return: A new pointer to the memory block allocated with the new size
*/
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
char *nptr;
unsigned int i;

if (new_size == old_size)
return (ptr);

if (ptr == NULL)
{
nptr = malloc(new_size);

if (nptr == NULL)
return (NULL);

return (nptr);
}
else
{
if (new_size == 0)
{
free(ptr);
return (NULL);
}
}

nptr = malloc(new_size);

if (nptr == NULL)
return (NULL);

for (i = 0; i < old_size && i < new_size; i++)
{
nptr[i] = ((char *) ptr)[i];
}

free(ptr);
return (nptr);
}