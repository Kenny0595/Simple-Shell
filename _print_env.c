#include "shell.h"

/**
  * _print_env - prints the environment  , mbula
  *
  * Return: nothing to be returned   , kenny
*/
void _print_env(void)
{
int i = 0, j = 0;

while (environ[i])
{
j = 0;
while (environ[i][j])
{
_putchar(environ[i][j]);
j++;
}

if (j != 0)
_putchar('\n');
i++;
}
}