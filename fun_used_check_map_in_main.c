/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fun_used_check_map_in_main.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkatfi <mkatfi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 01:52:09 by mkatfi            #+#    #+#             */
/*   Updated: 2023/08/27 18:32:40 by mkatfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include"./includes/prototypes.h"

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
		i++;
	return(i);
}

char chaek_play_used(char **str, int play)
{
	int a;
	int b;
	char k;

	a = -1;
	while (str[++a])
	{
		b = -1;
		while (str[a][++b])
		{
			if (str[a][b] == 'S' || str[a][b] == 'E' ||
				str[a][b] == 'N'|| str[a][b] == 'W')
			{
				play++;
				k = str[a][b];
			}
		}
	}
	if (play != 1)
	{
		ft_error("ERROR one play please\n");
		k = ' ';
	}
	return(k);
}
void check_play(t_data *p)
{
	int a;
	int b;
	int play = 0;
	char k ;

	k = chaek_play_used(p->map, play);
	a = -1;
	while (p->map[++a])
	{
		b = -1;
		while (p->map[a][++b])
		{
			if(p->map[a][b] == 'N' || p->map[a][b] == 'S' || p->map[a][b] == 'W' || p->map[a][b] == 'E') 
				p->player = k;
			else if (p->map[a][b] != '0' && p->map[a][b] != '1' && p->map[a][b] != ' ')
				ft_error("ERROR in map\n");
			else if (k != 32)
				cheack_map(p->map, k);
		}
	}	
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

