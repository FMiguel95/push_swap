/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernacar <fernacar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 21:17:15 by fernacar          #+#    #+#             */
/*   Updated: 2023/07/24 23:22:57 by fernacar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

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

void	swap_a(t_node **stack_a);
void	swap_b(t_node **stack_b);
void	swap_swap(t_node **stack_a, t_node **stack_b);
void	push_a(t_node **stack_a, t_node **stack_b);
void	push_b(t_node **stack_a, t_node **stack_b);
void	rotate_a(t_node **stack_a);
void	rotate_b(t_node **stack_b);
void	rotate_rotate(t_node **stack_a, t_node **stack_b);
void	reverse_rotate_a(t_node **stack_a);
void	reverse_rotate_b(t_node **stack_b);
void	reverse_rotate_rotate(t_node **stack_a, t_node **stack_b);

int		is_sorted(t_node *stack);
int		is_sorted_rev(t_node *stack);
int		is_done(t_node *stack_a, t_node *stack_b);

void	rotate_a_n_times(t_node **stack_a, int n);
void	rotate_b_n_times(t_node **stack_b, int n);
void	reverse_rotate_a_n_times(t_node **stack_a, int n);
void	reverse_rotate_b_n_times(t_node **stack_b, int n);
void	rotate_rotate_n_times(t_node **stack_a, t_node **stack_b, int n);
void	reverse_rotate_rotate_n_times(t_node **stck_a, t_node **stck_b, int n);

t_node	*get_target_node(t_node *stack_a, long value);
t_cost	distance_to_head(t_node *stack, t_node *node);
int		get_final_cost(t_cost a_cst, t_cost b_cst);
t_node	*get_next_node(t_node *stack_a, t_node *stack_b);
void	exec(t_node **stack_a, t_node **stack_b, t_cost a_cst, t_cost b_cst);

void	sort(t_node **stack_a, t_node **stack_b);

#endif