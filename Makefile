LIB = libft/libft.a

GNL = gnl/get_next_line.a

LIBN	=

MLX = -Lmlx -lmlx -framework OpenGL -framework AppKit

CC = gcc

SOURCES = so_long.c help.c valid.c valid_2.c map_operations.c moves.c

SOURCES_B = so_long_bonus.c help_bonus.c valid.c valid_2.c map_operations_bonus.c moves_bonus.c

OBJECTS_B = $(SOURCES_B:%.c=%.o)

OBJECTS = $(SOURCES:%.c=%.o)

HEADER = header

NAME = so_long

CFLAGS = -Wall -Werror -Wextra -Imlx -I $(HEADER)

.PHONY: all clean fclean re bonus

all	: $(NAME)

$(NAME)	: $(OBJECTS) $(HEADER)
	make -C ./mlx
	make -C libft
	make -C gnl
	$(CC) $(CFLAGS) $(MLX) $(OBJECTS) $(GNL) $(LIB) -o $(NAME)

%.o	: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

bonus	: $(OBJECTS_B) $(HEADER)
	make -C libft
	make -C gnl
	$(CC) $(CFLAGS) $(MLX) $(OBJECTS_B) $(GNL) $(LIB) -o $(NAME)

clean	:
	make -C libft clean
	make -C gnl clean
	make -C mlx clean
	rm -f $(OBJECTS)
	rm -f $(OBJECTS_B)

fclean	: clean
	@rm -rf libmlx.dylib
	make -C libft fclean
	make -C gnl fclean
	rm -f $(NAME)

re	:  fclean all
