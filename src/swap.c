/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernacar <fernacar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 23:27:20 by fernacar          #+#    #+#             */
/*   Updated: 2023/07/10 21:46:24 by fernacar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	swap_a(t_node **stack_a)
{
	swap(stack_a);
	ft_printf("sa\n");
}

void	swap_b(t_node **stack_b)
{
	swap(stack_b);
	ft_printf("sb\n");
}

void	swap_swap(t_node **stack_a, t_node **stack_b)
{
	swap(stack_a);
	swap(stack_b);
	ft_printf("ss\n");
}
