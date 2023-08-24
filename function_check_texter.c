/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_check_texter.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkatfi <mkatfi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 17:06:32 by mkatfi            #+#    #+#             */
/*   Updated: 2023/08/24 14:47:06 by mkatfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"prototypes.h"

void check_txter(char **s)
{
	char	**strs;
	int i;
	int c;

	i =-1;
	c = 0;
	while(s && s[++i])
	{
		strs = ft_split(s[i], ' ');
		if (ft_aray_size(strs) != 2)
			ft_error("ERROR\ntextur no valid!\n");
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
	if (c != 6 )
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
		exit(1);
	while(s[++i])
		if(s[i] == 32)
			ft_error("ERROR path\n");
}
void check_colors(t_data *p)
{
	char	**strs;
	char	**s;
	int		i;
	int		j;

	i = 0;
	while(p->mapm[i])
	{
		strs = ft_split(p->mapm[i], ' ');
		if (strs[0] && !ft_strcmp(strs[0], "F"))
		{
			s = ft_split(strs[1], ',');
			j = 0;
			while(s[j])
				ft_atoi(s[j++]);
			if (j != 3)
				ft_error("ERROR three number please\n");
		}
		if (strs[0] && !ft_strcmp(strs[0], "C"))
		{
			s = ft_split(strs[1], ',');
			j = 0;
			while(s[j])
				ft_atoi(s[j++]);
			if (j != 3)
				ft_error("ERROR three number please\n");
		}
		i++;
	}
}
void plus_txter_and_fc(t_data *p)
{
	char	**strs;
	int		i;

	i = 0;
	while(p->mapm[i])
	{
		strs = ft_split(p->mapm[i], ' ');
		if (strs[0] && !ft_strcmp(strs[0], "NO"))
		{
			check_xpm(strs[1]);
			p->no = strs[1];
		}
		if (strs[0] && !ft_strcmp(strs[0], "EA"))
		{
			check_xpm(strs[1]);
			p->ea = strs[1];
		}
		if (strs[0] && !ft_strcmp(strs[0], "SO"))
		{
			check_xpm(strs[1]);
			p->so = strs[1];
		}
		if (strs[0] && !ft_strcmp(strs[0], "WE"))
		{
			check_xpm(strs[1]);
			p->we = strs[1];
		}
		freepath(strs);
		i++;
	}
	check_colors(p);
}

