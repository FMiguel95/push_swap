/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernacar <fernacar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 00:13:48 by fernacar          #+#    #+#             */
/*   Updated: 2023/07/14 00:42:53 by fernacar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	reverse_rotate_rotate_n_times(t_node **stack_a, t_node **stack_b, int n)
{
	while (n-- > 0)
		reverse_rotate_rotate(stack_a, stack_b);
}

t_node	*get_target_node(t_node *stack_a, long value)
{
	t_node	*target_node;
	t_node	*temp;

	target_node = NULL;
	temp = stack_a;
	while (!target_node)
	{
		while (1)
		{
			if (temp->value > value && ((target_node
						&& temp->value < target_node->value) || !target_node))
				target_node = temp;
			temp = temp->next;
			if (temp == stack_a)
				break ;
		}
		value = -1;
	}
	return (target_node);
}

t_cost	distance_to_head(t_node *stack, t_node *node)
{
	t_cost	cost;
	int		distance;
	t_node	*temp;

	distance = 0;
	temp = node;
	while (temp != stack)
	{
		temp = temp->prev;
		distance++;
	}
	cost.up = distance;
	distance = 0;
	temp = node;
	while (temp != stack)
	{
		temp = temp->next;
		distance++;
	}
	cost.down = distance;
	return (cost);
}

int	get_final_cost(t_cost a_cst, t_cost b_cst)
{
	if (a_cst.up + b_cst.down <= a_cst.down
		&& a_cst.up + b_cst.down <= b_cst.up)
		return (a_cst.up + b_cst.down);
	if (b_cst.up + a_cst.down <= b_cst.down
		&& b_cst.up + a_cst.down <= a_cst.up)
		return (b_cst.up + a_cst.down);
	if (a_cst.up <= a_cst.down && a_cst.up >= b_cst.up)
		return (a_cst.up);
	if (a_cst.down <= a_cst.up && a_cst.down >= b_cst.down)
		return (a_cst.down);
	if (b_cst.up <= b_cst.down && b_cst.up >= a_cst.up)
		return (b_cst.up);
	if (b_cst.down <= b_cst.up && b_cst.down >= a_cst.down)
		return (b_cst.down);
	if (a_cst.up >= b_cst.up && a_cst.up <= a_cst.up + b_cst.down)
		return (a_cst.up);
	if (b_cst.up >= a_cst.up && b_cst.up <= b_cst.up + a_cst.down)
		return (b_cst.up);
	if (a_cst.down >= b_cst.down && a_cst.down <= a_cst.down + b_cst.up)
		return (a_cst.down);
	if (b_cst.down >= a_cst.down && b_cst.down <= b_cst.down + a_cst.up)
		return (b_cst.down);
	if (a_cst.up <= a_cst.down && b_cst.down <= a_cst.up)
		return (a_cst.up + b_cst.down);
	return (b_cst.up + a_cst.down);
}

t_node	*get_next_node(t_node *stack_a, t_node *stack_b)
{
	t_node	*next_node;
	t_node	*temp;
	int		lowest_cost;

	lowest_cost = INT_MAX;
	temp = stack_b;
	while (1)
	{
		if (lowest_cost > get_final_cost(
				distance_to_head(stack_a,
					get_target_node(stack_a, temp->value)),
				distance_to_head(stack_b, temp)))
		{
			next_node = temp;
			lowest_cost = get_final_cost(
					distance_to_head(stack_a,
						get_target_node(stack_a, temp->value)),
					distance_to_head(stack_b, temp));
		}
		temp = temp->next;
		if (temp == stack_b)
			break ;
	}
	return (next_node);
}
