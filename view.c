#include "shell.h"

/**
 * exe_cmd - checks if a file contains commands
 * @s: the file to check
 * @p: path to the file
 * Return: 1 or 0
 */

int exe_cmd(info_t *s, char *p)
{
	struct stat exe;

	(void)s;
	if (!p || stat(p, &exe))
		return (0);
	if (exe.st_mode & S_IFREG)
		return (1);
	return (0);
}

/**
 * get_path - finds cmd in path
 * @s: the file
 * @p: the path string
 * @exe: the executable commad to find
 * Return: full path of cmd if found or NULL
 */

char *get_path(info_t *s, char *p, char *exe)
{
	int i = 0;
	int pos = 0;
	char *path;

	if (!p)
		return (NULL);
	if ((_strlen(exe) > 2) && starts_with(exe, "./"))
	{
		if (exe_cmd(info_t, exe))
			return (exe);
	}
	while (1)
	{
		if (!path[i] || path[i] == ':')
		{
			p = _duplicated(path, pos, i);
			if (!*p)
				_strcat(p, exe);
			else
			{
				_strcat(p, "/");
				_strcat(p, exe);												}
		if (exe_cmd(s, p))
			return (p);
		if (!path[i])
			break;
			pos = i;
		}
	i++;
	}
	return (NULL);
}

/**
 * _duplicated - duplicates strings
 * @p: the path
 * @start_ind: the start index
 * @stop_ind: the stop index
 * Return: pointer
 */

char *_duplicated(char *p, int start_ind, int stop_ind)
{
	static char buffer[1024];
	int i = 0;
	int k = 0;

	for (k = 0; i = start_ind; i < stop_ind; i++)
		if (p[i] != ':')
			buffer[k++] = p;
	buffer[k] = 0;
	return (buffer);

}
