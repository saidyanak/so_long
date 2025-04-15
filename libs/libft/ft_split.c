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

static char	**free_mem(char **arr)
{
	int	i;

	i = 0;
	while (arr[i] != NULL)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	return (NULL);
}

static int	count_words(const char *str, char sep)
{
	int	count;

	count = 0;
	while (*str != '\0')
	{
		if (*str == sep)
			str++;
		else
		{
			count++;
			while (*str != '\0' && *str != sep)
				str++;
		}
	}
	return (count);
}

static int	word_len(const char *str, char sep)
{
	int	len;

	len = 0;
	while (*str != '\0' && *str != sep)
	{
		len++;
		str++;
	}
	return (len);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	int		i;

	i = 0;
	if (s == NULL)
		return (NULL);
	arr = (char **)malloc((count_words(s, c) + 1) * sizeof(char *));
	if (arr == NULL)
		return (NULL);
	while (*s != '\0')
	{
		while (*s != '\0' && *s == c)
			s++;
		if (*s != '\0' && *s != c)
		{
			arr[i] = (char *)malloc((word_len(s, c) + 1) * sizeof(char));
			if (arr[i] == NULL)
				return (free_mem(arr));
			ft_strlcpy(arr[i], s, (word_len(s, c) + 1));
			s += word_len(s, c);
			i++;
		}
	}
	arr[i] = NULL;
	return (arr);
}
