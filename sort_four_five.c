/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_four_five.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwira <jwira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/14 19:33:54 by juliannawir       #+#    #+#             */
/*   Updated: 2026/07/16 14:51:16 by jwira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_position(t_node *stack, int value)
{
	int	position;

	position = 0;
	while (stack)
	{
		if (stack->value == value)
			return (position);
		stack = stack->next;
		position++;
	}
	return (-1);
}

static void	rotate_to_top(t_node **stack, int value)
{
	int	position;
	int	size;

	position = find_position(*stack, value);
	size = stack_size(*stack);
	if (position <= size / 2)
	{
		while ((*stack)->value != value)
			ra(stack);
	}
	else
	{
		while ((*stack)->value != value)
			rra(stack);
	}
}

static int	find_min(t_node *stack)
{
	int	min;

	if (!stack)
		return (0);
	min = stack->value;
	while (stack)
	{
		if (stack->value < min)
			min = stack->value;
		stack = stack->next;
	}
	return (min);
}

void	sort_four(t_node **stack_a, t_node **stack_b)
{
	int	min;

	if (stack_size(*stack_a) != 4)
		return ;
	min = find_min(*stack_a);
	rotate_to_top(stack_a, min);
	pb(stack_a, stack_b);
	sort_three(stack_a);
	pa(stack_a, stack_b);
}

void	sort_five(t_node **stack_a, t_node **stack_b)
{
	int	min;

	if (stack_size(*stack_a) != 5)
		return ;
	min = find_min(*stack_a);
	rotate_to_top(stack_a, min);
	pb(stack_a, stack_b);
	sort_four(stack_a, stack_b);
	pa(stack_a, stack_b);
}
