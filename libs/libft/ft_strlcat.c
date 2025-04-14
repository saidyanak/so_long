/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syanak <syanak@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 10:22:02 by syanak            #+#    #+#             */
/*   Updated: 2024/11/05 16:19:55 by syanak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	sizedst;
	size_t	i;

	sizedst = ft_strlen(dst);
	i = 0;
	if (dstsize)
	{
		while ((i + sizedst < dstsize -1) && src[i])
		{
			dst[i + sizedst] = src[i];
			i++;
		}
	}
	dst[i + sizedst] = 0;
	if (sizedst > dstsize)
		return (dstsize + ft_strlen(src));
	return (sizedst + ft_strlen(src));
}
