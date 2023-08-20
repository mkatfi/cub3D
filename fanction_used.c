/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fanction_used.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkatfi <mkatfi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 00:20:15 by mkatfi            #+#    #+#             */
/*   Updated: 2023/08/18 00:50:51 by mkatfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"prototypes.h"

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

void	check_cub(char	*str)
{
	int		i;
	char	*s;

	i = 0;
	s = ft_strrchr(str, '.');
	while (str[i])
		i++;
	if (i < 5)
	{
		write(2, "Error\n.cub\n", 11);
		exit(1);
	}
	else if (ft_strchr(str, '.') == 0)
	{
		write(2, "Error\n.cub\n", 11);
		exit(1);
	}
	else if (ft_strcmp(s, ".cub") != 0)
	{
		write(2, "Error\n.cub\n", 11);
		exit(1);
	}
}

void	ft_error(char *a)
{
	write(2, a, ft_strlen(a));
	exit(1);
}