/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stbstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syanak <syanak@student.42kocaeli.com.tr >  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 16:31:29 by syanak            #+#    #+#             */
/*   Updated: 2025/04/15 16:31:30 by syanak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ret;
	size_t	size_s;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	size_s = ft_strlen(s);
	if (start > size_s)
		return (ft_strdub(""));
	if (len > size_s - start)
		len = size_s - start;
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
