#include "header/so_long.h"

void	ft_call_change_img(t_Mainstuct *m_s)
{
	int	i;
	int	j;

	j = -1;
	while (++j < m_s->map_info->width)
	{
		i = -1;
		while (++i < m_s->map_info->length)
		{
			if (m_s->map_info->map[j][i] == 'C')
			{
				if (m_s->img->k == 1)
					mlx_put_image_to_window(m_s->img->mlx, m_s->img->window,
						m_s->img->collect, 64 * i, 64 * j);
				if (m_s->img->k == 2)
					mlx_put_image_to_window(m_s->img->mlx, m_s->img->window,
						m_s->img->collect2, 64 * i, 64 * j);
				if (m_s->img->k == 3)
					mlx_put_image_to_window(m_s->img->mlx, m_s->img->window,
						m_s->img->collect3, 64 * i, 64 * j);
			}
		}
	}
}

int	ft_circle_draw(t_Mainstuct *m_s)
{
	short	count;

	if (m_s->img->k == 4)
		m_s->img->k = 0;
	count = 0;
	while (count < 10000)
		count++;
	m_s->img->k += 1;
	ft_call_change_img(m_s);
	return (0);
}

void	ft_create_mandatory(t_Mapinfo *map_info, t_Image *img)
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

void	ft_create_basic_image(t_Mapinfo *map_info, t_Image *img)
{
	int		i;
	int		j;
	char	*str;

	ft_create_mandatory(map_info, img);
	j = -1;
	while (++j < map_info->width)
	{
		i = -1;
		while (++i < map_info->length)
		{
			if (j == img->enemy_y && i == img->enemy_x)
				mlx_put_image_to_window(img->mlx, img->window, img->enemy,
					64 * i, 64 * j);
		}
	}
	str = ft_itoa(map_info->steps);
	mlx_put_image_to_window(img->mlx, img->window, img->ramka,
		0, 64 * map_info->width);
	mlx_string_put(img->mlx, img->window, 24, 64 * map_info->width, -1, str);
	free(str);
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
	if ((m_s->img->player_x == m_s->img->enemy_x)
		&& (m_s->img->player_y == m_s->img->enemy_y))
	{
		printf("You lose\n");
		ft_close_window(m_s);
	}
	return (0);
}
