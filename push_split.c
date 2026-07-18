/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_split.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliannawira <juliannawira@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/18 00:52:19 by juliannawir       #+#    #+#             */
/*   Updated: 2026/07/18 11:05:48 by juliannawir      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ps_len(const char *s, int i, char c)
{
	int	len;
	
	len = 0;
	while (s[i] && s[i] != c)
	{
		len++;
		i++;
	}
	return (len);
}

static int	ps_count(const char *s, char c)
{
	int	w = 0;
	int	i = 0;

	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
			w++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (w);
}

char	**ps_split(char const *s, char c)
{
	char	**arr;
	int		i = 0;
	int		idx = 0;
	int		len;

	if (!s || !(arr = malloc((ps_count(s, c) + 1) * sizeof(char *))))
		return (NULL);
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (!s[i])
			break;
		len = ps_len(s, i, c);
		if (!(arr[idx] = malloc(len + 1)))
			return (NULL);
		ft_memcpy(arr[idx], &s[i], len);
		arr[idx++][len] = '\0';
		i += len;
	}
	arr[idx] = NULL;
	return (arr);
}
