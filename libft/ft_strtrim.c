#include <stddef.h>
#include <stdlib.h>
#include "header/libft.h"

static size_t	ft_first(char const *s1, char const *set)
{
	int		counter;
	size_t	i;
	size_t	j;
	size_t	len2;
	size_t	len;

	counter = 1;
	i = 0;
	len2 = ft_strlen(set);
	len = ft_strlen(s1);
	if (len2 == 0)
		return (0);
	while (counter > 0 && i < len)
	{
		j = 0;
		counter = 0;
		while (j < len2)
		{
			if (s1[i] == set[j])
				counter++;
			j++;
		}
		i++;
	}
	return (i);
}

static size_t	ft_last(char const *s1, char const *set)
{
	size_t	len;
	size_t	len2;
	int		counter;
	size_t	j;

	len = ft_strlen(s1);
	len2 = ft_strlen(set);
	counter = 1;
	if (len2 == 0)
		return (0);
	while ((counter > 0) && len)
	{
		j = 0;
		counter = 0;
		while (j < len2)
		{
			if (s1[len - 1] == set[j])
				counter++;
			j++;
		}
		len--;
	}
	return (len);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	i;
	size_t	j;
	size_t	len;

	if (!s1)
		return (NULL);
	len = ft_strlen(s1);
	if (ft_strlen(set) == 0)
	{
		str = malloc(sizeof(char));
		str = ft_memcpy(str, s1, len + 1);
		return (str);
	}
	i = ft_first(s1, set);
	j = ft_last(s1, set);
	if (i == len)
	{
		str = ft_calloc(1, 1);
		return (str);
	}
	str = ft_substr(s1, i - 1, (j - (i - 1) + 1));
	if (!str)
		return (NULL);
	return (str);
}
