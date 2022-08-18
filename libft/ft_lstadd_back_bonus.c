#include "header/libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*leest;

	if (*lst)
	{
		leest = ft_lstlast(*lst);
		leest->next = new;
	}
	else
		*lst = new;
}
