/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fun_used_main.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkatfi <mkatfi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 01:52:09 by mkatfi            #+#    #+#             */
/*   Updated: 2023/08/20 01:54:39 by mkatfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include"prototypes.h"

int	ft_isalnum(int c)
{
	if ((c >= '0' && c <= '9')
		|| (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
	{
		return (1);
	}
	return (0);
}

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
			if (str[a][b] == 'S')
				play++;
			else if (str[a][b] == 'E')
				play++;
			else if (str[a][b] == 'N')
				play++;
			else if (str[a][b] == 'O')
				play++;
			else if (str[a][b] != '0' && str[a][b] != '1' && str[a][b] != ' ')
				ft_error("ERROR\n in map");
		}
	}
	if (play != 1)
		ft_error("ERROR\none play please\n");
}
