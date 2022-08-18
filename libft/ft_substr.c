#include <stddef.h>
#include <stdlib.h>
#include "header/libft.h"

static size_t	ft_min(size_t a, size_t b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*s2;
	size_t	lenght;

	if (!s)
		return (NULL);
	i = 0;
	lenght = ft_strlen(s);
	s2 = malloc(sizeof(char) * (ft_min(len, lenght) + 1));
	if (!s2)
		return (NULL);
	s2[i] = '\0';
	if (start >= lenght)
		return (s2);
	while (i < len && s[start + i] != '\0')
	{
		s2[i] = s[start + i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}
