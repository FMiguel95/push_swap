/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernacar <fernacar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 22:15:39 by fernacar          #+#    #+#             */
/*   Updated: 2023/07/24 21:37:56 by fernacar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker_bonus.h"

void	lst_clear(t_node **list)
{
	t_node	*temp;

	if (*list)
	{
		(*list)->prev->next = NULL;
		while (*list)
		{
			temp = (*list)->next;
			free(*list);
			*list = temp;
		}
		*list = NULL;
	}
}

t_node	*lst_newnode(long value)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	new_node->prev = NULL;
	new_node->value = value;
	new_node->next = NULL;
	return (new_node);
}

void	lst_addback(t_node **list, t_node *node)
{
	if (!(*list))
	{
		*list = node;
		node->next = node;
		node->prev = node;
	}
	else
	{
		node->prev = (*list)->prev;
		node->next = *list;
		(*list)->prev->next = node;
		(*list)->prev = node;
	}
}

void	lst_addfront(t_node **list, t_node *node)
{
	if (!(*list))
	{
		*list = node;
		node->next = node;
		node->prev = node;
	}
	else
	{
		node->prev = (*list)->prev;
		node->next = *list;
		(*list)->prev->next = node;
		(*list)->prev = node;
		*list = node;
	}
}

int	lst_size(t_node *list)
{
	int		count;
	t_node	*temp;

	count = 0;
	if (list)
	{
		count++;
		temp = list->next;
		while (temp != list)
		{
			count++;
			temp = temp->next;
		}
	}
	return (count);
}
