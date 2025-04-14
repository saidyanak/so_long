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
	char	*ret;

	ret = (char *)malloc((1 + ft_strlen(s1)) * sizeof(char));
	if (!ret)
		return (NULL);
	ft_memcpy(ret, s1, ft_strlen(s1) + 1);
	return (ret);
}
