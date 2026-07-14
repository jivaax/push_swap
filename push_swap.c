/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwira <jwira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 00:07:50 by juliannawir       #+#    #+#             */
/*   Updated: 2026/07/14 13:35:47 by jwira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

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

	stack_a = NULL;
	stack_b = NULL;
	if (argc == 1)
		return (0);
	parse_input(argc, argv, &stack_a);
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}
