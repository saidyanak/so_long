/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syanak <syanak@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 10:21:51 by syanak            #+#    #+#             */
/*   Updated: 2024/11/05 11:57:32 by syanak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ret;
	size_t	sizes;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	sizes = ft_strlen(s);
	if (start > sizes)
		return (ft_strdup(""));
	if (len > sizes - start)
		len = sizes - start;
	ret = (char *)malloc(sizeof(char) * (len + 1));
	if (!ret)
		return (NULL);
	while (s[i + start] && i < len)
	{
		ret[i] = (char)s[i + start];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}
