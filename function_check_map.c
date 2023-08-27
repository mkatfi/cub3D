/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_check_map.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkatfi <mkatfi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 17:01:42 by mkatfi            #+#    #+#             */
/*   Updated: 2023/08/27 16:55:50 by mkatfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"./includes/prototypes.h"

void cheack_map(char **str, char c)
{
	int i;
	int j;
	
	i = 0;
	while(str[i])
	{
		j=0;
		while(str[i][j])
		{
			if (str[i][j] == c)
			{
				if (j >= 0 && (str[i][j + 1] == ' ' || str[i][j - 1] == ' ' ))
					ft_error("Error '0' or player\n");
				else if (i >= 0 && (str[i + 1][j] == ' ' || str[i - 1][j] == ' ' ))
					ft_error("Error '0' or player\n");
			}
			j++;
		}
		i++;
	}
}
void plus_espice_used(t_data *p, int i)
{
	int j;
	char *buffer;

	if (p->m_height < p->m_witdh)
	{	
		buffer = malloc(p->m_witdh + 1);
		j = 0;
		while (p->map[i][j])
		{
			buffer[j] = p->map[i][j];
			j++;
		}
		while (j < p->m_witdh)
		{
			buffer[j] = ' ';
			j++;
		}
		buffer[j] = '\0';
		free(p->map[i]);
		p->map[i] = buffer;
	}
}
void plus_espice(t_data *p)
{
	int i;

	p->m_witdh = long_line(p->map);
	i = 0;
	while(p->map[i])
	{	
		p->m_height = ft_aray_size(p->map);
		plus_espice_used(p, i);
		i++;
	}
	check_play(p);
	cheack_map(p->map, '0');
}
