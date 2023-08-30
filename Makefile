
NAME = cub3D

SRC = 	main.c \
		get_next_line.c\
		ft_split.c \
		function_libft_used.c \
		function_libft.c \
		fun_read_and_partition_map.c \
		fun_used_check_map_in_main.c \
		function_check_map.c \
		function_check_texter.c \
		fun_check_newline.c \
		check_plus_texter.c 

CC = cc

OBJ = ${SRC:.c=.o}

CFLAGS = -Wextra -Wall -Werror -fsanitize=address -g3

all: ${NAME}

${NAME}: ${OBJ}
	$(CC)  ${CFLAGS}  ${OBJ} -o ${NAME}

clean:
	rm -f ${OBJ}

fclean: clean
	rm -f ${NAME}

re: fclean all