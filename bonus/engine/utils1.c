/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkatfi <mkatfi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 20:17:36 by iantar            #+#    #+#             */
/*   Updated: 2023/09/16 20:41:44 by mkatfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/includes_bonus.h"

void	destroy_everything(t_data *data)
{
	freepath(data->map);
	freepath(data->mapm);
	free(data->txt.ea);
	free(data->txt.no);
	free(data->txt.so);
	free(data->txt.we);
}

int	error_mesg(char *msg)
{
	write(2, msg, ft_strlen(msg));
	exit(1);
	return (1);
}
