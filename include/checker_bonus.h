/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernacar <fernacar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 21:17:15 by fernacar          #+#    #+#             */
/*   Updated: 2023/07/24 23:22:26 by fernacar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include "../libft/libft.h"
# include <limits.h>

# include <stdio.h>

typedef struct s_node
{
	struct s_node	*prev;
	long			value;
	struct s_node	*next;
}				t_node;

typedef struct s_cost
{
	int	up;
	int	down;
}				t_cost;

t_node	*lst_newnode(long value);
void	lst_addfront(t_node **list, t_node *node);
void	lst_addback(t_node **list, t_node *node);
void	lst_clear(t_node **list);
int		lst_size(t_node *list);

int		convert_args(int ac, char **av, t_node **stack);

void	swap(t_node **stack);
void	push(t_node **stack1, t_node **stack2);
void	rotate(t_node **stack);
void	reverse_rotate(t_node **stack);

int		is_sorted(t_node *stack);
int		is_sorted_rev(t_node *stack);
int		is_done(t_node *stack_a, t_node *stack_b);

#endif