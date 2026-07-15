/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliannawira <juliannawira@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/13 16:51:42 by jwira             #+#    #+#             */
/*   Updated: 2026/07/15 22:19:01 by juliannawir      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_node
{
	int				value;
	struct s_node	*next;
}	t_node;

void	parse_input(int argc, char **argv, t_node **stack_a);
void	parse_argument(char *arg, t_node **stack_a);
int		valid_nbr_check(char *str);
int		int_range_check(char *str);
int		duplicate_check(t_node *stack);
void	error_exit(t_node *stack);
void	add_nodes(t_node **stack, int value);
long	ft_atol(const char *nptr);
void	free_split(char **numbers);
void	free_stack(t_node *stack);
void	sa(t_node **stack_a);
void	sb(t_node **stack_b);
void	ss(t_node **stack_a, t_node **stack_b);
void	pa(t_node **stack_a, t_node **stack_b);
void	pb(t_node **stack_a, t_node **stack_b);
void	ra(t_node **stack_a);
void	rb(t_node **stack_b);
void	rr(t_node **stack_a, t_node **stack_b);
void	rra(t_node **stack_a);
void	rrb(t_node **stack_b);
void	rrr(t_node **stack_a, t_node **stack_b);
int		stack_size(t_node *stack);
int		is_sorted(t_node *stack);
void	sort_two(t_node **stack_a);
void	sort_three(t_node **stack_a);
void	sort_four(t_node **stack_a, t_node **stack_b);
void	sort_five(t_node **stack_a, t_node **stack_b);

#endif