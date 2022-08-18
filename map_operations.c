#include "header/so_long.h"

void	ft_create_basic_image(t_Mapinfo *map_info, t_Image *img)
{
	int	i;
	int	j;

	j = -1;
	while (++j < map_info->width)
	{
		i = -1;
		while (++i < map_info->length)
		{
			mlx_put_image_to_window(img->mlx, img->window, img->floor,
				64 * i, 64 * j);
			if (map_info->map[j][i] == '1')
				mlx_put_image_to_window(img->mlx, img->window, img->wall,
					64 * i, 64 * j);
			if (map_info->map[j][i] == 'E')
				mlx_put_image_to_window(img->mlx, img->window, img->exit,
					64 * i, 64 * j);
			if (map_info->map[j][i] == 'C')
				mlx_put_image_to_window(img->mlx, img->window, img->collect,
					64 * i, 64 * j);
			if (j == img->player_y && i == img->player_x)
				mlx_put_image_to_window(img->mlx, img->window, img->player,
					64 * i, 64 * j);
		}
	}
}

int	ft_hook_operations(int keycode, t_Mainstuct	*m_s)
{
	if (keycode == 53)
		ft_close_window(m_s);
	if (keycode == 13)
		ft_move_up(m_s);
	if (keycode == 0)
		ft_move_left(m_s);
	if (keycode == 1)
		ft_move_down(m_s);
	if (keycode == 2)
		ft_move_right(m_s);
	return (0);
}
