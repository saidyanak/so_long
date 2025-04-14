#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void* (*f)(void*),void (*del)(void*))
{
	t_list	**ret;

	ret =(t_list**)malloc(sizeof(t_list*));
	while (lst)
	{
		*ret = ft_lstadd_front(ret,f(lst->content));
		
		lst = lst->next;
	}


}
