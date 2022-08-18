#include <stddef.h>
#include <stdlib.h>
#include "header/libft.h"

static void	ft_clear(char **arr)
{
	int	i;

	i = 0;
	while (arr[i] != NULL)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

static int	ft_count(const char *s, char c)
{
	int	n;
	int	i;

	n = 0;
	i = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c && s[i] != '\0')
		{
			i++;
		}
		if (s[i] != '\0')
			n++;
		while (s[i] != c && s[i] != '\0')
		{
			i++;
		}
	}
	return (n);
}

static int	ft_start(const char *s, char c, int i)
{
	while (s[i] == c && s[i] != '\0')
	{
		i++;
	}
	return (i);
}

static int	ft_end(const char *s, char c, int i)
{
	while (s[i] == c && s[i] != '\0')
	{
		i++;
	}
	while (s[i] != c && s[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	**ft_split(const char *s, char c)
{
	int		i;
	char	**arr;
	int		j;
	int		k;

	if (!s)
		return (NULL);
	i = 0;
	j = 0;
	arr = malloc((ft_count(s, c) + 1) * sizeof(char *));
	if (!arr)
		return (NULL);
	while (s[i] != '\0')
	{
		k = ft_start(s, c, i);
		if (s[k] == '\0')
			break ;
		i = ft_end(s, c, i);
		arr[j] = ft_substr(s, k, (i - k));
		if (!arr[j])
			ft_clear(arr);
		j++;
	}
	arr[j] = NULL;
	return (arr);
}
