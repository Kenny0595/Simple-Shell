#include "shell.h"

/**
  * handle_logical_operators - handle multiple commands
  *
  * @line: a string representing the user input containing multiple commands
  *
  * Return: nothing
  */

void handle_logical_operators(char *line)
{
	char **commands = strsplit(line, ";");
	int idx = 0, next_idx;

	while (commands[idx] != NULL)
	{
		char **args = strsplit(commands[idx], " \t");

		if (strcmp(args[0], "cd") == 0)
			execute_cd(args);
		else
		{
			int status;
			pid_t pid = fork();

			if (pid == 0)
			{
				if (execvp(args[0], args) == -1)
				{
					perror("execute_command");
					exit(EXIT_FAILURE);
				}
			}
			else if (pid < 0)
			{
				perror("fork");
				exit(EXIT_FAILURE);
			}
			else
			{
				waitpid(pid, &status, 0);
				next_idx = idx + 1;
				if (commands[next_idx] != NULL)
				{
					char *logical_op = commands[next_idx];
					if (WIFEXITED(status))
					{
						if (WEXITSTATUS(status) == 0 && strcmp(logical_op, "&&") == 0)
							idx++;
						else if (WEXITSTATUS(status) != 0 && strcmp(logical_op, "||") == 0)
							idx++;
					}
				}
			}
		}
		free_tokens(args);
		idx++;
	}
	free_tokens(commands);
}
