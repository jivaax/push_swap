/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwira <jwira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/18 00:38:26 by juliannawir       #+#    #+#             */
/*   Updated: 2026/07/18 13:10:54 by jwira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_position(t_node *stack, int value)
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

void	rotate_to_top(t_node **stack_a, int value)
{
	int	position;
	int	size;

	position = find_position(*stack_a, value);
	size = stack_size(*stack_a);
	if (position <= size / 2)
	{
		while ((*stack_a)->value != value)
			ra(stack_a);
	}
	else
	{
		while ((*stack_a)->value != value)
			rra(stack_a);
	}
}

int	find_min(t_node *stack)
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

int	find_max_position(t_node *stack_b)
{
	int	max;
	int	max_position;
	int	position;

	if (!stack_b)
		return (-1);
	max = stack_b->index;
	max_position = 0;
	position = 0;
	while (stack_b)
	{
		if (stack_b->index > max)
		{
			max = stack_b->index;
			max_position = position;
		}
		stack_b = stack_b->next;
		position++;
	}
	return (max_position);
}
