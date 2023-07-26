/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernacar <fernacar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 01:10:29 by fernacar          #+#    #+#             */
/*   Updated: 2023/07/26 18:02:39 by fernacar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	str2int(char *str, long *output)
{
	long	value;
	long	sign;

	output = 0;
	value = 0;
	sign = 1;
	while (ft_isspace(*str))
		str++;
	if (*str == '+' || *str == '-')
		if (*str++ == '-')
			sign = -1;
	if (!ft_isdigit(*str))
		return (1);
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (1);
		value = value * 10 + *str - '0';
		str++;
		if (sign * value > INT_MAX || sign * value < INT_MIN)
			return (1);
	}
	*output = sign * value;
	return (0);
}

static void	free_split(char	**split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

static int	find_duplicate(t_node *stack)
{
	t_node	*current;
	t_node	*temp;

	current = stack;
	while (current && current->next != current)
	{
		temp = current->next;
		while (temp != stack)
		{
			if (temp->value == current->value)
				return (1);
			temp = temp->next;
		}
		current = current->next;
		if (current == stack)
			break ;
	}
	return (0);
}

static void	standardize(t_node **stack)
{
	t_node	*new_stack;
	t_node	*current;
	t_node	*temp;
	long	new_value;

	new_stack = NULL;
	current = *stack;
	while (current)
	{
		new_value = 0;
		temp = current->next;
		while (temp != current)
		{
			if (temp->value < current->value)
				new_value++;
			temp = temp->next;
		}
		lst_addback(&new_stack, lst_newnode(new_value));
		current = current->next;
		if (current == *stack)
			break ;
	}
	lst_clear(stack);
	*stack = new_stack;
}

int	convert_args(int ac, char **av, t_node **stack)
{
	long	value;
	int		i;
	int		j;
	char	**split;
	int		error;

	error = 0;
	i = 0;
	while (++i < ac)
	{
		split = ft_split(av[i], ' ');
		j = -1;
		if (!*split)
			error++;
		while (split[++j])
		{
			error |= str2int(split[j], &value);
			lst_addback(stack, lst_newnode(value));
		}
		free_split(split);
	}
	error |= find_duplicate(*stack);
	standardize(stack);
	return (error);
}
