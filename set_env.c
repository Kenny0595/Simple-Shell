#include "shell.h"

/**
 * get_env - returns a copy of the environment variable
 * @s:  arguments.
 * Return: array of environment variables
 */
char **get_env(info_t *s)
{
	if (!s->environ || s->env_changed)
	{
		s->environ = _to_strings(s->env);
		s->env_changed = 0;
	}

	return (s->environ);
}


/**
 * set_env - Initializes new environment variables
 * @s: arguments.
 * @var: the environment variable
 * @value: the environment value
 *  Return: 0
 */
int set_env(info_t *s, char *var, char *value)
{
	char *buffer = NULL;
	list_t *node;
	char *p;

	if (!var || !value)
		return (0);

	buffer = malloc(_strlen(var) + _strlen(value) + 2);
	if (!buffer)
		return (1);
	_strcpy(buffer, var);
	_strcat(buffer, "=");
	_strcat(buffer, value);
	node = s->env;
	while (node)
	{
		p = starts_with(node->str, var);
		if (p && *p == '=')
		{
			free(node->str);
			node->str = buffer;
			info_t->env_changed = 1;
			return (0);
		}
		node = node->next;
	}
	add_node_end(&(s->env), buffer, 0);
	free(buffer);
	s->env_changed = 1;
	return (0);
}


/**
 * un_set_env - Removes environment variables
 * @s: arguments.
 * @var: the environment variable
 * Return: 1 or 0
 */

int un_set_env(info_t *s, char *var)
{
	list_t *node = s->env;
	size_t i = 0;
	char *p;

	if (!node || !var)
		return (0);

	while (node)
	{
		p = starts_with(node->str, var);
		if (p && *p == '=')
		{
			s->env_changed = delete_node_at_index(&(s->env), i);
			i = 0;
			node = s->env;
			continue;
		}
		node = node->next;
		i++;
	}
	return (s->env_changed);
}
