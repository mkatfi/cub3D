/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkatfi <mkatfi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 18:27:33 by mkatfi            #+#    #+#             */
/*   Updated: 2023/08/30 17:12:04 by mkatfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/prototypes.h"

int	main(int ac, char **av)
{
	t_data		*p;
	t_textures	*txt;
	t_color		*g;
	char		**map;

	if (ac == 2)
	{
		map = NULL;
		check_cub (av[1]);
		p = malloc(sizeof(t_data));
		txt = malloc(sizeof(t_textures));
		g = malloc(sizeof(t_color));
		map = git_map(av[1]); 
		partition_map(map, &p);
		if (check_txter(map) == 1)
			(freepath(map), ft_error("Error\n"));
		plus_txter_and_fc(p, txt, g);
		if (plus_espice(p) == 1)
			(freepath(p->map), freepath(p->mapm),
				free(p), ft_error("Error\n"));
		(freepath(p->mapm), freepath(p->map), free(g));
		(free(txt), free(p));
	}
	else
		ft_error("ERROR one_arg\n");
}
