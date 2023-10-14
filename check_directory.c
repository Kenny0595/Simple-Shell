#include "shell.h"

/**
  * get_current_directory -  get the current working directory
  *
  * Return: a pointer to a dynamically allocated string
  */
char *get_current_directory(void)
{
	char *cwd = (char *)malloc(PATH_MAX * sizeof(char));

	if (cwd != NULL)
	{
		if (getcwd(cwd, PATH_MAX) == NULL)
		{
			free(cwd);
			return (NULL);
		}
	}
	return (cwd);
}

/**
  * execute_cd - execute the cd built-in command
  *
  * @args: an array of strings representing the command and its arguments
  *
  * Return: returns nothing
  */
int execute_cd(char **args)
{
	char *current_dir = NULL;

	if (args[1] == NULL || strcmp(args[1], "~") == 0)
	{
		current_dir = getenv("HOME");
	}
	else if (strcmp(args[1], "-") == 0)
	{
		current_dir = getenv("OLDPWD");
	}
	else
	{
		current_dir = args[1];
	}
	if (current_dir != NULL)
	{
		char *prev_dir = get_current_directory();

		if (prev_dir != NULL)
		{
			if (chdir(current_dir) != 0)
			{
				perror("cd");
			}
			else
			{
				char cwd[PATH_MAX];

				if (getcwd(cwd, sizeof(cwd)) != NULL)
				{
					setenv("OLDPWD", prev_dir, 1);
					setenv("PWD", cwd, 1);
				}
				else
				{
					perror("getcwd");
				}
			}
			free(prev_dir);
		}
		else
		{
			perror("get_current_directory");
		}
	}
	else
	{
		perror("cd");
	}
	return (1);
}
