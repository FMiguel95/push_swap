/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernacar <fernacar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 21:14:58 by fernacar          #+#    #+#             */
/*   Updated: 2023/07/24 21:25:26 by fernacar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int ac, char **av)
{
	t_node	*stack_a;
	t_node	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (convert_args(ac, av, &stack_a))
		write(STDERR_FILENO, "Error\n", 6);
	else if (stack_a)
		sort(&stack_a, &stack_b);
	lst_clear(&stack_a);
	lst_clear(&stack_b);
	return (0);
}
