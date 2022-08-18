#include "header/so_long.h"

void	ft_is_ber(char **argv)
{
	int	i;

	i = ft_strlen(argv[1]);
	if ((argv[1][i - 4] != '.') || (argv[1][i - 3] != 'b')
		|| (argv[1][i - 2] != 'e') || (argv[1][i - 1] != 'r'))
		ft_print_error("Wrong map format");
}

void	ft_is_correct(t_Mapinfo *map_info)
{
	int	i;
	int	j;
	int	exit;
	int	start;

	j = -1;
	exit = 0;
	start = 0;
	while (++j < map_info->width)
	{
		i = -1;
		while (++i < map_info->length)
		{
			if (map_info->map[j][i] == 'E')
				exit += 1;
			if (map_info->map[j][i] == 'P')
				start += 1;
			if (map_info->map[j][i] == 'C')
				map_info->items += 1;
		}
	}
	if ((exit == 0) || (start == 0) || (map_info->items == 0))
		ft_print_error("Wrong positions");
}

int	ft_find_player(t_Mapinfo *map_info, t_Image *img)
{
	int	i;
	int	j;

	j = -1;
	while (++j < map_info->width)
	{
		i = -1;
		while (++i < map_info->length)
		{
			if (map_info->map[j][i] == 'P')
			{
				img->player_x = i;
				img->player_y = j;
				return (0);
			}
		}
	}
	return (0);
}

int	ft_find_enemy(t_Mapinfo *map_info, t_Image *img)
{
	int	i;
	int	j;

	j = -1;
	while (++j < map_info->width)
	{
		i = -1;
		while (++i < map_info->length)
		{
			if (map_info->map[j][i] == 'C')
			{
				img->enemy_x = i;
				img->enemy_y = j;
				return (0);
			}
		}
	}
	return (0);
}

void	ft_create_and_check_map(char **argv, t_Mapinfo *map_info, t_Image *img)
{
	ft_init_struct(map_info, img);
	ft_is_ber(argv);
	ft_parse_map(argv, map_info);
	ft_is_rect(map_info);
	ft_is_fenced(map_info);
	ft_is_valid(map_info);
	ft_is_correct(map_info);
	ft_find_player(map_info, img);
	ft_find_enemy(map_info, img);
}
