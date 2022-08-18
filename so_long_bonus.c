#include "header/so_long.h"

void	ft_loop_write(t_Mainstuct *m_s)
{
	m_s->img->mlx = mlx_init();
	m_s->img->window = mlx_new_window(m_s->img->mlx, 64 * m_s->map_info->length,
			64 * m_s->map_info->width + 30, "utawana");
	ft_textures(m_s->img);
	ft_create_basic_image(m_s->map_info, m_s->img);
	mlx_hook(m_s->img->window, 2, 0, ft_hook_operations, m_s);
	mlx_hook(m_s->img->window, 17, 0, ft_close_window, m_s);
	mlx_loop_hook(m_s->img->mlx, &ft_circle_draw, m_s);
	mlx_loop(m_s->img->mlx);
}

int	main(int argc, char **argv)
{
	t_Mapinfo	*map_info;
	t_Image		*img;
	t_Mainstuct	*main_struct;

	if (argc != 2)
		return (0);
	map_info = malloc(sizeof(t_Mapinfo));
	if (!map_info)
		ft_print_error("Malloc error");
	img = malloc(sizeof(t_Image));
	if (!img)
		ft_print_error("Malloc error");
	ft_create_and_check_map(argv, map_info, img);
	main_struct = malloc(sizeof(t_Mainstuct));
	if (!main_struct)
		ft_print_error("Malloc error");
	main_struct->img = img;
	main_struct->map_info = map_info;
	ft_loop_write(main_struct);
}
