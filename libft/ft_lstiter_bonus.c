#include "header/libft.h"
#include <stdlib.h>

void	ft_lstiter(t_list *list, void (*f)(void *))
{
	if (!list)
		return ;
	while (list->next != NULL)
	{
		f(list->content);
		list = list->next;
	}
	f(list->content);
}
