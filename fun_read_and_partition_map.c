/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fun_read_and_partition_map.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkatfi <mkatfi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 17:53:03 by mkatfi            #+#    #+#             */
/*   Updated: 2023/08/24 18:24:26 by mkatfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"prototypes.h"
#include"math.h"

int  check_chek(char *s)
{
	int	i;
	int c;

	i = 0;
	c = 0;
	while(s[i])
	{
		if (s[i] != '\n')
			c++;
		else if (c == 6)
			return(c);
		i++;
	}
	return(0);
}
int first_line(char *c)
{
	int i;

	i = check_chek(c);
	while(c[i])
	{
		if(c[i] == '1' && c[i + 1] == '\n')
			return(i);
		i++;
	}
	return(0);
}
void check_newline(char *s)
{
	int i;

	i =first_line(s);
	while(s[i])
	{
		if (s[i] == '\n' && s[i + 1] == '\n')
			ft_error("ERROR espace\n");
		i++;
	}
}

char **	git_map(char *srt)
{
	int		fd;
	char *buff;
	char **m;
	
	fd = open(srt, O_RDONLY);
	if (fd == -1)
	{
		write(2, "Error not file\n", 16);
		exit(1);
	}
	if(!(buff = get_next_line(fd)))
		return(NULL);
	m = ft_split(buff, '\n');
	check_newline(buff);
	return(m);
}

void partition_map(char **s, t_data **p)
{
	int i;
	int j;
	int k;
	

	i =0;
	(*p)->mapm = (char **)malloc(sizeof(char*) * 7);
	if (!(*p)->mapm)
	{
		freepath((*p)->mapm);
		ft_error("ERRoR texter not fond\n");
	}
	while (s && s[i] && i < 6)
	{
		(*p)->mapm[i] = s[i];
		i++;
	}
	(*p)->mapm[i] = NULL;
	j = 0;

	k = ft_aray_size(s);
	if (k == 0)
		ft_error("ERROR\n");
	(*p)->map = malloc(sizeof(char *) * ((k - 6) + 1));
	if (!(*p)->map)
	{
		freepath((*p)->map);
		ft_error("ERRoR map not fond\n");
	}
	while (s && s[i])
	{
		(*p)->map[j++] = s[i++];

	}
	(*p)->map[j] = NULL;	
}
