#include <stddef.h>

void	*ft_memcpy(void *str1, const void *str2, size_t len)
{
	unsigned long	i;

	i = 0;
	if (!str1 && !str2)
		return (str1);
	while (i < len)
	{
		*(unsigned char *)(str1 + i) = *(unsigned char *)(str2 + i);
		i++;
	}
	return (str1);
}
