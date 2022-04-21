/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jniemine <jniemine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 14:21:44 by jniemine          #+#    #+#             */
/*   Updated: 2022/03/25 14:17:44 by jniemine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static t_hNode	*ft_new_hash_node(int key, void *value)
{
	t_hNode	*new_node;

	new_node = (t_hNode *)ft_memalloc(sizeof(t_hNode));
	if (new_node == NULL)
		return (NULL);
	(*new_node).key = key;
	if (value != NULL)
		(*new_node).v = value;
	else
		(*new_node).v = (void *)ft_memalloc(sizeof(char) * (BUFF_SIZE + 1));
	if ((*new_node).v == NULL)
		return (NULL);
	(*new_node).p = 0;
	(*new_node).next = NULL;
	return (new_node);
}

static ssize_t	reader(t_ln *wrap, t_hNode **node, size_t old_size, ssize_t *n)
{	
	if (old_size == 0 || ((*node)->p == BUFF_SIZE))
	{
		*n = read((*node)->key, (*node)->v, BUFF_SIZE);
		(*node)->p = 0;
		if (*n == -1)
		{
			free ((*node)->v);
			free (*node);
			return (-1);
		}
		if (*n < BUFF_SIZE)
			((signed char *)(*node)->v)[*n] = -1;
	}
	if (old_size >= wrap->space || old_size == 0)
	{
		wrap->space = 3 * wrap->space / 2 + 1000;
		*wrap->line = ft_realloc(*wrap->line, old_size, wrap->space + 1);
	}
	if (*wrap->line == NULL)
		return (-1);
	return (*n);
}

static t_list	*search_for_key(int key, t_list **head, t_ln *wrap, ssize_t *n)
{
	t_hNode	*node;
	t_list	*lst_start;

	lst_start = *head;
	if (*wrap->line == NULL)
		return (NULL);
	while (*head != NULL && (*head)->content != NULL
		&& ((t_hNode *)(*head)->content)->key != key)
		*head = (*head)->next;
	if (*head == NULL || (*head)->content == NULL)
	{
		node = ft_new_hash_node(key, NULL);
		if (node == NULL)
			return (NULL);
		*n = reader(wrap, &node, 0, n);
		if (*n == -1)
			return (NULL);
		*head = ft_lstnew(node, sizeof(t_hNode));
		ft_lstadd(&lst_start, *head);
		free (node);
	}
	return (*head);
}

static int	write_to_line(t_ln *wrap, t_list *lst, t_list **hash, ssize_t *n)
{
	t_hNode	*node;

	wrap->i = 0;
	node = lst->content;
	while (((char *)node->v)[node->p] != -1
	&& ((char *)node->v)[node->p] != '\n')
	{
		if ((node->p == BUFF_SIZE && ((char *)node->v)[node->p] != '\n')
		|| wrap->i == wrap->space)
			if (reader(wrap, &node, wrap->i, n) == -1)
				return (-1);
		while (node->p < BUFF_SIZE && ((char *)node->v)[node->p] != '\n'
		&& ((char *)node->v)[node->p] != -1 && wrap->i < wrap->space)
			(*wrap->line)[wrap->i++] = ((char *)node->v)[node->p++];
	}
	if ((((char *)node->v)[node->p] == '\n' && ++node->p) || wrap->i > 0)
		return (1);
	free (node->v);
	ft_lstdelany(hash, lst);
	free (lst);
	return (0);
}

int	get_next_line(const int fd, char **line)
{
	int				code;
	ssize_t			n;
	static t_list	*hash[100] = {NULL};
	t_list			*lst;
	t_ln			wrap;

	code = fd % 99;
	wrap.space = BUFF_SIZE + 1;
	n = 1;
	if (line == NULL || fd < 0 || fd > 65536)
		return (-1);
	*line = (char *)ft_memalloc(sizeof(**line) * wrap.space);
	wrap.line = line;
	lst = search_for_key(fd, &(hash[code]), &wrap, &n);
	if (n == 0)
	{
		free (((t_hNode *)lst->content)->v);
		ft_lstdelany(&hash[code], lst);
		free (lst);
		return (0);
	}
	if (lst == NULL && n != 0)
		return (-1);
	return (write_to_line(&wrap, lst, &(hash[code]), &n));
}
