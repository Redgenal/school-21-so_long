#include <unistd.h>
#include "header/libft.h"
#include <stddef.h>

void	ft_putendl_fd(char *s, int fd)
{
	size_t	len;
	char	c;

	if (!s)
		return ;
	len = 0;
	c = '\n';
	len = ft_strlen(s);
	write(fd, s, len);
	write(fd, &c, 1);
}
