#include <unistd.h>
#include "header/libft.h"
#include <stddef.h>

void	ft_putstr_fd(char *s, int fd)
{
	size_t	len;

	if (!s)
		return ;
	len = 0;
	len = ft_strlen(s);
	write(fd, s, len);
}
