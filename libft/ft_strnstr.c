#include <stddef.h>
#include "header/libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	k;
	size_t	j;

	i = 0;
	k = ft_strlen(needle);
	if (k == 0)
		return ((char *) &haystack[0]);
	if (len == 0)
		return (NULL);
	while (haystack[i] != '\0' && i <= len - 1)
	{
		j = 0;
		while (j < len && needle[j] != '\0' && (i + j) < len)
		{
			if (haystack[i + j] != needle[j])
				break ;
			j++;
		}
		if (j == k)
			return ((char *)(haystack + i));
		i++;
	}
	return (0);
}
