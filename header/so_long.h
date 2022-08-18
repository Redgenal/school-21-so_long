#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/header/libft.h"
# include "../gnl/header/get_next_line_bonus.h"
# include "../mlx/header/mlx.h"
# include <fcntl.h>
# include <stdlib.h>
# include <time.h>
# include <stdio.h>

typedef struct	s_struct {
	int		length;
	int		width;
	char	**map;
	int		items;
	int		collected;
	int		steps;
}	t_Mapinfo;

typedef struct	s_data {
	void	*mlx;
	void	*window;
	void	*wall;
	void	*collect;
	void	*collect2;
	void	*collect3;
	void	*player;
	void	*floor;
	void	*exit;
	void	*enemy;
	void	*ramka;
	int		player_x;
	int		player_y;
	int		enemy_x;
	int		enemy_y;
	int		k;
}	t_Image;

typedef struct	s_structure {
	t_Image		*img;
	t_Mapinfo	*map_info;
}	t_Mainstuct;

void	ft_create_and_check_map(char **argv, t_Mapinfo *map_info, t_Image *img);
void	ft_init_struct(t_Mapinfo *map_info, t_Image *img);
void    ft_print_error(char *str);
void	ft_parse_map(char **argv, t_Mapinfo *map_info);
void	ft_is_rect(t_Mapinfo *map_info);
void	ft_is_fenced(t_Mapinfo *map_info);
void	ft_is_valid(t_Mapinfo *map_info);
void    ft_is_ber(char **argv);
void    ft_is_correct(t_Mapinfo *map_info);

void	ft_textures(t_Image *img);
void	ft_create_basic_image(t_Mapinfo *map_info, t_Image *img);
void	ft_move_right(t_Mainstuct	*m_s);
void	ft_move_left(t_Mainstuct	*m_s);
void	ft_move_up(t_Mainstuct	*m_s);
void	ft_move_down(t_Mainstuct	*m_s);
void	ft_win_game(t_Mainstuct	*m_s);

int		ft_circle_draw(t_Mainstuct *m_s);
int		ft_close_window(t_Mainstuct	*main_struct);
int		ft_hook_operations(int keycode, t_Mainstuct	*main_struct);
#endif
