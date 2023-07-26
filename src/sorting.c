/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernacar <fernacar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 20:16:32 by fernacar          #+#    #+#             */
/*   Updated: 2023/07/14 00:31:35 by fernacar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sort2(t_node **stack_a)
{
	if ((*stack_a)->value > (*stack_a)->next->value)
		swap_a(stack_a);
}

void	sort3(t_node **stack_a)
{
	if ((*stack_a)->value < (*stack_a)->next->value
		&& (*stack_a)->value < (*stack_a)->prev->value
		&& (*stack_a)->prev->value < (*stack_a)->next->value)
	{
		swap_a(stack_a);
		rotate_a(stack_a);
	}
	else if ((*stack_a)->value > (*stack_a)->prev->value
		&& (*stack_a)->value < (*stack_a)->next->value)
		reverse_rotate_a(stack_a);
	else if ((*stack_a)->value < (*stack_a)->prev->value
		&& (*stack_a)->value > (*stack_a)->next->value) 
		swap_a(stack_a);
	else if ((*stack_a)->value > (*stack_a)->next->value
		&& (*stack_a)->value > (*stack_a)->prev->value)
	{
		if ((*stack_a)->next->value > (*stack_a)->prev->value)
		{
			swap_a(stack_a);
			reverse_rotate_a(stack_a);
		}
		else
			rotate_a(stack_a);
	}
}

static void	final_rotate(t_node **stack_a)
{
	t_node	*node0;
	t_cost	cost;

	node0 = *stack_a;
	while (node0->value != 0)
		node0 = node0->next;
	cost = distance_to_head(*stack_a, node0);
	if (cost.up <= cost.down)
	{
		while (cost.up--)
			rotate_a(stack_a);
	}
	else
	{
		while (cost.down--)
			reverse_rotate_a(stack_a);
	}
}

void	insertion(t_node **stack_a, t_node **stack_b)
{
	t_node	*next_node;
	t_node	*target_node;
	t_cost	a_cst;
	t_cost	b_cst;

	if (is_done(*stack_a, *stack_b))
		return ;
	while (lst_size(*stack_a) > 3)
		push_b(stack_a, stack_b);
	sort3(stack_a);
	while (*stack_b)
	{
		next_node = get_next_node(*stack_a, *stack_b);
		target_node = get_target_node(*stack_a, next_node->value);
		a_cst = distance_to_head(*stack_a, target_node);
		b_cst = distance_to_head(*stack_b, next_node);
		exec(stack_a, stack_b, a_cst, b_cst);
		push_a(stack_a, stack_b);
	}
	final_rotate(stack_a);
}

void	sort(t_node **stack_a, t_node **stack_b)
{
	int	size;

	size = lst_size(*stack_a);
	if (size == 2)
		sort2(stack_a);
	else
		insertion(stack_a, stack_b);
}
