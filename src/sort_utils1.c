/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernacar <fernacar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 00:13:48 by fernacar          #+#    #+#             */
/*   Updated: 2023/07/14 00:19:00 by fernacar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	exec1(t_node **stack_a, t_node **stack_b, t_cost a_cst, t_cost b_cst)
{
	if (a_cst.up + b_cst.down <= a_cst.down
		&& a_cst.up + b_cst.down <= b_cst.up)
	{
		rotate_a_n_times(stack_a, a_cst.up);
		reverse_rotate_b_n_times(stack_b, b_cst.down);
		return (1);
	}
	else if (b_cst.up + a_cst.down <= b_cst.down
		&& b_cst.up + a_cst.down <= a_cst.up)
	{
		rotate_b_n_times(stack_b, b_cst.up);
		reverse_rotate_a_n_times(stack_a, a_cst.down);
		return (1);
	}
	else if (a_cst.up <= a_cst.down && a_cst.up >= b_cst.up)
	{
		rotate_rotate_n_times(stack_a, stack_b, b_cst.up);
		rotate_a_n_times(stack_a, a_cst.up - b_cst.up);
		return (1);
	}
	return (0);
}

int	exec2(t_node **stack_a, t_node **stack_b, t_cost a_cst, t_cost b_cst)
{
	if (a_cst.down <= a_cst.up && a_cst.down >= b_cst.down)
	{
		reverse_rotate_rotate_n_times(stack_a, stack_b, b_cst.down);
		reverse_rotate_a_n_times(stack_a, a_cst.down - b_cst.down);
		return (1);
	}
	else if (b_cst.up <= b_cst.down && b_cst.up >= a_cst.up)
	{
		rotate_rotate_n_times(stack_a, stack_b, a_cst.up);
		rotate_b_n_times(stack_b, b_cst.up - a_cst.up);
		return (1);
	}
	else if (b_cst.down <= b_cst.up && b_cst.down >= a_cst.down)
	{
		reverse_rotate_rotate_n_times(stack_a, stack_b, a_cst.down);
		reverse_rotate_b_n_times(stack_b, b_cst.down - a_cst.down);
		return (1);
	}
	return (0);
}

int	exec3(t_node **stack_a, t_node **stack_b, t_cost a_cst, t_cost b_cst)
{
	if (a_cst.up >= b_cst.up && a_cst.up <= a_cst.up + b_cst.down)
	{
		rotate_rotate_n_times(stack_a, stack_b, b_cst.up);
		rotate_a_n_times(stack_a, a_cst.up - b_cst.up);
		return (1);
	}
	else if (b_cst.up >= a_cst.up && b_cst.up <= b_cst.up + a_cst.down)
	{
		rotate_rotate_n_times(stack_a, stack_b, a_cst.up);
		rotate_b_n_times(stack_b, b_cst.up - a_cst.up);
		return (1);
	}
	else if (a_cst.down >= b_cst.down && a_cst.down <= a_cst.down + b_cst.up)
	{
		reverse_rotate_rotate_n_times(stack_a, stack_b, b_cst.down);
		reverse_rotate_a_n_times(stack_a, a_cst.down - b_cst.down);
		return (1);
	}
	return (0);
}

int	exec4(t_node **stack_a, t_node **stack_b, t_cost a_cst, t_cost b_cst)
{
	if (b_cst.down >= a_cst.down && b_cst.down <= b_cst.down + a_cst.up)
	{
		reverse_rotate_rotate_n_times(stack_a, stack_b, a_cst.down);
		reverse_rotate_b_n_times(stack_b, b_cst.down - a_cst.down);
		return (1);
	}
	else if (a_cst.up <= a_cst.down && b_cst.down <= a_cst.up)
	{
		rotate_a_n_times(stack_a, a_cst.up);
		reverse_rotate_b_n_times(stack_b, b_cst.down);
		return (1);
	}
	else if (a_cst.down <= a_cst.up && b_cst.up <= a_cst.down)
	{
		rotate_b_n_times(stack_b, b_cst.up);
		reverse_rotate_a_n_times(stack_a, a_cst.down);
		return (1);
	}
	return (0);
}

void	exec(t_node **stack_a, t_node **stack_b, t_cost a_cst, t_cost b_cst)
{
	if (exec1(stack_a, stack_b, a_cst, b_cst))
		return ;
	if (exec2(stack_a, stack_b, a_cst, b_cst))
		return ;
	if (exec3(stack_a, stack_b, a_cst, b_cst))
		return ;
	exec4(stack_a, stack_b, a_cst, b_cst);
}
