/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliannawira <juliannawira@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/14 13:26:05 by jwira             #+#    #+#             */
/*   Updated: 2026/07/17 18:25:11 by juliannawir      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_split(char **numbers)
{
	int	i;

	if (!numbers)
		return ;
	i = 0;
	while (numbers[i])
	{
		free(numbers[i]);
		i++;
	}
	free(numbers);
}

void	parse_argument(char *arg, t_node **stack_a)
{
	char	**numbers;
	int		i;

	numbers = ps_split(arg, ' ');
	if (!numbers)
		error_exit(*stack_a);
	if (!numbers[0])
	{
		free_split(numbers);
		error_exit(*stack_a);
	}
	i = 0;
	while (numbers[i])
		i++;
	while (i > 0)
	{
		i--;
		if (!valid_nbr_check(numbers[i]) || !int_range_check(numbers[i]))
		{
			free_split(numbers);
			error_exit(*stack_a);
		}
		add_nodes(stack_a, ft_atoi(numbers[i]));
	}
	free_split(numbers);
}

void	parse_input(int argc, char **argv, t_node **stack_a)
{
	int	i;

	i = argc - 1;
	while (i > 0)
	{
		parse_argument(argv[i], stack_a);
		i--;
	}
	if (duplicate_check(*stack_a))
		error_exit(*stack_a);
}
