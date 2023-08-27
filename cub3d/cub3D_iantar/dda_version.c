/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_version.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iantar <iantar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 12:26:28 by iantar            #+#    #+#             */
/*   Updated: 2023/08/22 08:42:25 by iantar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/includes_iantar.h"
#include "../includes/includes_aouaziz.h"
#include "../includes/structures_iantar.h"
#include "../includes/structures_iantar.h"
#include "../includes/macros.h"
 
double	magnitude(double x, double y)
{
	return (sqrt(x * x + y * y));
}

double	dda_distance(t_data *data, t_pos ray_dir)
{
	double	dx;
	double	dy;
	cor_int	step;
	t_pos	dist;
	int		side;
	cor_int	ray_map;

	dx = magnitude(ray_dir.x, ray_dir.y) / fabs(ray_dir.x);//there is a problem here
	dy = magnitude(ray_dir.x, ray_dir.y) / fabs(ray_dir.y);

	ray_map.x = (int)data->pos.x;
	ray_map.y = (int)data->pos.y;
	if (ray_dir.x > 0)
	{
		step.x = 1;
		dist.x = ((ray_map.x + 1) - data->pos.x) * dx;
	}
	else
	{
		step.x = -1;
		dist.x =  (data->pos.x - ray_map.x) * dx;
	}
	if (ray_dir.y < 0)
	{
		dist.y = (data->pos.y - ray_map.y) * dy;
		step.y = -1;
	}
	else
	{
		dist.y =  ((ray_map.y + 1) - data->pos.y) * dy; 
		step.y = 1;
	}

	while (data->map[ray_map.y][ray_map.x] != '1')//here you must to make sure that x and y are in thier place
	{
		if (dist.x < dist.y)
		{
			dist.x += dx;
			ray_map.x += step.x;
			side = 1;
		}
		else
		{
			dist.y += dy;
			ray_map.y += step.y;
			side = 0;
		}
	}
	if (side)
		return (dist.x - dx);
	return (dist.y - dy);
}

void	dda_version(t_data *data)
{
	double		x;
	double	camera_x;
	double	dda;
	t_pos	ray_dir;	

	x = 0;
	while (x < SCREEN_WIDTH)
	{
		camera_x = (2 * x) / SCREEN_WIDTH - 1;//x-coordinate in camera space
		ray_dir.x = data->dir.x + camera_x * data->plan.x;
		ray_dir.y = data->dir.y + camera_x * data->plan.y;
		dda = dda_distance(data, ray_dir);
		line(data, data->pos.x * GRID, data->pos.y * GRID, atan2(ray_dir.y, ray_dir.x), dda * GRID);
		
		fake_3d(data, dda / magnitude(ray_dir.x, ray_dir.y), x + SCREEN_WIDTH);
		
		x++;
 	}
}
