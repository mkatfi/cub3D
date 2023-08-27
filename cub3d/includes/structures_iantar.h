/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures_iantar.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iantar <iantar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 11:05:23 by iantar            #+#    #+#             */
/*   Updated: 2023/08/17 11:17:20 by iantar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_IANTAR_H
# define STRUCTURES_IANTAR_H

typedef struct s_dir
{
	double	x;
	double	y;
	double	angle;
}					t_dir;

typedef struct s_pos
{
	double	x;
	double	y;
}					t_pos;

typedef struct s_coor_int
{
	int	x;
	int	y;
}					cor_int;

typedef struct s_plan
{
	double	x;
	double	y;
}					t_plan;

typedef struct s_data
{
	void	*mlx;
	void	*mlx_win;
	char	**map;
	void	*img;
	char	*get_adr;
	int		bits_per_pixel;
	int		line_length;
	int		m_width;
	int		m_height;
	double	k;
	double	v_angle;
	double	dist;
	t_pos	pos;
	t_dir	dir;
	t_plan	plan;
	//cor_int	ray_map;
	//t_pos	rayDir;
	int		input[3];
}					t_data;


#endif