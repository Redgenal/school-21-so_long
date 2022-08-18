char	*ft_strchr(const char *string, int symbol)
{
	int				i;
	unsigned char	*result;

	i = 0;
	while ((unsigned char)string[i] != (unsigned char)symbol)
	{
		if (string[i] == '\0')
			return (0);
		i++;
	}
	result = (unsigned char *) &string[i];
	return ((char *)result);
}
