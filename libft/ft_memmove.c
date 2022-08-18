#include <stddef.h>

void	*ft_memmove(void *str1, const void *str2, size_t len)
{
	size_t			i;

	i = 0;
	if (str1 == str2)
		return (str1);
	else if (str1 > str2)
	{
		i = len;
		while (i >= 1)
		{
			*(unsigned char *)(str1 + i - 1) = *(unsigned char *)(str2 + i - 1);
			i--;
		}
	}
	else
	{
		while (i < len)
		{
			*(unsigned char *)(str1 + i) = *(unsigned char *)(str2 + i);
			i++;
		}
	}
	return (str1);
}
