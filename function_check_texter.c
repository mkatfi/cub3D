/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_check_texter.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkatfi <mkatfi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 17:06:32 by mkatfi            #+#    #+#             */
/*   Updated: 2023/08/28 03:36:02 by mkatfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"./includes/prototypes.h"

int rgb(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

void check_txter(char **s)
{
	char	**strs;
	int i;
	int c;

	i =-1;
	c = 0;
	if (chek_duple(s) == 1)
		ft_error("error duple\n");
	while(s && s[++i])
	{
		strs = ft_split(s[i], ' ');
		if (strs[0] && !ft_strcmp(strs[0], "NO"))
			c++;
		if (strs[0] && !ft_strcmp(strs[0], "EA"))
			c++;
		if (strs[0] && !ft_strcmp(strs[0], "SO"))
			c++;
		if (strs[0] && !ft_strcmp(strs[0], "WE"))
			c++;
		if (strs[0] && (!ft_strcmp(strs[0], "F") || !ft_strcmp(strs[0], "C")))
			c++;
		freepath(strs);
	}
	if (c != 6)
		ft_error("ERROR texter\n");
}

void	check_xpm(char	*str)
{
	int		i;
	char	*s;

	i = 0;
	s = ft_strrchr(str, '.');
	while (str[i])
		i++;
	if (i < 5)
		ft_error("Error .xpm\n");
	else if (ft_strchr(str, '.') == 0)
		ft_error("Error .xpm\n");
	else if (ft_strcmp(s, ".xpm") != 0)
		ft_error("Error .xpm\n");
}
void check_path(char *s)
{
	int i;
	int fd;

	i = -1;
	fd = open(s, O_RDONLY);
	if (fd == -1)
		ft_error("Error not file\n");
	while(s[++i])
		if(s[i] == 32)
			ft_error("ERROR path\n");
}
void check_colors(t_data *p, t_color *g)
{
	char	**strs;
	char	**s;
	int		i;
	int		j;

	i = -1;
	while(p->mapm[++i])
	{
		strs = ft_split(p->mapm[i], ' ');
		if (strs[0] && ((!ft_strcmp(strs[0], "F")) ||
			(!ft_strcmp(strs[0], "C"))))
		{
			s = ft_split(strs[1], ',');
			j = 0;
			while(s[j])
				ft_atoi(s[j++]);
			if (j != 3)
				ft_error("ERROR three number please\n");
		}
	}
	if (strs[0] && !ft_strcmp(strs[0], "F"))
		g->floor = rgb(ft_atoi(s[0]), ft_atoi(s[1]), ft_atoi(s[2]));
	if (strs[0] && !ft_strcmp(strs[0], "C"))
		g->ceiling = rgb(ft_atoi(s[0]), ft_atoi(s[1]), ft_atoi(s[2]));
}


void plus_txter_and_used(char **strs, t_textures *txt)
{
	if (ft_aray_size(strs) != 2)
		ft_error("ERROR textur no valid!\n");
	if (strs[0] && !ft_strcmp(strs[0], "NO"))
	{
		check_xpm(strs[1]);
		txt->no = strs[1];
	}
	if (strs[0] && !ft_strcmp(strs[0], "EA"))
	{
		check_xpm(strs[1]);
		txt->ea = strs[1];
	}
	if (strs[0] && !ft_strcmp(strs[0], "SO"))
	{
		check_xpm(strs[1]);
		txt->so = strs[1];
	}
	if (strs[0] && !ft_strcmp(strs[0], "WE"))
	{
		check_xpm(strs[1]);
		txt->we = strs[1];
	}
}
void plus_txter_and_fc(t_data *p, t_textures *txt, t_color *g)
{
	char	**strs;
	int		i;

	i = 0;
	
	while(p->mapm[i])
	{
		strs = ft_split(p->mapm[i], ' ');
		plus_txter_and_used(strs, txt);
		free(strs[0]);
		free(strs);
		i++;
	}
	check_colors(p, g);
}

