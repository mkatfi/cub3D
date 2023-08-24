/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_check_map.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkatfi <mkatfi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 17:01:42 by mkatfi            #+#    #+#             */
/*   Updated: 2023/08/23 15:12:59 by mkatfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"prototypes.h"

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
					ft_error("Error '0'\n");
				else if (i >= 0 && (str[i + 1][j] == ' ' || str[i - 1][j] == ' ' ))
					ft_error("Error '0'\n");
			}
			j++;
		}
		i++;
	}
}
// void cheack_map(char **str, char c)
// {
// 	int i;
// 	int j;
	
// 	i = 0;
// 	while(str[i])
// 	{
// 		j=0;
// 		while(str[i][j])
// 		{
// 			if (str[i][j]  == c)
// 			{
// 				if (str[i][j] == 32 && (i != 0  && str[i][j + 1] != '1'))
// 				{
// 					printf("here-->>: str[i][j]: %c\n", str[i][j]);
// 					ft_error("Error==>1\n");
// 				}
// 				if (str[i][j] == 32 && (str[i][j + 1] != '1' && j != 0 ))
// 					ft_error("Error==>2\n");
// 				if(str[i][j] == 32 && (str[i][j + 1] != '\0' && str[i][j + 1] != '1'))
// 					ft_error("Error==>3\n");
// 				if (str[i][j] == 32 && (str[i][j + 1] != '1' && str[i] != NULL))
// 							ft_error("Error==>4\n");
// 				}
// 			j++;
// 		}
// 		i++;
// 	}
// }
void plus_espice(t_data *p)
{
	char *buffer;
	int i;
	int j;
	int len;
	int size_of_line;
	len = long_line(p->map);
	i = 0;
	while(p->map[i])
	{	
		size_of_line = ft_strlen(p->map[i]);
		if (size_of_line < len)
		{	
			buffer = malloc(len + 1);
			j = 0;
			while (p->map[i][j])
			{
				buffer[j] = p->map[i][j];
				j++;
			}
			while (j < len)
			{
				buffer[j] = ' ';
				j++;
			}
			buffer[j] = '\0';
			free(p->map[i]);
			p->map[i] = buffer;
		}
		i++;
	}
	// i= 0;
	// while (p->map[i])
	// {
	// 	printf("%s\n", p->map[i++]);
	// }
	check_play(p->map);
	cheack_map(p->map, '0');
}
