/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwira <jwira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 00:07:50 by juliannawir       #+#    #+#             */
/*   Updated: 2026/07/13 16:52:40 by jwira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

void	add_nodes(t_node **stack, int value)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
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
	int		i;
	t_node	*stack_a;
	t_node	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc == 1)
		return (0);
	i = argc - 1;
	while (i > 0)
	{
		if (!valid_nbr_check(argv[i]))
			error_exit(stack_a);
		if (!int_range_check(argv[i]))
			error_exit(stack_a);
		add_nodes(&stack_a, ft_atoi(argv[i]));
		i--;
	}
	if (duplicate_check(stack_a))
		error_exit(stack_a);
	sa(&stack_a);
	print_stack(stack_a);
	ft_printf ("\n");
	print_stack(stack_b);
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}