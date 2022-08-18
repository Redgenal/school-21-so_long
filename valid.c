#include "header/so_long.h"

void	ft_find_width(char **argv, t_Mapinfo *map_info)
{
	int		fd;
	int		i;
	char	*str;

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		ft_print_error("Cant open");
	i = 0;
	str = malloc(sizeof(*str));
	if (!str)
		ft_print_error("Malloc error");
	*str = 'y';
	while (str != NULL)
	{
		free(str);
		str = get_next_line(fd);
		i++;
	}
	free (str);
	map_info->width = i - 1;
}

void	ft_parse_map(char **argv, t_Mapinfo *map_info)
{
	int		fd;
	char	*buff;
	int		i;

	ft_find_width(argv, map_info);
	map_info->map = malloc((map_info->width + 1) * sizeof(*(map_info->map)));
	if (!map_info->map)
		ft_print_error("Malloc error");
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		ft_print_error("Cant open");
	i = -1;
	buff = "hello";
	while (buff != NULL)
	{
		buff = NULL;
		buff = get_next_line(fd);
		map_info->map[++i] = buff;
	}
	free (buff);
}

void	ft_is_rect(t_Mapinfo *map_info)
{
	int		i;

	i = -1;
	map_info->length = ft_strlen(map_info->map[0]);
	while (map_info->map[++i] != NULL)
	{
		if (ft_strlen(map_info->map[i]) != (size_t)map_info->length)
			ft_print_error("Not rectangular");
	}
}

void	ft_is_fenced(t_Mapinfo *map_info)
{
	int	i;
	int	j;

	i = -1;
	while (++i < map_info->length)
		if (map_info->map[0][i] != '1')
			ft_print_error("Not fenced");
	j = 0;
	while (++j < map_info->width - 1)
	{
		if (map_info->map[j][0] != '1')
			ft_print_error("Not fenced");
		if (map_info->map[j][i - 1] != '1')
			ft_print_error("Not fenced");
	}
	i = -1;
	while (++i < map_info->length)
		if (map_info->map[j][i] != '1')
			ft_print_error("Not fenced");
}

void	ft_is_valid(t_Mapinfo *map_info)
{
	int	i;
	int	j;

	j = -1;
	while (++j < map_info->width)
	{
		i = -1;
		while (++i < map_info->length)
		{
			if ((map_info->map[j][i] != '1') && (map_info->map[j][i] != '0')
				&& (map_info->map[j][i] != 'C') && (map_info->map[j][i] != 'E')
				&& (map_info->map[j][i] != 'P'))
				ft_print_error("Not valid");
		}
	}
}
