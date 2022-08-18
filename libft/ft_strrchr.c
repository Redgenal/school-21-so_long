char	*ft_strrchr(const char *string, int symbol)
{
	int				i;
	unsigned char	*result;

	i = 0;
	while (string[i] != '\0')
		i++;
	while ((unsigned char) string[i] != (unsigned char) symbol)
	{
		if (i < 0)
			return (0);
		i--;
	}
	result = (unsigned char *) &string[i];
	return ((char *) result);
}
