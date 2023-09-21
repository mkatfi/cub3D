/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkatfi <mkatfi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 13:42:16 by iantar            #+#    #+#             */
/*   Updated: 2023/09/16 20:41:34 by mkatfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/includes_bonus.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || y < 0 || x > SCREEN_WIDTH * 2 || y > SCREEN_HEIGHT)
		return ;
	dst = data->get_adr + (y * data->line_length + x * (data->bits_per_pixel
				/ 8));
	*(unsigned int *)dst = color;
}

void	line(t_data *data, double angle, double len)
{
	double	r;

	r = 0;
	while (r < len)
	{
		my_mlx_pixel_put(data, 50 + r * cos(angle), 50 + r * sin(angle), RED);
		r += 0.1;
	}
}

unsigned int	rgb_color(int r, int g, int b, int density)
{
	r -= density;
	g -= density;
	b -= density;
	if (r < 0)
		r = 0;
	if (g < 0)
		g = 0;
	if (b < 0)
		b = 0;
	return (r << 16 | g << 8 | b);
}

void	render_map(t_data *data)
{
	int			i;
	int			j;
	int			endian;
	static int	check;

	i = 0;
	j = 0;
	if (!check)
	{
		data->img = mlx_new_image(data->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
		data->get_adr = mlx_get_data_addr(data->img, &data->bits_per_pixel,
				&data->line_length, &endian);
	}
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img, 0, 0);
	check = 1;
}
