#include "header/so_long.h"

void	ft_move_enemy(t_Mainstuct	*m_s)
{
	time_t	t;
	int		n;

	srand((unsigned) time(&t));
	n = (rand() % 4);
	if (n == 0)
		if (m_s->map_info->map[m_s->img->enemy_y - 1][m_s->img->enemy_x] != '1')
			m_s->img->enemy_y -= 1;
	if (n == 1)
		if (m_s->map_info->map[m_s->img->enemy_y + 1][m_s->img->enemy_x] != '1')
			m_s->img->enemy_y += 1;
	if (n == 2)
		if (m_s->map_info->map[m_s->img->enemy_y][m_s->img->enemy_x - 1] != '1')
			m_s->img->enemy_x -= 1;
	if (n == 3)
		if (m_s->map_info->map[m_s->img->enemy_y][m_s->img->enemy_x + 1] != '1')
			m_s->img->enemy_x += 1;
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
		m_s->map_info->steps += 1;
		if (m_s->map_info->map[m_s->img->player_y - 1][m_s->img->player_x]
			== 'E')
			if (m_s->map_info->collected == m_s->map_info->items)
				ft_win_game(m_s);
		m_s->img->player_y -= 1;
		ft_move_enemy(m_s);
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
		m_s->map_info->steps += 1;
		if (m_s->map_info->map[m_s->img->player_y + 1][m_s->img->player_x]
			== 'E')
			if (m_s->map_info->collected == m_s->map_info->items)
				ft_win_game(m_s);
		m_s->img->player_y += 1;
		ft_move_enemy(m_s);
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
		m_s->map_info->steps += 1;
		if (m_s->map_info->map[m_s->img->player_y][m_s->img->player_x - 1]
			== 'E')
			if (m_s->map_info->collected == m_s->map_info->items)
				ft_win_game(m_s);
		m_s->img->player_x -= 1;
		ft_move_enemy(m_s);
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
		if (m_s->map_info->map[m_s->img->player_y][m_s->img->player_x + 1]
			== 'E')
			if (m_s->map_info->collected == m_s->map_info->items)
				ft_win_game(m_s);
		m_s->img->player_x += 1;
		ft_move_enemy(m_s);
	}
	ft_create_basic_image(m_s->map_info, m_s->img);
}
