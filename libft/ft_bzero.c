#include <stddef.h>

void	ft_bzero(void *str, size_t n)
{
	unsigned long	i;

	i = 0;
	while (i < n)
	{
		*(unsigned char *)(str + i) = '\0';
		i++;
	}
}
