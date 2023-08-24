/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fanction_used.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkatfi <mkatfi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 00:20:15 by mkatfi            #+#    #+#             */
/*   Updated: 2023/08/24 18:46:02 by mkatfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"prototypes.h"

void check_digit(const char *s)
{
	int i;

	i = 0;
	while(s[i])
	{
		if (ft_isdigit(s[i]) == 0)
			ft_error("ERROR NOT DIGIt\n");
		i++;
	}
}
int	ft_atoi(const char *str)
{
	int	i;
	int	nb;

	i = 0;
	nb = 0;
	while (str[i] == 32)
		i++;
	check_digit(str);
	while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
	{
		nb = (str[i] - 48) + nb * 10;
		i++;
	}
	if (nb >= 0 && nb <= 255)
		return (nb);
	else
	{
		ft_error("ERROR int not valide\n");
		return(0);
	}
		
}

void	freepath(char **ptr)
{
	int	i;

	i = 0;
	while (ptr[i])
	{
		free(ptr[i]);
		i++;
	}
	free(ptr);
}
char	*ft_strrchr(char *s, int c)
{
	int		i;
	char	*k;

	k = (char *)s;
	i = ft_strlen(s);
	while (i >= 0)
	{
		if (k[i] == (char)c)
			return (k + i);
		i--;
	}
	return (NULL);
}

int	ft_strchr(char *str, char c)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		if (str[i++] == c)
			return (1);
	return (0);
}
int	ft_strcmp(const char *str1, const char *str2)
{
	size_t			i;
	unsigned char	*s1;
	unsigned char	*s2;

	s1 = (unsigned char *)str1;
	s2 = (unsigned char *)str2;
	i = 0;
	while ((s1[i] || s2[i]))
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}	
	return (0);
}

void	ft_error(char *a)
{
	write(2, a, ft_strlen(a));
	exit(1);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	a;

	i = 0;
	a = 0;
	while (src[a] != '\0')
		a++;
	if (dstsize != 0)
	{
		while (src[i] != '\0' && i < dstsize - 1)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (a);
}
int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
	{
		return (1);
	}
	return (0);
}
int	ft_isalnum(int c)
{
	if ((c >= '0' && c <= '9')
		|| (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
	{
		return (1);
	}
	return (0);
}


int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	size_t			i;
	unsigned char	*s1;
	unsigned char	*s2;

	s1 = (unsigned char *)str1;
	s2 = (unsigned char *)str2;
	if (n == 0)
		return (0);
	i = 0;
	while ((s1[i] || s2[i]) && i < n)
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}	
	return (0);
}
