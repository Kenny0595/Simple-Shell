#include "shell.h"

/**
  * strsplit - split a string into an array of tokens based on a delimiter
  *
  * @str: string to be split
  *
  * @delim: the delimiter used to split the string
  *
  * Return: an array of strings (tokens) obtained by splitting
  * - the input string based on the delimiter
  */

char **strsplit(const char *str, const char *delim)
{
	char *copy = safe_strdup(str);
	char *token;
	int bufsize = 64;
	int position = 0;
	char **tokens = safe_malloc(bufsize * sizeof(char *));

	token = strtok(copy, delim);
	while (token != NULL)
	{
		tokens[position] = safe_strdup(token);
		position++;
		if (position >= bufsize)
		{
			bufsize += 64;
			tokens = realloc(tokens, bufsize * sizeof(char *));
			if (!tokens)
			{
				perror("Allocation error");
				exit(EXIT_FAILURE);
			}
		}
		token = strtok(NULL, delim);
	}
	tokens[position] = NULL;
	free(copy);
	return (tokens);
}

/**
  * free_tokens - free memory allocated for an array of tokens
  *
  * @tokens: The array of tokens to be freed
  *
  * Return: return nothing
  */

void free_tokens(char **tokens)
{
	int i = 0;

	while (tokens[i] != NULL)
	{
		free(tokens[i]);
		i++;
	}
	free(tokens);
}

/**
  * count_tokens - Count the number of tokens in an array of strings
  *
  * @tokens: The array of tokens for which to count the elements
  *
  * Return: the number of tokens in the array
  */

int count_tokens(char **tokens)
{
	int count = 0;

	while (tokens[count] != NULL)
	{
		count++;
	}
	return (count);
}

/**
  * execute_setenv - execute the built-in setenv command
  *
  * @args: An array of arguments for the setenv command
  *
  * Return: return nothing
  */

void execute_setenv(char **args)
{
	if (args[1] == NULL || args[2] == NULL)
	{
		fprintf(stderr, "Usage: setenv VARNAME VALUE\n");
		return;
	}
	if (setenv(args[1], args[2], 1) == -1)
	{
		perror("setenv");
	}
}

/**
  * execute_unsetenv - Execute the built-in unsetenv command
  *
  * @args: An array of arguments for the unsetenv command
  *
  * Return: return nothing
  */

void execute_unsetenv(char **args)
{
	if (args[1] == NULL)
	{
		fprintf(stderr, "Usage: unsetenv VARNAME\n");
		return;
	}
	if (unsetenv(args[1]) == -1)
	{
		perror("unsetenv");
	}
}
