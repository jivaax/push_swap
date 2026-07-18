/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_chunks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliannawira <juliannawira@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/18 01:03:56 by juliannawir       #+#    #+#             */
/*   Updated: 2026/07/18 09:36:49 by juliannawir      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	assign_indices(t_node **stack_a)
{
	t_node	*current;
	t_node	*compare;
	int		idx;

	current = *stack_a;
	while (current)
	{
		idx = 0;
		compare = *stack_a;
		while (compare)
		{
			if (compare->value < current->value)
				idx++;
			compare = compare->next;
		}
		current->index = idx;
		current = current->next;
	}
}

void	sort_chunks(t_node **stack_a, t_node **stack_b)
{
	assign_indices(stack_a);
	push_chunks_to_b(stack_a, stack_b);
	push_back_to_a(stack_a, stack_b);
}
