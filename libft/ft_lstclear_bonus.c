#include "header/libft.h"
#include <stdlib.h>

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*leest;
	t_list	*leest2;

	leest = *lst;
	while (leest->next != NULL)
	{
		del(leest->content);
		leest2 = leest->next;
		free(leest);
		leest = leest2;
	}
	del(leest->content);
	free(leest);
	*lst = NULL;
}
