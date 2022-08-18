#include <stddef.h>
#include <stdlib.h>
#include "header/libft.h"

static int	ft_intlen(int n)
{
	int	count;

	count = 0;
	if (n < 0)
	{
		count++;
		if (n == -2147483648)
		{
			count++;
			n += 2000000000;
		}
		n *= -1;
	}
	if (n == 0)
	{
		count++;
	}
	while (n > 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

static char	*for_plus(int n, char *str, int i)
{
	char	rev[100];
	int		j;

	j = 0;
	while (n > 0)
	{
		rev[j] = n % 10 + '0';
		n /= 10;
		j++;
	}
	j--;
	while (j >= 0)
	{
		str[i] = rev[j];
		i++;
		j--;
	}
	str[i] = '\0';
	return (str);
}

static char	*for_minus(int n, char *str)
{
	int	i;

	i = 0;
	str[i] = '-';
	i++;
	if (n == -2147483648)
	{
		str[i] = '2';
		i++;
		n += 2000000000;
	}
	n *= -1;
	str = for_plus(n, str, i);
	return (str);
}

char	*ft_itoa(int n)
{
	int		i;
	char	*str;

	str = malloc((ft_intlen(n) + 1) * sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	if (n < 0)
	{
		str = for_minus(n, str);
	}
	else if (n == 0)
	{
		str[i] = '0';
		str[i + 1] = '\0';
	}
	else
	{
		str = for_plus(n, str, i);
	}
	return (str);
}
