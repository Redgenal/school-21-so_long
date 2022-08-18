#include "header/so_long.h"

void	ft_print_error(char *str)
{
	write(2, "Error: ", 7);
	write(2, str, ft_strlen(str));
	write(2, "\n", 1);
	exit(1);
}

void	ft_init_struct(t_Mapinfo *map_info, t_Image *img)
{
	map_info->length = 0;
	map_info->width = 0;
	map_info->items = 0;
	map_info->collected = 0;
	img->player_x = 0;
	img->player_y = 0;
	map_info->steps = 0;
	img->enemy_x = 0;
	img->enemy_y = 0;
}

void	ft_win_game(t_Mainstuct	*m_s)
{
	printf("You win!\n");
	ft_close_window(m_s);
}

void	ft_textures(t_Image *img)
{
	int	img_width;
	int	img_height;

	img->wall = mlx_xpm_file_to_image(img->mlx, "sprites/wall.xpm",
			&img_width, &img_height);
	img->collect = mlx_xpm_file_to_image(img->mlx, "sprites/crystal1.xpm",
			&img_width, &img_height);
	img->player = mlx_xpm_file_to_image(img->mlx, "sprites/player.xpm",
			&img_width, &img_height);
	img->floor = mlx_xpm_file_to_image(img->mlx, "sprites/floor.xpm",
			&img_width, &img_height);
	img->exit = mlx_xpm_file_to_image(img->mlx, "sprites/exit.xpm",
			&img_width, &img_height);
}
