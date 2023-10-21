#include "shell.h"

/**
 * _len - length of nodes in a linked list
 * @head: pointer to head node*
 * Return: number of nodes
 */

size_t _len(const list_t *head)
{
	size_t i = 0;

	while (head)
	{
		head = head->next;
		i++;
	}
	return (i);
}

/**
 * _to_strings - converts list of strings into an array
 * @head: pointer to head node
 * Return: an array of strings
 */

char **_to_strings(list_t *head)
{
	list_t *node = head;
	size_t i = list_len(head), j;
	char **strs;
	char *str;

	if (!head || !i)
		return (NULL);
	strs = malloc(sizeof(char *) * (i + 1));
	if (!strs)
		return (NULL);
	for (i = 0; node; node = node->next, i++)
	{
		str = malloc(_strlen(node->str) + 1);
		if (!str)
		{
			for (j = 0; j < i; j++)
				free(strs[j]);
			free(strs);
			return (NULL);
		}

		str = _strcpy(str, node->str);
		strs[i] = str;
	}
	strs[i] = NULL;
	return (strs);
}


/**
 * _print - prints all elements
 * @head: pointer to head node
 * Return: list size
 */

size_t _print(const list_t *head)
{
	size_t i = 0;

	while (head)
	{
		_puts(convert_number(head->num, 10, 0));
		_putchar(':');
		_putchar(' ');
		_puts(head->str ? head->str : "(nil)");
		_puts("\n");
		head = head->next;
		i++;
	}
	return (i);
}

/**
 * prefix_node - seaches for node with specific prefix
 * @head: pointer to head node
 * @prefix: string to match
 * @c: the next character after prefix to match
 * Return: pointer to matching node
 */

list_t *prefix_node(list_t *head, char *prefix, char c)
{
	char *p = NULL;

	while (head)
	{
		p = starts_with(head->str, prefix);
		if (p && ((c == -1) || (*p == c)))
			return (head);
		head = head->next;
	}
	return (NULL);
}

/**
 * get_node - retrives the index of a specific node
 * @head: pointer to head node
 * @node: pointer to the node whose index to be found
 * Return: index of node or -1
 */

ssize_t get_node(list_t *head, list_t *node)
{
	size_t i = 0;

	while (head)
	{
		if (head == node)
			return (i);
		head = head->next;
		i++;
	}
	return (-1);
}
