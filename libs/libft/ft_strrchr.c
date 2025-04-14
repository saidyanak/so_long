/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syanak <syanak@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 10:22:23 by syanak            #+#    #+#             */
/*   Updated: 2024/11/05 16:20:25 by syanak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	sizes;

	sizes = ft_strlen(s);
	while (sizes >= 0)
	{
		if (s[sizes] == (char)c)
			return ((char *)&s[sizes]);
		sizes--;
	}
	return (NULL);
}
