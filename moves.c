#include "header/so_long.h"

int	ft_close_window(t_Mainstuct	*main_struct)
{
	if (main_struct->img->window != NULL)
		mlx_destroy_window(main_struct->img->mlx, main_struct->img->window);
	exit (0);
}

void	ft_move_up(t_Mainstuct	*m_s)
{
	if (m_s->map_info->map[m_s->img->player_y - 1][m_s->img->player_x] != '1')
	{
		if (m_s->map_info->map[m_s->img->player_y - 1][m_s->img->player_x]
			== 'C')
		{
			m_s->map_info->map[m_s->img->player_y - 1][m_s->img->player_x]
				= '0';
			m_s->map_info->collected += 1;
		}
		m_s->img->player_y -= 1;
		m_s->map_info->steps += 1;
		printf("Steps = %d\n", m_s->map_info->steps);
		if (m_s->map_info->map[m_s->img->player_y][m_s->img->player_x]
			== 'E')
			if (m_s->map_info->collected == m_s->map_info->items)
				ft_win_game(m_s);
	}
	ft_create_basic_image(m_s->map_info, m_s->img);
}

void	ft_move_down(t_Mainstuct *m_s)
{
	if (m_s->map_info->map[m_s->img->player_y + 1][m_s->img->player_x] != '1')
	{
		if (m_s->map_info->map[m_s->img->player_y + 1][m_s->img->player_x]
			== 'C')
		{
			m_s->map_info->map[m_s->img->player_y + 1][m_s->img->player_x]
				= '0';
			m_s->map_info->collected += 1;
		}
		m_s->img->player_y += 1;
		m_s->map_info->steps += 1;
		printf("Steps = %d\n", m_s->map_info->steps);
		if (m_s->map_info->map[m_s->img->player_y][m_s->img->player_x]
			== 'E')
			if (m_s->map_info->collected == m_s->map_info->items)
				ft_win_game(m_s);
	}
	ft_create_basic_image(m_s->map_info, m_s->img);
}

void	ft_move_left(t_Mainstuct	*m_s)
{
	if (m_s->map_info->map[m_s->img->player_y][m_s->img->player_x - 1] != '1')
	{
		if (m_s->map_info->map[m_s->img->player_y][m_s->img->player_x - 1]
			== 'C')
		{
			m_s->map_info->map[m_s->img->player_y][m_s->img->player_x - 1]
				= '0';
			m_s->map_info->collected += 1;
		}
		m_s->img->player_x -= 1;
		m_s->map_info->steps += 1;
		printf("Steps = %d\n", m_s->map_info->steps);
		if (m_s->map_info->map[m_s->img->player_y][m_s->img->player_x]
			== 'E')
			if (m_s->map_info->collected == m_s->map_info->items)
				ft_win_game(m_s);
	}	
	ft_create_basic_image(m_s->map_info, m_s->img);
}

void	ft_move_right(t_Mainstuct	*m_s)
{
	if (m_s->map_info->map[m_s->img->player_y][m_s->img->player_x + 1] != '1')
	{
		if (m_s->map_info->map[m_s->img->player_y][m_s->img->player_x + 1]
			== 'C')
		{
			m_s->map_info->map[m_s->img->player_y][m_s->img->player_x + 1]
				= '0';
			m_s->map_info->collected += 1;
		}
		m_s->map_info->steps += 1;
		printf("Steps = %d\n", m_s->map_info->steps);
		m_s->img->player_x += 1;
		if (m_s->map_info->map[m_s->img->player_y][m_s->img->player_x]
			== 'E')
			if (m_s->map_info->collected == m_s->map_info->items)
				ft_win_game(m_s);
	}
	ft_create_basic_image(m_s->map_info, m_s->img);
}
