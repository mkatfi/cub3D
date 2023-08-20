/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkatfi <mkatfi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 18:27:33 by mkatfi            #+#    #+#             */
/*   Updated: 2023/08/20 20:29:32 by mkatfi           ###   ########.fr       */
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
// cheack
// int	ft_isalnum(int c)
// {
// 	if ((c >= '0' && c <= '9')
// 		|| (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
// 	{
// 		return (1);
// 	}
// 	return (0);
// }
// void cheack_valid(t_data *p)
// {
// 	int i =0;
// 	int j;
// 	while(p->mapm[i])
// 	{
// 		if (p->mapm[i	(*p)->map[j++] = s[i++];] == p->no || p->mapm[i] == p->ea ||
// 			p->mapm[i] == p->so || p->mapm[i]==p->we)
// 		{
// 			j=0;
// 			while(p->mapm[i][j])
// 			{
// 				if (ft_isalnum(p->mapm[i][j]) == 0 &&
// 					(!(p->mapm[i][j]== '.' || p->mapm[i][j] == '_' ||
// 						p->mapm[i][j] == '/' || p->mapm[i][j] == 32)))
// 					{
// 						printf("kkkk");
// 						printf("==>%c$$\n", p->mapm[i][j]);
// 					}
// 				j++;
// 			}
// 		}
// 		i++;
// 	}
// }
int ft_aray_size(char **s)
{
	int i;
	
	i=0;
	while(s[i])
		i++;
	return(i);
}

// void cheack_map(t_data *p)
// {
// 	int i;
// 	int j;
	
// 	i = 0;
// 	while(p->map[i])
// 	{
// 		j=0;
// 		while(p->map[i][j])
// 		{
// 			if (p->map[i][j] == '0' && (i == 0  || i == ft_aray_size(p->map) - 1))
// 				ft_error("Error==>1\n");
// 			if (p->map[i][j] == '0' && (j == 0 || p->map[i][j- 1] == ' ' ||
// 				j == ft_strlen(p->map[i]) - 1) || p->map[i][j + 1] == ' ')
// 				ft_error("Error==>2\n");
// 			j++;
// 		}
// 		i++;
// 	}
// }

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
			if (p->map[i][j] == 32 && (i == 0  && p->map[i][j + 1] == '1'))
				ft_error("Error==>1\n");
			if (p->map[i][j] == 32 && (p->map[i][j + 1] == '1' && j == 0 ))
				ft_error("Error==>2\n");
			if(p->map[i][j] == 32 && (p->map[i][j + 1] == '\0' && p->map[i][j + 1] == '1'))
				ft_error("Error==>3\n");
			if (p->map[i][j] == 32 && (p->map[i][j + 1] == '1' && p->map[i] == NULL))
				ft_error("Error==>4\n");
			j++;
		}
		i++;
	}
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	a;

	i = 0;
	a = 0;
	while (src[a] != '\0')
		a++;
	if (dstsize != 0)
	{
		while (src[i] != '\0' && i < dstsize - 1)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (a);
}
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	a;
	size_t	d;
	size_t	s;

	if (dstsize == 0 && !dst)
		return (ft_strlen(src));
	d = ft_strlen(dst);
	s = ft_strlen(src);
	i = ft_strlen(dst);
	a = 0;
	if (dstsize <= d)
		return (s + dstsize);
	while (src[a] && a < dstsize - 1 - d)
	{
		dst[i] = src[a];
		i++;
		a++;
	}
	dst[i] = '\0';
	return (d + s);
}
void plus_espice(t_data *p)
{
	char *buffer;
	int i;
	int j;
	int len;
	size_t size_of_line;

	len = long_line(p->map);
	i = -1;
	while(p->map[++i])
	{
		size_of_line = ft_strlen(p->map[i]);
		if (size_of_line < len)
		{	
			buffer = malloc(len + 1);
			ft_strlcpy(buffer, p->map[0], size_of_line);
			j = -1;
			while (++j < len)
				buffer[j - 1 + size_of_line] = ' ';
			buffer[len] = 0;
			free(p->map[i]);
			p->map[i] = buffer;
		}
	}	
}
int long_line(char **str)
{
	int i;
	int	 m;
	
	i =0;
	m = ft_strlen(str[0]);
	while(str[i])
	{
		if (m < ft_strlen(str[i]))
			m = ft_strlen(str[i]);
		i++;
	}
	return(m);
}

// void check_txter(char **s)
// {
// 	int i = 0;
// 	int j= 0;
// 	int c =0;
// 	while(s && s[i])
// 	{
// 		while(s[i][j])
// 		{
			
// 			if (s[i][j] == 'N' && s[i][j + 1] == 'O')
// 				c++;
// 			else if (s[i][j] == 'S' && s[i][j + 1] == 'O')
// 				c++;
// 			else if (s[i][j] == 'W' && s[i][j + 1] == 'E')
// 				c++;
// 			else if (s[i][j] == 'E' && s[i][j + 1] == 'A')
// 				c++;
// 			else if (s[i][j] == 'C')
// 				c++;
// 			else if (s[i][j] == 'F')
// 				c++;
// 			j++;
// 		}
// 		i++;
// 	}
// 	if (c == 6)
// 		ft_error("error\n");
// }
int	main(int ac, char **av)
{
	t_data	*p;
	int i;
	i =0;
	char**map = NULL;
	p = malloc(sizeof(t_data));
	if (ac == 2)
	{
		check_cub(av[1]);
		map = git_map(av[1]);
		partition_map(map,&p);
		// while(p->map[i])
		// 	printf("%s\n", p->map[i++]);
		//check_txter(map);
		plus_txter_and_fc(p);
		check_play(p->map);
		plus_espice(p);
		cheack_map(p);
		// printf("=>>%d\n",ft_aray_size(p->map));

		
		// printf("**%s**\n", p->ea);
		// printf("**%s**\n", p->we);
		// printf("**%s**\n", p->so);
		// printf("**%s**\n", p->floor1);
		// printf("**%s**\n", p->ceiling1);
	}
}

