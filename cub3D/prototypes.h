/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prototypes.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkatfi <mkatfi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 11:04:19 by iantar            #+#    #+#             */
/*   Updated: 2023/08/20 03:52:56 by mkatfi           ###   ########.fr       */
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
void	*ft_calloc(size_t count, size_t size);
size_t	ft_gstrlen(const char *s);
char	*ft_strjoin(char *s1, char *s2);
// int	ft_strchr(char *str, char c);
char	*ft_read(int fd, char *container);
char	*get_next_line(int fd);

size_t ft_strlen(const char *s);
char	**ft_split(char const *s, char c);
char	*ft_strrchr(char *s, int c);
int     ft_strchr(char *str, char c);
int		ft_strcmp(const char *str1, const char *str2);
void	check_cub(char	*str);
void    ft_error(char *s);
char *long_line(char **str);
int	ft_isalnum(int c);
void	check_play(char **str);
int	ft_sstrchr(char *str);
#endif