#include <stddef.h>

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	int		k;

	i = 0;
	k = 0;
	while (src[k] != '\0')
		k++;
	if (size == 0)
		return (k);
	if (k == 0)
	{
		dst[i] = '\0';
		return (k);
	}
	while (i + 1 < size && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (k);
}
