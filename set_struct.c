#include "shell.h"

/**
 * init_st - initializes info_t
 * @s: the address of the info_t struct
 * this code is written by KENNY
 */
void init_st(info_t *s)
{
	s->arg = NULL;
	s->argv = NULL;
	s->path = NULL;
	s->argc = 0;
}

/**
 * pop_st - populates info_t
 * @s: the address
 * @vec: the argument vector
 * this code is written by KENNY
 */
void pop_st(info_t *s, char **vec)
{
	int i = 0;

	s->fname = vec[0];
	if (s->arg)
	{
		s->argv = strtow(s->arg, " \t");
		if (!s->argv)
		{
			s->argv = malloc(sizeof(char *) * 2);
			if (s->argv)
			{
				s->argv[0] = _strdup(s->arg);
				s->argv[1] = NULL;
			}
		}
		for (i = 0; s->argv && s->argv[i]; i++)
			;
		s->argc = i;

		replace_alias(s);
		replace_vars(s);
	}
}

/**
 * free_st - frees info_t
 * @s: the address
 * @all: true if all fields are free
 * this code is written by KENNY
 */

void free_st(info_t *s, int all)
{
	free(s->argv);
	s->argv = NULL;
	s->path = NULL;
	if (all)
	{
		if (!s->cmd_buf)
			free(s->arg);
		if (s->env)
			free_st(&(s->env));
		if (s->history)
			free_st(&(s->history));
		if (s->alias)
			free_list(&(s->alias));
		free(s->environ);
			s->environ = NULL;
		free((void **)s->cmd_buf);
		if (s->readfd > 2)
			close(s->readfd);
		_putchar(BUFFER_FLUSH);
	}
}

