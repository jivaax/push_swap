/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliannawira <juliannawira@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 14:46:34 by jwira             #+#    #+#             */
/*   Updated: 2026/07/18 09:45:26 by juliannawir      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_b_max_to_top(t_node **stack_b, int position)
{
	int	size;
	int	moves;

	size = stack_size(*stack_b);
	if (position <= size / 2)
	{
		while (position > 0)
		{
			rb(stack_b);
			position--;
		}
	}
	else
	{
		moves = size - position;
		while (moves > 0)
		{
			rrb(stack_b);
			moves--;
		}
	}
}

static void	push_chunk(t_node **stack_a, t_node **stack_b, int start, int end)
{
	int	pushed;

	pushed = 0;
	while (*stack_a && pushed < end - start + 1)
	{
		if ((*stack_a)->index >= start && (*stack_a)->index <= end)
		{
			pb(stack_a, stack_b);
			pushed++;
		}
		else
			ra(stack_a);
	}
}

void	push_chunks_to_b(t_node **stack_a, t_node **stack_b)
{
	int	size;
	int	chunks;
	int	chunk_size;
	int	i;

	size = stack_size(*stack_a);
	if (size <= 100)
		chunks = 5;
	else
		chunks = 10;
	chunk_size = size / chunks;
	i = 0;
	while (*stack_a && i < chunks)
	{
		push_chunk(stack_a, stack_b, i * chunk_size, (i + 1) * chunk_size - 1);
		i++;
	}
}

void	push_back_to_a(t_node **stack_a, t_node **stack_b)
{
	int	position;

	while (*stack_b)
	{
		position = find_max_position(*stack_b);
		rotate_b_max_to_top(stack_b, position);
		pa(stack_a, stack_b);
	}
}
