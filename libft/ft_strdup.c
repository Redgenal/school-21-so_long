#include <stddef.h>
#include <stdlib.h>
#include "header/libft.h"

char	*ft_strdup(const char *s1)
{
	char	*mem;
	int		len;
	int		i;

	len = ft_strlen(s1);
	i = 0;
	mem = malloc((len + 1) * sizeof(char));
	if (!mem)
		return (NULL);
	while (i < len)
	{
		mem[i] = s1[i];
		i++;
	}
	mem[i] = '\0';
	return (mem);
}
