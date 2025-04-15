/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syanak <syanak@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 10:21:56 by syanak            #+#    #+#             */
/*   Updated: 2024/11/05 16:19:40 by syanak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	char	*ptr;
	size_t	index;

	ptr = (char *)malloc(sizeof(*s1) * (ft_strlen(s1) + 1));
	if (!ptr)
		return (NULL);
	index = 0;
	while (s1[index])
	{
		ptr[index] = s1[index];
		index++;
	}
	ptr[index] = '\0';
	return (ptr);
}
