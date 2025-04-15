/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syanak <syanak@student.42kocaeli.com.tr >  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 16:31:39 by syanak            #+#    #+#             */
/*   Updated: 2025/04/15 16:31:40 by syanak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	**ret;

	ret = (t_list **)malloc(sizeof(t_list *));
	while (lst)
	{
		*ret = ft_lstadd_front(ret, f(lst->content));
		lst = lst->next;
	}
}
