/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkatfi <mkatfi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 18:27:33 by mkatfi            #+#    #+#             */
/*   Updated: 2023/08/28 03:52:23 by mkatfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"./includes/prototypes.h"

int	main(int ac, char **av)
{
	t_data	*p;
	t_textures *txt;
	t_color *g;
	char**map = NULL;
	p = malloc(sizeof(t_data));
	txt = malloc(sizeof(t_textures));
	g = malloc(sizeof(t_color));
	if (ac == 2)
	{
		//while(1);
		check_cub(av[1]); // check last file fond << .cub >>
		map = git_map(av[1]); // read map only
		partition_map(map,&p);  // t9ssim map tow part
		check_txter(map);
		plus_txter_and_fc(p, txt, g);
		plus_espice(p);
		freepath(p->mapm);
		freepath(p->map);
		free(p);
		free(g);
		free(txt);
	}
	else
		ft_error("ERROR one_arg\n");
	//system("leaks cub3D");
}

