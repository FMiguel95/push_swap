/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernacar <fernacar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 19:59:17 by fernacar          #+#    #+#             */
/*   Updated: 2023/07/24 22:22:15 by fernacar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker_bonus.h"

int	is_sorted(t_node *stack)
{
	t_node	*temp;

	if (!stack)
		return (0);
	temp = stack;
	while (temp->next != stack)
	{
		if (temp->value > temp->next->value)
			return (0);
		temp = temp->next;
	}
	return (1);
}

int	is_sorted_rev(t_node *stack)
{
	t_node	*temp;

	if (!stack)
		return (0);
	temp = stack;
	while (temp->next != stack)
	{
		if (temp->value < temp->next->value)
			return (0);
		temp = temp->next;
	}
	return (1);
}

int	is_done(t_node *stack_a, t_node *stack_b)
{
	if (stack_b || !stack_a)
		return (0);
	return (is_sorted(stack_a));
}
