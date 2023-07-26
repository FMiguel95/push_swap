/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernacar <fernacar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 23:24:18 by fernacar          #+#    #+#             */
/*   Updated: 2023/07/10 22:46:05 by fernacar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	swap(t_node **stack)
{
	long	temp;

	if (*stack)
	{
		temp = (*stack)->value;
		(*stack)->value = (*stack)->next->value;
		(*stack)->next->value = temp;
	}
}

void	push(t_node **stack1, t_node **stack2)
{
	t_node	*temp;

	if (*stack1)
	{
		temp = *stack1;
		if (temp->next == temp)
			*stack1 = NULL;
		else
		{
			temp->prev->next = temp->next;
			temp->next->prev = temp->prev;
			*stack1 = temp->next;
		}
		lst_addfront(stack2, temp);
	}
}

void	rotate(t_node **stack)
{
	if (*stack)
		*stack = (*stack)->next;
}

void	reverse_rotate(t_node **stack)
{
	if (*stack)
		*stack = (*stack)->prev;
}
