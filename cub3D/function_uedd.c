/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_uedd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkatfi <mkatfi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 01:48:56 by mkatfi            #+#    #+#             */
/*   Updated: 2023/08/20 01:51:18 by mkatfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//libft

// int	ft_strlen(char *str)
// {
// 	char	*ptr;

// 	ptr = str;
// 	while (str && *str)
// 		str++;
// 	return (str - ptr);
// }

//fin_libft


// void	checkn(t_so *p)
// {
// 	int	i;
// 	char *buff;

// 	i = 0;
// 	while (buff[i])
// 	{
// 		if (buff[i] == '\n' && buff[i + 1] == '\n')
// 		{
// 			write(2, "Error\n", 6);
// 			exit(1);
// 		}
// 		else if (buff[i] == '\n' && buff[i + 1] == '\0')
// 		{
// 			write(2, "Error\n", 6);
// 			exit(1);
// 		}
// 		else if (buff[0] == '\n')
// 		{
// 			write(2, "Error\n", 6);
// 			exit(1);
// 		}
// 		i++;
// 	}
// }
// 111111111111111
/*
void	check_1(char **map)
{
	int	i;
	int	len;

	len = 0;
	while (map[len])
		len++;
	i = 0;
	while (map[0][i] && map[len - 1][i])
	{
		if (map[0][i] != '1' || map[len - 1][i] != '1')
		{void	check_play(char **str)
// {
// 	int a;
// 	int b;
// 	int play = 0;

// 	a = -1;
// 	while (str[++a])
// 	{
// 		b = -1;
// 		while (str[a][++b])
// 		{
// 			if (str[a][b] == 'S')
// 				play++;
// 			else if (str[a][b] == 'E')
// 				play++;
// 			else if (str[a][b] == 'N')
// 				play++;
// 			else if (str[a][b] == 'O')
// 				play++;
// 			else if (str[a][b] != '0' && str[a][b] != '1')
// 			{
// 				write (2, "Error\nUtil\n", 11);
// 				exit(1);
// 			}
// 		}
// 	}
// 	if (play != 1)
// 	{
// 		write (2, "Error\nUtil\n", 11);
// 		exit(1);
// 	}
// }
			write(1, "Error\nUpDown\n", 13);
			exit(1);void	check_play(char **str)
// {
// 	int a;
// 	int b;
// 	int play = 0;

// 	a = -1;
// 	while (str[++a])
// 	{
// 		b = -1;
// 		while (str[a][++b])
// 		{
// 			if (str[a][b] == 'S')
// 				play++;
// 			else if (str[a][b] == 'E')
// 				play++;
// 			else if (str[a][b] == 'N')
// 				play++;
// 			else if (str[a][b] == 'O')
// 				play++;
// 			else if (str[a][b] != '0' && str[a][b] != '1')
// 			{
// 				write (2, "Error\nUtil\n", 11);
// 				exit(1);
// 			}
// 		}00011
10000
// 	}
// 	if (play != 1)
// 	{
// 		write (2, "Error\nUtil\n", 11);
// 		exit(1);
// 	}
// }
		}
		i++;
	}
	check_2(map);
}

void	check_2(char **map)
{00011
10000
	int	i;

	i = 0;
	while (map[i])
	{
		if (map[i][0] != '1' || map[i][ft_strlen(map[i]) - 1] != '1')
		{
			write(1, "Error\nRiLif\n", 12);
			exit(1);
		}void	check_play(char **str)
// {
// 	int a;
// 	int b;
// 	int play = 0;

// 	a = -1;
// 	while (str[++a])
// 	{
// 		b = -1;
// 		while (str[a][++b])
// 		{
// 			if (str[a][b] == 'S')
// 				play++;
// 			else if (str[a][b] == 'E')
// 				play++;
// 			else if (str[a][b] == 'N')
// 				play++;
// 			else if (str[a][b] == 'O')
// 				play++;
// 			else if (str[a][b] != '0' && str[a][b] != '1')
// 			{
// 				write (2, "Error\nUtil\n", 11);
// 				exit(1);
// 			}
// 		}
// 	}
// 	if (play != 1)
// 	{
// 		write (2, "Error\nUtil\void	check_play(char **str)
// {
// 	int a;
// 	int b;
// 	int play = 0;

// 	a = -1;
// 	while (str[++a])
// 	{
// 		b = -1;
// 		while (str[a][++b])
// 		{
// 			if (str[a][b] == 'S')
// 				play++;
// 			else if (str[a][b] == 'E')
// 				play++;
// 			else if (str[a][b] == 'N')
// 				play++;
// 			else if (str[a][b] == 'O')
// 				play++;
// 			else if (str[a][b] != '0' && str[a][b] != '1')
// 			{
// 				write (2, "Error\nUtil\n", 11);
// 				exit(1);
// 			}
// 		}
// 	}
// 	if (play != 1)
// 	{00011
10000
// 		write (2, "Error\nUtil\n", 11);
// 		exit(1);
// 	}
// }n", 11);
// 		exit(1);
// 	}
// }
		i++;
	}
}*/



// char **plus_espice(t_data *p)
// {
// 	int i;
// 	int j;
// 	int len;
// 	char **str;

// 	str = (char **)malloc(sizeof(char*) * 7);
// 	 i=0;
// 	len = ft_strlen(long_line(p->map));
// 	char 
	
// 	printf("%d\n", len);
// 	while (p->map[i])
// 	{		
// 		i++;
// 	 }
// 	 i=0;
// 	 while(str[i])
// 	 	printf("%s\n", str[i++]);
// 	 return(str);
// }
// fin_cheak

// void cheack_valid(t_data *p)
// {
// 	int i =0;
// 	int j;
// 	while(p->mapm[i])
// 	{
// 		if (p->mapm[i] == p->no || p->mapm[i] == p->ea ||
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