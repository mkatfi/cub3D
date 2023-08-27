/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouaziz <aouaziz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 21:48:06 by aouaziz           #+#    #+#             */
/*   Updated: 2023/07/27 14:26:19 by aouaziz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <fcntl.h>
# include <limits.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_free
{
	unsigned long	adres;
	struct s_free	*next;
}					t_free;

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

int					ft_atoi(const char *str);
void				ft_bzero(void *s, size_t n);
void				*ft_calloc(size_t count, size_t size);
int					ft_isalnum(int i);
int					ft_isalpha(int c);
int					ft_isascii(int i);
int					ft_isdigit(int i);
int					ft_isprint(int i);
char				*ft_itoa(int n);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstadd_front(t_list **lst, t_list *new);
t_list				*ft_lstlast(t_list *lst);
int					ft_lstsize(t_list *lst);
t_list				*ft_lstnew(void *content);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memset(void *b, int c, size_t len);
void				ft_putchar_fd(char c, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);
void				ft_putstr_fd(char *s, int fd);
char				**ft_split(char const *s, char c);
char				*ft_strchr(const char *s, int c);
char				*ft_strdup(const char *s1);
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strjoin(char const *s1, char const *s2);
size_t				ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t				ft_strlcat(char *dst, const char *src, size_t dstsize);
int					ft_strlen(const char *s);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strncmp(char *s1, char *s2, size_t n);
char				*ft_strnstr(const char *s, const char *find, size_t len);
char				*ft_strrchr(const char *s, int c);
char				*ft_strtrim(char const *s1, char const *set);
char				*ft_substr(char const *s, unsigned int start, size_t len);
int					ft_tolower(int c);
int					ft_toupper(int c);
char				*get_next_line(int fd);
size_t				get_strlen(const char *s);
char				*get_strchr(char *s, int c);
char				*get_strjoin(char *s1, char *s2);
void				ft_free(char **str);
int					ft_strcmp(char *s1, char *s2);
char				*ft_strncpy(char *dest, const char *src, size_t n);
char				*ft_charjoin(char *s1, char s2);
int					ft_strlen_array(char **array);
int					ft_atoi_color(char *str);
int					ft_color_resolution(char *str);
char				*ft_strcpy(char *s1, const char *s2);
void				ft_print_error(char *str);
char				*ft_cub_strdup(const char *s1, int len);
void				free_double_str(char **str);
void				*ft_malloc(int size);
t_free				*ft_lstnew_free(void *content);
t_free				*ft_lstlast_free(t_free *lst);
void				ft_lstadd_back_free(t_free **lst, t_free *new);
#endif
