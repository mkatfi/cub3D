/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prototypes.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkatfi <mkatfi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 11:04:19 by iantar            #+#    #+#             */
/*   Updated: 2023/09/01 15:48:08 by mkatfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTOTYPES_H
# define PROTOTYPES_H

# include <math.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stddef.h>

# include "structuers.h"
# include "macros.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 3
# endif



//parcing

//libft

char	*ft_strrchr(char *s, int c);
int		ft_strchr(char *str, char c);
int		ft_strcmp(const char *str1, const char *str2);
void	ft_error(char *s);
int		ft_strncmp(const char *str1, const char *str2, size_t n);
int		ft_isalnum(int c);
int		ft_isdigit(int c);
//used in split
size_t	ft_strlen(const char *s);
char	**ft_split(char const *s, char c);
char	*ft_strdup(const char	*s1);
//get_next_line
char	*get_next_line(int fd);
void	*ft_calloc(size_t count, size_t size);
size_t	ft_gstrlen(const char *s);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_read(int fd, char *container);

// check
int		check_chek(char *s);
int		first_line(char *c);
int		check_newline(char *s);
char	**git_map(char *srt);
void	partition_map(char **s, t_data **p);
int		check_newline(char *s);
int		long_line(char **str);
int		ft_aray_size(char **s);
int		check_play(t_data *p);
void	check_cub(char	*str);

// void cheack_map(char **str);
int		cheack_map(char **str, char c);
int		plus_espice(t_data *p);
int		rgb(int r, int g, int b);
//check_texer

int		check_txter(char **s);
void	plus_txter_and_fc(t_data *p, t_textures *txt, t_color *g);
int		check_xpm(char	*str);
void	freepath(char **ptr);
int		ft_atoi(const char *str);

#endif