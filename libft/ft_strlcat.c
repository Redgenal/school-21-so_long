#include <stddef.h>

static size_t	ft_min(size_t a, size_t b)
{
	if (a <= b)
		return (a);
	else
		return (b);
}

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	int		k;
	size_t	len;
	size_t	len2;

	i = 0;
	k = 0;
	len = 0;
	len2 = 0;
	while (dst[len] != '\0')
		len++;
	while (src[len2] != '\0')
		len2++;
	i = len;
	if (size == 0)
		return (len2 + ft_min(size, len));
	while (i < (size - 1) && src[k])
	{
		dst[i] = src[k];
		i++;
		k++;
	}
	dst[i] = '\0';
	return (len2 + ft_min(size, len));
}
