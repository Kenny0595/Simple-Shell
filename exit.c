#include "shell.h"

/**
  * execute_exit - exit the shell with the specified status
  *
  * @args: the command and its arguments are represented as an array of strings.
  *
  * Return: returns nothing
  * this code is written by KENNY AND MBULA
*/

void execute_exit(char **args)
{
int status = 0;

if (args[1] != NULL)
{
status = atoi(args[1]);
}

free_tokens(args);
exit(status);
}
