#include "shell.h"

/**
  * execute_command - run a command in a child process
  *
  * @args: the command and its arguments are represented as an array of strings.
  *
  * Return: nothing
  * this code is written by KENNY and MBULA
*/
void execute_command(char **args)
{
pid_t pid;
int status;

if (strcmp(args[0], "cd") == 0)
{
execute_cd(args);
return;
}
pid = fork();
if (pid == 0)
{
if (execvp(args[0], args) == -1)
{
perror("execute_command");
exit(EXIT_FAILURE);
}
} else if (pid < 0)
{
perror("execute_command");
exit(EXIT_FAILURE);
} else
{
do {
pid_t wpid = waitpid(pid, &status, WUNTRACED);

if (wpid == -1)
{
perror("waitpid");
}
} while (!WIFEXITED(status) && !WIFSIGNALED(status));
}
}

/**
  * execute_env -  Print the current working environment
  * this code is written by KENNY and MBULA
  *
  * Return: nothing
*/

void execute_env(void)
{
char **env = environ;

while (*env)
{
printf("%s\n", *env);
env++;
}
}

/**
  * safe_malloc - allocate memory safely with error handling
  *
  * @size_t: the amount of memory to be allocated
  *
  * Return: a pointer to the allocated memory
  * this code is written by KENNY and MBULA
*/

void *safe_malloc(size_t size)
{
void *ptr = malloc(size);

if (!ptr)
{
perror("Allocation error");
exit(EXIT_FAILURE);
}
return (ptr);
}

/**
  * safe_strdup - safely duplicate a string with error handling
  *
  * @str: The string to be duplicated
  *
  * Return: a pointer to the duplicated string
  * this code is written by KENNY and MBULA
*/

char *safe_strdup(const char *str)
{
char *copy = safe_malloc(strlen(str) + 1);

strcpy(copy, str);
return (copy);
}
