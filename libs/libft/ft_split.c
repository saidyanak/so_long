/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syanak <syanak@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 10:16:19 by syanak            #+#    #+#             */
/*   Updated: 2024/11/05 16:19:12 by syanak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static void	freedoublepinter(char **ret)
{
	int	i;

	i = 0;
	while (ret[i])
		free(ret[i++]);
	free(ret);
}

static	int	ft_count(char const *s, char c)
{
	int	count;
	int	in_word;

	count = 0;
	in_word = 0;
	while (*s)
	{
		if (*s == c)
			in_word = 0;
		else if (in_word == 0)
		{
			in_word = 1;
			count++;
		}
		s++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	int		k;
	char	**ret;
	size_t	i;

	k = 0;
	ret = (char **)malloc(sizeof(char *) * (ft_count(s, c) + 1));
	if (!ret)
		return (NULL);
	while (*s)
	{
		i = 0;
		while (*s && *s == c)
			s++;
		if (*s)
		{
			while (s[i] && s[i] != c)
				i++;
			ret[k] = ft_substr(s, 0, i);
			if (!ret[k])
				return (freedoublepinter(ret), NULL);
			s += i;
			k++;
		}
	}
	return (ret[k] = NULL, ret);
}
