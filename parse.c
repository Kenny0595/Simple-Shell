#include "shell.h"

/**
  * run_shell - costum shell for running the main loop
  *
  * Return: returns nothing
  * this code is written by KENNY and MBULA
  */

void run_shell(void)
{
	char *line;
	char **commands;

	while (1)
	{
		int idx = 0;

		if (isatty(STDIN_FILENO))
		{
			printf("my_shell$ ");
			fflush(stdout);
		}

		line = get_input();
		if (strcmp(line, "exit") == 0)
		{
			free(line);
			break;
		}
		commands = strsplit(line, ";");

		while (commands[idx] != NULL)
		{
			char **args = strsplit(commands[idx], " \t");

			execute_command(args);
			free_tokens(args);
			idx++;
		}

		free(line);
		free_tokens(commands);
	}
}

/**
  * get_input - from standard input read  user input
  *
  * Return: a pointer to a dynamically allocated string
  * this code is written by KENNY and MBULA
  *
  */

char *get_input()
{
	char *line = NULL;

	size_t bufsize = 0;

	ssize_t nread = getline(&line, &bufsize, stdin);

	if (nread == -1)
	{
		if (isatty(STDIN_FILENO))
		{
			printf("\n");
		}
		free(line);
		exit(0);
	}

	if (line[nread - 1] == '\n')
	{
		line[nread - 1] = '\0';
	}

	return (line);
}
