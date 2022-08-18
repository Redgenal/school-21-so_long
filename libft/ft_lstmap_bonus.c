#include "header/libft.h"
#include <stdlib.h>

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*leest;
	t_list	*arr;

	arr = NULL;
	while (lst != NULL)
	{
		leest = ft_lstnew(f(lst->content));
		if (!leest)
		{
			ft_lstclear(&arr, del);
			return (arr);
		}
		ft_lstadd_back(&arr, leest);
		lst = lst->next;
	}
	return (arr);
}
