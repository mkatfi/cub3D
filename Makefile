NAME = cub3D

CC = clang

MLX_LIB = libmlx.a


FLAGS = -Wall -Wextra -Werror  -fsanitize=address -g3

MLX = -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz

SRC =	mandatory/main.c mandatory/engine/initilize.c \
		mandatory/engine/utils1.c mandatory/engine/hooks_utils.c \
		mandatory/engine/render_map.c \
		mandatory/engine/player_hooks.c \
		mandatory/engine/dda_version.c \
		mandatory/engine/fake_3d.c \
		mandatory/engine/set_textuers.c \
		mandatory/parcing/get_next_line.c\
		mandatory/parcing/ft_split.c \
		mandatory/parcing/function_libft_used.c \
		mandatory/parcing/function_libft.c \
		mandatory/parcing/fun_read_and_partition_map.c \
		mandatory/parcing/fun_used_check_map_in_main.c \
		mandatory/parcing/function_check_map.c \
		mandatory/parcing/function_check_texter.c \
		mandatory/parcing/fun_check_newline.c \
		mandatory/parcing/check_plus_texter.c 

OBJ = ${SRC:.c=.o}

%.o: %.c
	$(CC) ${FLAGS} -I/usr/include -Imlx_linux -O3 -c $< -o $@
	

#MLX = -lmlx -framework OpenGL -framework AppKit

${NAME}: ${LIBFT} ${OBJ}
	$(CC) ${FLAGS} $(OBJ) ${LIBFT} -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)
#@${CC} ${FLAGS} ${MLX} ${MLX_LIB} ${OBJ}   -o ${NAME}
#	cc $(OBJ)  -o $(NAME)

all: ${NAME}

${LIBFT}:
	@make -C ./libft
	@make -C ./libft clean
	@mv ./libft/libft.a .


clean:
	@rm -f ${OBJ}

fclean: clean
	@rm -f ${NAME}
	@rm -f ${LIBFT}

re: fclean all

COM = "cub3D"
VAR = "pull"
git:
	git add .
	git commit -m ${COM}
	git ${VAR}

#bonus:
