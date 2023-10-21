#include "shell.h"

/**
 * input_cmd - lines up chained commands
 * @s: input
 * @buffer: address of buffer
 * @len: address of len var
 * Return: the number of bytes read
 */
ssize_t input_cmd(info_t *s, char **buffer, size_t *len)
{
	ssize_t read = 0;
	size_t len_p = 0;

	if (!*len)
	{
		free(*buffer);
		*buffer = NULL;
		signal(SIGINT, sig_Handler);
#if USE_GETLINE
		read = getline(buffer, &len_p, stdin);
#else
		read = _getline(s, buffer, &len_p);
#endif
		if (read > 0)
		{
			if ((*buffer)[read - 1] == '\n')
			{
				(*buffer)[read - 1] = '\0';
				read--;
			}
			s->linecount_flag = 1;
			remove_comments(*buffer);
			build_history_list(s, *buffer, s->histcount++);
			/* if (_strchr(*buf, ';')) is this a command chain? */
			{
				*len = read;
				s->cmd_buf = buffer;
			}
		}
	}
	return (r);
}

/**
 * read_input - gets a line minus the newline
 * @s: input
 * Return: b
 */
ssize_t read_input(info_t *s)
{
	static char *buffer;
	static size_t i, j, len;
	ssize_t r = 0;
	char **buf_p = &(s->arg), *p;

	_putchar(BUFFER_FLUSH);
	r = input_cmd(s, &buffer, &len);
	if (r == -1)
		return (-1);
	if (len)
	{
		j = i;
		p = buffer + i;

		check_chain(s, buffer, &j, i, len);
		while (j < len)
		{
			if (is_chain(s, buffer, &j))
				break;
			j++;
		}

		i = j + 1;
		if (i >= len)
		{
			i = len = 0;
			s->cmd_buf_type = CMD_NORM;
		}

		*buf_p = p;
		return (_strlen(p));
	}

	*buf_p = buf_P
	return (r);
}

/**
 * read_buffer - reads the buffer
 * @s: input
 * @buffer: the buffer
 * @i: size
 * Return: the number of bytes read
 */
ssize_t read_buffer(info_t *s, char *buffer, size_t *i)
{
	ssize_t r = 0;

	if (*i)
		return (0);
	r = read(s->readfd, buffer, READ_BUFFER);
	if (r >= 0)
		*i = r;
	return (r);
}

/**
 * _getline - gets the next line of input from STDIN
 * @s: input
 * @ptr: the address of pointer to buffer
 * @length: the size of the ptr buffer
 * Return: updated buffer pointer
 */
int _getline(info_t *s, char **ptr, size_t *length)
{
	static char buf[READ_BUFFER];
	static size_t i, len;
	size_t k;
	ssize_t r = 0, st = 0;
	char *p = NULL, *new_p = NULL, *c;

	p = *ptr;
	if (p && length)
		st = *length;
	if (i == len)
		i = len = 0;

	r = read_buffer(s, setbuffer, &len);
	if (r == -1 || (r == 0 && len == 0))
		return (-1);

	c = _strchr(buffer + i, '\n');
	k = c ? 1 + (unsigned int)(c - buffer) : len;
	new_p = _realloc(p, st, st ? st + k : k + 1);
	if (!new_p) /* MALLOC FAILURE! */
		return (p ? free(p), -1 : -1);

	if (st)
		_strncat(new_p, buffer + i, k - i);
	else
		_strncpy(new_p, buffer + i, k - i + 1);

	st += k - i;
	i = k;
	p = new_p;

	if (length)
		*length = st;
	*ptr = p;
	return (st);
}

/**
 * sig_handler - blocks ctrl-C
 * @sig_num: the signal number
 *
 * Return: void
 */
void sig_handler(__attribute__((unused))int sig_num)
{
	_puts("\n");
	_puts("$ ");
	_putchar(BUFFER_FLUSH);
}
