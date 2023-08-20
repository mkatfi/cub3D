
NAME = cub3D

SRC = 	main.c \
		get_next_line.c\
		ft_split.c\
		fanction_used.c\
		fun_used_main.c

CC = cc

OBJ = ${SRC:.c=.o}

CFLAGS = -g #-Wextra -Wall -Werror -fsanitize=address -g3

all: ${NAME}

${NAME}: ${OBJ}
	$(CC)  ${CFLAGS}  ${OBJ} -o ${NAME}

clean:
	rm -f ${OBJ}

fclean: clean
	rm -f ${NAME}

re: fclean all