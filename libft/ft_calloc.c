#include <stddef.h>
#include <stdlib.h>
#include "header/libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*mem;

	mem = malloc(size * count);
	if (!mem)
		return (NULL);
	ft_bzero(mem, size * count);
	return (mem);
}
