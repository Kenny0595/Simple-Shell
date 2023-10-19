#include "shell.h"

/**
  * execute_exit - exit the shell with the provided status
  *
  * @args: a string array describing the command and its arguments
  *
  * Return: returns nothing
  * this code written by KENNY and MBALU
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
