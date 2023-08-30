/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structuers.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkatfi <mkatfi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 11:04:22 by iantar            #+#    #+#             */
/*   Updated: 2023/08/30 15:37:53 by mkatfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTUERS_H
# define STRUCTUERS_H

typedef struct s_pos
{
	float	x;
	float	y;
	char	diraction;
}t_pos;

typedef struct s_map
{
	char	**map;
	int		height;
	int		witdh;
}t_map;

typedef struct s_mlx
{
	void	*ptr;
	void	*win;
	void	*img;
	char	*get_adr;
	int		bits_per_pixel;
	int		line_length;
}t_mlx;

typedef struct s_textures
{
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
}t_textures;

typedef struct s_color
{
	int	floor;
	int	ceiling;
}t_color;

typedef struct s_data
{
	char	**map;
	char	**mapm;
	int		m_height;
	int		m_witdh;
	char	player;
	t_pos	pos;
	t_mlx	mlx;
}t_data;

#endif