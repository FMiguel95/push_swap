/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernacar <fernacar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 21:28:05 by fernacar          #+#    #+#             */
/*   Updated: 2023/07/25 22:33:55 by fernacar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker_bonus.h"

static int	exec_instruction1(t_node **stack_a, t_node **stack_b, char *inst)
{
	if (!ft_strcmp(inst, "sa\n"))
		swap(stack_a);
	else if (!ft_strcmp(inst, "sb\n"))
		swap(stack_b);
	else if (!ft_strcmp(inst, "ss\n"))
	{
		swap(stack_a);
		swap(stack_b);
	}
	else if (!ft_strcmp(inst, "pa\n"))
		push(stack_b, stack_a);
	else if (!ft_strcmp(inst, "pb\n"))
		push(stack_a, stack_b);
	else
		return (0);
	return (1);
}

static int	exec_instruction2(t_node **stack_a, t_node **stack_b, char *inst)
{
	if (!ft_strcmp(inst, "ra\n"))
		rotate(stack_a);
	else if (!ft_strcmp(inst, "rb\n"))
		rotate(stack_b);
	else if (!ft_strcmp(inst, "rr\n"))
	{
		rotate(stack_a);
		rotate(stack_b);
	}
	else if (!ft_strcmp(inst, "rra\n"))
		reverse_rotate(stack_a);
	else if (!ft_strcmp(inst, "rrb\n"))
		reverse_rotate(stack_b);
	else if (!ft_strcmp(inst, "rrr\n"))
	{
		reverse_rotate(stack_a);
		reverse_rotate(stack_b);
	}
	else
		return (0);
	return (1);
}

static void	read_instructions(t_node **stack_a, t_node **stack_b, int *error)
{
	char	*instruction;

	while (!*error)
	{
		instruction = get_next_line(STDIN_FILENO);
		while (instruction && instruction[ft_strlen(instruction) - 1] != '\n')
			ft_strlcat(instruction, get_next_line(STDIN_FILENO), 5);
		if (!instruction)
			break ;
		if (!exec_instruction1(stack_a, stack_b, instruction)
			&& !exec_instruction2(stack_a, stack_b, instruction))
		{
			*error = 1;
			get_next_line(-1);
		}
		free(instruction);
	}
}

int	main(int ac, char **av)
{
	t_node	*stack_a;
	t_node	*stack_b;
	int		error;

	stack_a = NULL;
	stack_b = NULL;
	error = convert_args(ac, av, &stack_a);
	if (lst_size(stack_a) > 0)
		read_instructions(&stack_a, &stack_b, &error);
	if (error)
		write(STDERR_FILENO, "Error\n", 6);
	else if (is_done(stack_a, stack_b))
		ft_printf("OK\n");
	else if (stack_a || stack_b)
		ft_printf("KO\n");
	lst_clear(&stack_a);
	lst_clear(&stack_b);
	return (0);
}
