/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_split.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwira <jwira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/18 00:52:19 by juliannawir       #+#    #+#             */
/*   Updated: 2026/07/18 14:01:50 by jwira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ps_count(const char *s, char c)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
			count++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (count);
}

static char	**ps_free(char **arr, int count)
{
	while (count > 0)
	{
		count--;
		free(arr[count]);
	}
	free(arr);
	return (NULL);
}

static int	ps_add_word(char **arr, const char *s, int index, char c)
{
	int	len;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	arr[index] = malloc(sizeof(char) * (len + 1));
	if (!arr[index])
		return (0);
	ft_memcpy(arr[index], s, len);
	arr[index][len] = '\0';
	return (len);
}

static char	**ps_fill(char **arr, const char *s, char c)
{
	int	i;
	int	index;
	int	len;

	i = 0;
	index = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (!s[i])
			break ;
		len = ps_add_word(arr, s + i, index, c);
		if (!len)
			return (ps_free(arr, index));
		i += len;
		index++;
	}
	arr[index] = NULL;
	return (arr);
}

char	**ps_split(char const *s, char c)
{
	char	**arr;

	if (!s)
		return (NULL);
	arr = malloc(sizeof(char *) * (ps_count(s, c) + 1));
	if (!arr)
		return (NULL);
	return (ps_fill(arr, s, c));
}
