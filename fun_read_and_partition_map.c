/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fun_read_and_partition_map.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkatfi <mkatfi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 17:53:03 by mkatfi            #+#    #+#             */
/*   Updated: 2023/08/27 18:42:07 by mkatfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"./includes/prototypes.h"

int chek_comma(char *s)
{
	int i;
	int k;

	i =0;
	k =0;
	while(s[i])
	{
		if (s[i] == ',')
			k++;
		i++;
	}
	if (k != 4)
		return(1);
	return(0);
}
int  check_chek(char *s)
{
	int i;
	int k;

	i = 0;
	k = 0;
	while(s[i])
	{
		if (s[i] != '\n' && s[i + 1] == '\n')
			k++;
		if (k == 6)
			break;
		i++;
	}
	i++;
	while(s[i])
	{
		if(s[i] == '1')
			return(i);
		i++;
	}
	return(0);
}

int check_newline(char *s)
{
	int i;

	i = check_chek(s);
	if (chek_comma(s) == 1)
		return(2);
	while(s[i])
	{
		if (s[i] == '\n' && s[i + 1] == '\n')
			return (1);
		i++;
	}
	return (0);
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
	buff = get_next_line(fd);
	close(fd);
	if(!buff)
		return(NULL);
	m = ft_split(buff, '\n');
	if (check_newline(buff) == 1)
		(free(buff), ft_error("ERROR espace\n"));
	else if (check_newline(buff) == 2)
		(free(buff), ft_error("ERROR comma\n"));
	return(free(buff), m);
}

void partition_map2(char **s, t_data **p ,int i)
{
	int j;
	int k;

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
		(*p)->map[j++] = s[i++];
	(*p)->map[j] = NULL;
}

void partition_map(char **s, t_data **p)
{
	int i;

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
	partition_map2(s, p ,i);
}
