/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernacar <fernacar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 00:13:48 by fernacar          #+#    #+#             */
/*   Updated: 2023/07/14 00:22:58 by fernacar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	rotate_a_n_times(t_node **stack_a, int n)
{
	while (n-- > 0)
		rotate_a(stack_a);
}

void	rotate_b_n_times(t_node **stack_b, int n)
{
	while (n-- > 0)
		rotate_b(stack_b);
}

void	reverse_rotate_a_n_times(t_node **stack_a, int n)
{
	while (n-- > 0)
		reverse_rotate_a(stack_a);
}

void	reverse_rotate_b_n_times(t_node **stack_b, int n)
{
	while (n-- > 0)
		reverse_rotate_b(stack_b);
}

void	rotate_rotate_n_times(t_node **stack_a, t_node **stack_b, int n)
{
	while (n-- > 0)
		rotate_rotate(stack_a, stack_b);
}
