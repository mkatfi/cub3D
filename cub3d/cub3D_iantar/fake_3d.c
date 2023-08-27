/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fake_3d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iantar <iantar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 11:53:05 by iantar            #+#    #+#             */
/*   Updated: 2023/08/22 11:53:00 by iantar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/includes_iantar.h"
#include "../includes/includes_aouaziz.h"
#include "../includes/structures_iantar.h"
#include "../includes/structures_iantar.h"
#include "../includes/macros.h"

//void    ceiling_ground()
//{

//}

void    fake_3d(t_data *data, double dist, int x)
{
    int line_h;
    int end;
    int y1;
    int y2;

    y1 = 0;
    while (y1 < SCREEN_HEIGHT / 2)
    {
        my_mlx_pixel_put(data, x, y1, rgb_color(0, 139, 139, y1 / 2));
        y1++;
    }
    while (y1 < SCREEN_HEIGHT)
    {
        my_mlx_pixel_put(data, x, y1, rgb_color(218, 165, 32, (SCREEN_HEIGHT - y1) / 2));
        y1++;
    }
    
    if (dist < 1)
        dist = 1;
    line_h = SCREEN_HEIGHT / dist;
    y2 = SCREEN_HEIGHT / 2 - line_h / 2;
    end = SCREEN_HEIGHT / 2 + line_h / 2;
    while (y2 < end)
    {
        my_mlx_pixel_put(data, x, y2, rgb_color(192,192,192, dist * 12));
        y2++;
    }
}