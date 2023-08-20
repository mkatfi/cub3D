/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkatfi <mkatfi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 05:03:48 by mkatfi            #+#    #+#             */
/*   Updated: 2023/08/20 05:08:23 by mkatfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include"prototypes.h"

char **	git_map(char *srt)
{
	int		fd;
	char *buff;
	char **m;
	fd = open(srt, O_RDONLY);
	if (fd == -1)
	{
		write(2, "Error\nnot file\n", 16);
		exit(1);
	}
	buff = get_next_line(fd);
	m = ft_split(buff, '\n');
	return(m);
}

void partition_map(char **s, t_data **p)
{
	int i;
	int j;

	i =0;
	(*p)->mapm = (char **)malloc(sizeof(char*) * 7);
	while (s && s[i] && i < 6)
	{
		(*p)->mapm[i] = s[i];
		i++;
	}
	(*p)->mapm[i] = NULL;
	j=0;
	(*p)->map = malloc(sizeof(char *) * ((ft_strlen(*s) - 6) + 1));
	while (s && s[i])
		(*p)->map[j++] = s[i++];
	(*p)->map[j] = NULL;	
}

void plus_txter_and_fc(t_data *p)
{
	int i = 0;
	int j= 0;
	while(p->mapm[i])
	{
		if (p->mapm[i][j] == 'N' && p->mapm[i][j + 1] == 'O')
			p->no = p->mapm[i];
		else if (p->mapm[i][j] == 'S' && p->mapm[i][j + 1] == 'O')
			p->so = p->mapm[i];
		else if (p->mapm[i][j] == 'W' && p->mapm[i][j + 1] == 'E')
			p->we = p->mapm[i];
		else if (p->mapm[i][j] == 'E' && p->mapm[i][j + 1] == 'A')
			p->ea = p->mapm[i];
		else if (p->mapm[i][j] == 'C')
			p->ceiling1 = p->mapm[i];
		else if (p->mapm[i][j] == 'F')
			p->floor1 = p->mapm[i];
		i++;
	}
}

void cheack_map(t_data *p)
{
	int i;
	int j;
	
	i = 0;
	while(p->map[i])
	{
		j=0;
		while(p->map[i][j])
		{
			if (p->map[i][j] == 32 && (i != 0  && p->map[i][j + 1] != '1'))
			{
				printf("here-->>: p->map[i][j]: %c\n", p->map[i][j]);
				ft_error("Error==>1\n");
			}
			if (p->map[i][j] == 32 && (p->map[i][j + 1] != '1' && j != 0 ))
				ft_error("Error==>2\n");
			if(p->map[i][j] == 32 && (p->map[i][j + 1] != '\0' && p->map[i][j + 1] != '1'))
				ft_error("Error==>3\n");
			if (p->map[i][j] == 32 && (p->map[i][j + 1] != '1' && p->map[i] != NULL))
					ft_error("Error==>4\n");
			j++;
		}
		i++;
	}
}

char *long_line(char **str)
{
	int i;
	char *m;
	
	i =0;
	m = str[0];
	while(str[i])
	{
		if (ft_strlen(m) < ft_strlen(str[i]))
			m = str[i];
		i++;
	}
	return(m);
}


int	main(int ac, char **av)
{
	t_data	*p;
	// int i;
	// i =0;
	char**map = NULL;;
	p = malloc(sizeof(t_data));
	if (ac == 2)
	{
		check_cub(av[1]);
		map = git_map(av[1]);
		partition_map(map,&p);
		printf("*******\n");
		// plus_txter_and_fc(p);
		// check_play(p->map);
		// plus_espice(p);?

		// cheack_map(p);
		
		// printf("**%s**\n", p->ea);
		// printf("**%s**\n", p->we);
		// printf("**%s**\n", p->so);
		// printf("**%s**\n", p->floor1);
		// printf("**%s**\n", p->ceiling1);
	}
}

