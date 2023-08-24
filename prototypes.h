/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prototypes.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkatfi <mkatfi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 11:04:19 by iantar            #+#    #+#             */
/*   Updated: 2023/08/24 03:00:36 by mkatfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTOTYPES_H
# define PROTOTYPES_H

# include <math.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>


# include "structuers.h"
# include "macros.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 3
# endif

// # include "../GNL/get_next_line.h"
//# include "/minilibx-linux/mlx.h"

//parcing

//libft

char	*ft_strrchr(char *s, int c);
int     ft_strchr(char *str, char c);
int		ft_strcmp(const char *str1, const char *str2);
void    ft_error(char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
int     ft_strncmp(const char *str1, const char *str2, size_t n);
int     ft_isalnum(int c);

//used

size_t ft_strlen(const char *s);
char	**ft_split(char const *s, char c);
//get_next_line
char	*get_next_line(int fd);
void	*ft_calloc(size_t count, size_t size);
size_t	ft_gstrlen(const char *s);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_read(int fd, char *container);

// check

int  check_chek(char *s);
int first_line(char *c);
void check_newline(char *s);
char **	git_map(char *srt);
void partition_map(char **s, t_data **p);

int     long_line(char **str);
int     ft_aray_size(char **s);
void	check_play(char **str);
void	check_cub(char	*str);

// void cheack_map(char **str);
void cheack_map(char **str, char c);
void    plus_espice(t_data *p);

//check_texer

void check_txter(char **s);
void plus_txter_and_fc(t_data *p);

void	freepath(char **ptr);
int	ft_atoi(const char *str);
// int	    cheak(char c, char *set);
// char	*ft_strtrim(char *s1, char *set);

#endif