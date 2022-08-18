#include <unistd.h>
#include "header/libft.h"

static int	ft_minus(int n, int fd)
{
	if (n == -2147483647 - 1)
	{
		ft_putchar_fd('2', fd);
		n = -147483648;
	}
	n *= -1;
	return (n);
}

void	ft_putnbr_fd(long long n, int fd)
{
	int		i;
	char	buff[20];

	i = 0;
	if (n < 0)
		n = ft_minus(n, fd);
	if (n == 0)
		ft_putchar_fd('0', fd);
	while (n > 0)
	{
		buff[i] = n % 10 + '0';
		n /= 10;
		i++;
	}
	while (i > 0)
	{
		i--;
		ft_putchar_fd(buff[i], fd);
	}
}
