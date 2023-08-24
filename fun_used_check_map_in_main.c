/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fun_used_check_map_in_main.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkatfi <mkatfi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 01:52:09 by mkatfi            #+#    #+#             */
/*   Updated: 2023/08/23 21:32:22 by mkatfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include"prototypes.h"

int long_line(char **str)
{
	int i;
	size_t m;
	
	i =0;
	m = ft_strlen(str[0]);
	while(str[i])
	{
		if (m < ft_strlen(str[i]))
			m = ft_strlen(str[i]);
		i++;
	}
	return(m);
}

int ft_aray_size(char **s)
{
	int i;
	
	i=0;
	while(s[i])
	{
		// printf("s[%d] = %s\n", i, s[i]);
		i++;
	}
	return(i);
}

// void chek_play1(char **str, int play, int a, int b)
// {
	
// }

void	check_play(char **str)
{
	int a;
	int b;
	int play = 0;

	a = -1;
	while (str[++a])
	{
		b = -1;
		while (str[a][++b])
		{
			if (str[a][b] == 'S' )
		{
			play++;
			cheack_map(str, 'S');
		}
		else if (str[a][b] == 'E')
		{
			play++;
			cheack_map(str, 'E');	
		}
		else if (str[a][b] == 'N')
		{
			play++;
			cheack_map(str, 'N');
		}
		else if (str[a][b] == 'W')
		{
			play++;
			cheack_map(str, 'W');
		}
		else if (str[a][b] != '0' && str[a][b] != '1' && str[a][b] != ' ')
			ft_error("ERROR in map\n");
			}
	}
	if (play != 1)
		ft_error("ERROR one play please\n");
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
		ft_error("Error .cub\n");
	else if (ft_strchr(str, '.') == 0)
		ft_error("Error .cub\n");
	else if (ft_strcmp(s, ".cub") != 0)
		ft_error("Error .cub\n");
}

