/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliannawira <juliannawira@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 00:07:50 by juliannawir       #+#    #+#             */
/*   Updated: 2026/07/14 19:15:09 by juliannawir      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_nodes(t_node **stack, int value)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	if (!new_node)
		error_exit(*stack);
	new_node->value = value;
	new_node->next = *stack;
	*stack = new_node;
}

void	print_stack(t_node *stack)
{
	while (stack != NULL)
	{
		ft_printf("%d\n", stack->value);
		stack = stack->next;
	}
}

void	free_stack(t_node *stack)
{
	t_node	*temp;

	while (stack != NULL)
	{
		temp = stack;
		stack = stack->next;
		free(temp);
	}
}

int	main(int argc, char **argv)
{
	t_node	*stack_a;
	t_node	*stack_b;
	int		size;

	stack_a = NULL;
	stack_b = NULL;
	if (argc == 1)
		return (0);
	parse_input(argc, argv, &stack_a);
	size = stack_size(stack_a);
	if (is_sorted(stack_a))
		;
	else if (size == 2)
		sort_two(&stack_a);
	else if (size == 3)
		sort_three(&stack_a);
	//else if (size <= 5)
	//	sort_five(&stack_a, &stack_b);
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}
