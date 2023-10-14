#include "shell.h"

/**
  * execute_exit - exit the shell with the specified status
  *
  * @args: an array of strings representing the command and its arguments
  *
  * Return: returns nothing
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
