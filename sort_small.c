/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliannawira <juliannawira@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/14 18:06:55 by juliannawir       #+#    #+#             */
/*   Updated: 2026/07/18 09:09:53 by juliannawir      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_four_five(t_node **stack_a, t_node **stack_b)
{
	int	min;

	if (!stack_a || !*stack_a || !stack_b)
		return ;
	while (stack_size(*stack_a) > 3)
	{
		min = find_min(*stack_a);
		rotate_to_top(stack_a, min);
		pb(stack_a, stack_b);
	}
	sort_three(stack_a);
	while (*stack_b)
		pa(stack_a, stack_b);
}

static void	sort_three_values(t_node **stack, int first, int second, int third)
{
	if (first > second && first > third)
	{
		if (second > third)
		{
			sa(stack);
			rra(stack);
		}
		else
			ra(stack);
	}
	else if (second > first && second > third)
	{
		if (first < third)
		{
			sa(stack);
			ra(stack);
		}
		else
			rra(stack);
	}
	else if (first > second)
		sa(stack);
}

void	sort_three(t_node **stack)
{
	int	first;
	int	second;
	int	third;

	if (!stack || !*stack || !(*stack)->next
		|| !(*stack)->next->next)
		return ;
	first = (*stack)->value;
	second = (*stack)->next->value;
	third = (*stack)->next->next->value;
	sort_three_values(stack, first, second, third);
}

void	sort_two(t_node **stack_a)
{
	if (!stack_a || !*stack_a || !(*stack_a)->next)
		return ;
	if ((*stack_a)->value > (*stack_a)->next->value)
		sa(stack_a);
}
