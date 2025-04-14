/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syanak <syanak@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 10:20:58 by syanak            #+#    #+#             */
/*   Updated: 2024/11/05 15:25:18 by syanak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	ft_step(int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		i++;
	while (n)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*ret;
	long	nmbr;
	int		step;

	nmbr = n;
	if (n < 0)
		nmbr = -nmbr;
	step = ft_step(n);
	ret = (char *)malloc(sizeof(char) * step + 1);
	if (!ret)
		return (NULL);
	if (n < 0)
		ret[0] = '-';
	if (n == 0)
		ret[0] = '0';
	ret[step] = 0;
	while (nmbr)
	{
		ret[--step] = (nmbr % 10) + 48;
		nmbr /= 10;
	}
	return (ret);
}
