/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_hooks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iantar <iantar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 08:05:16 by iantar            #+#    #+#             */
/*   Updated: 2023/08/22 10:37:07 by iantar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/includes_iantar.h"
#include "../includes/includes_aouaziz.h"
#include "../includes/structures_iantar.h"
#include "../includes/structures_iantar.h"
#include "../includes/macros.h"

int	close_win(void)
{
	exit(0);
	return (0);
}

int	key_up(int key_code, t_data *data)
{
	if (key_code == W || key_code == S)
	{
		data->input[0] = -1;
	}
	if (key_code == D || key_code == A)
	{
		data->input[1] = -1;
	}
	if (key_code == RIGHT_ARR || key_code == LEFT_ARR)
	{
		data->input[2] = -1;
	}
	return 0;
}	


void	rotate(double *x, double *y, double angle)
{
	double tmp;

	tmp = *x;
	*x = (*x) * cos(angle) - (*y) * sin(angle);
	*y = tmp * sin(angle) + (*y) * cos(angle);
}


int	hit_wall(t_data *data, int key)
{
	int	i;
	t_pos	check;

	i = 0;
	if (key == W)
	{
		check.x = data->pos.x + data->dir.x * SPEED;
		check.y = data->pos.y + data->dir.y * SPEED;
	}
	else if (key == S)
	{
		check.x =  data->pos.x + (-1) *data->dir.x * SPEED;
		check.y = data->pos.y + (-1) * data->dir.y * SPEED;
	}
	else if (key == A)
	{
		check.x =  data->pos.x + data->dir.y * SPEED;
		check.y = data->pos.y + (-1) * data->dir.y * SPEED;
	}
	else if (key == D)
	{
		check.x =  data->pos.x + (-1) * data->dir.y * SPEED;
		check.y = data->pos.y + data->dir.x * SPEED;
	}
	while (i < 2 * PI)
	{
		if (data->map[(int)(check.y + 0.05 * sin(i))][(int)(check.x + 0.05 * cos(i))] == '1')
			return (1);
		i += PI / 3;
	}
	return (0);
}

int	key_press(int key_code, t_data *data)
{
	if (key_code == ESC)
		close_win();
	if (key_code == W || key_code == S)
	{
		data->input[0] = key_code;
	}
	if (key_code == D || key_code == A)
	{
		data->input[1] = key_code;
	}
	if (key_code == RIGHT_ARR || key_code == LEFT_ARR)
	{
		data->input[2] = key_code;
	}
	return 0;
}

int	game_loop(t_data *data)
{
	int	c;

	if (data->input[0] == S && !hit_wall(data, S))
	{
		data->pos.x += (-1) * data->dir.x * SPEED;
		data->pos.y += (-1) * data->dir.y * SPEED;
	}
	if (data->input[0] == W && !hit_wall(data, W))
	{
		data->pos.x += data->dir.x * SPEED;
		data->pos.y += data->dir.y * SPEED;
	}
	if (data->input[1] == A && !hit_wall(data, A))
	{
		data->pos.x += data->dir.y * SPEED;
		data->pos.y += (-1) * data->dir.x * SPEED;
	}
	if (data->input[1] == D && !hit_wall(data, D))
	{
		data->pos.x += (-1) * data->dir.y * SPEED;
		data->pos.y += data->dir.x * SPEED;
	}
	if (data->input[2] == RIGHT_ARR)
	{
		c = 1;
		rotate(&data->dir.x, &data->dir.y, 0.1 * c);
		rotate(&data->plan.x, &data->plan.y, 0.1 * c);
	}
	if (data->input[2] == LEFT_ARR)
	{
		c = -1;
		rotate(&data->dir.x, &data->dir.y, 0.1 * c);
		rotate(&data->plan.x, &data->plan.y, 0.1 * c);
	}
	render_map(data);
	dda_version(data);
	return (0);
}

void	player_hooks(t_data *data)
{
	printf("mlx->map:%p\n", data);
	mlx_hook(data->mlx_win, ON_DESTROY, 1L << 0, close_win, data);
	mlx_hook(data->mlx_win, ON_KEYDOWN, 1L << 0 , key_press, data);
	mlx_hook(data->mlx_win, ON_KEYUP, 1L << 1, key_up, data);
	mlx_loop_hook(data->mlx, game_loop, data);
	mlx_loop(data->mlx);
}
