/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structuers.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkatfi <mkatfi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 11:04:22 by iantar            #+#    #+#             */
/*   Updated: 2023/08/20 03:14:50 by mkatfi           ###   ########.fr       */
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


typedef struct s_mlx
{
	void	*ptr;
	void	*win;
	void	*img;
	char	*get_adr;
	int		bits_per_pixel;
	int		line_length;
}t_mlx;

// typedef struct s_textures
// {
// 	char	*no;
// 	char	*so;
// 	char	*we;
// 	char	*ea;
// }t_textures;

typedef struct s_color
{
	int	floor;
	int	ceiling;
}t_color;

typedef struct s_data
{
	char	**map;
	int		m_height;
	int		m_witdh;
	t_pos	pos;
	t_mlx	mlx;
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	char 	*floor1;
	char 	*ceiling1;
	char 	**mapm;
	// char 	**mapm2;
	int cout;
	
}t_data;

#endif