/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkatfi <mkatfi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 18:27:33 by mkatfi            #+#    #+#             */
/*   Updated: 2023/08/24 16:15:32 by mkatfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"prototypes.h"


int	main(int ac, char **av)
{
	t_data	*p;
	char**map = NULL;
	p = malloc(sizeof(t_data));
	if (ac == 2)
	{
		check_cub(av[1]);
		map = git_map(av[1]); // read map only
		partition_map(map,&p);  // t9ssim map tow part
		check_txter(map);
		// check_texter_valide(p->mapm);
		plus_txter_and_fc(p);
		// check_play(p->map);
		plus_espice(p);
	}
	else
		ft_error("ERROR one_arg\n");
}

