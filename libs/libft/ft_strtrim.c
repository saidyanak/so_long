/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syanak <syanak@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 10:22:26 by syanak            #+#    #+#             */
/*   Updated: 2024/11/05 16:08:44 by syanak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static	int	ft_chrcmpr(char chr, char const *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == chr)
		{
			return (1);
		}
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	end;
	size_t	start;
	char	*ret;
	size_t	i;

	start = 0;
	end = ft_strlen(s1);
	while (ft_chrcmpr(s1[start], set))
		start++;
	while (start < end && ft_chrcmpr(s1[end - 1], set))
		end--;
	ret = (char *)malloc(sizeof(char) * (end - start + 1));
	if (!ret)
		return (NULL);
	i = 0;
	while (start < end)
		ret[i++] = s1[start++];
	ret[i] = 0;
	return (ret);
}
