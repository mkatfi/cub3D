/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   duble_chek.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkatfi <mkatfi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 03:35:36 by mkatfi            #+#    #+#             */
/*   Updated: 2023/08/28 03:49:56 by mkatfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"./includes/prototypes.h"

int chek_duple1(char **strs)
{
    int i;
	int j;
	int c;
	int f;

	f = 0;
	c = 0;
	i = -1;
	while(strs && strs[++i])
	{
		j = -1;
		while(strs[i][++j])
        {
            if (strs[i][j] == 'F')
                f++;
            if (strs[i][j] == 'C')
                c++;
        }
	}
    if (c != 1 || f != 1)
		return(1);
	return(0);
}
int chek_duple2(char **strs)
{
    int i;
	int j;
	int e;
	int w;

	e = 0;
	w = 0;
	i = -1;
	while(strs && strs[++i])
	{
		j = -1;
		while(strs[i][++j])
        {
            if (strs[i][j] == 'E' && strs[i][j + 1] == 'A')
                e++;
            if (strs[i][j] == 'W' && strs[i][j + 1] == 'E')
                w++;
        }
	}
    if (e != 1 || w != 1)
		return(1);
	return(0);
}
int chek_duple3(char **strs)
{
	int i;
	int j;
	int n;
	int s;

	n = 0;
	s = 0;
	i = -1;
	while(strs && strs[++i])
	{
		j = -1;
		while(strs[i][++j])
        {
            if (strs[i][j] == 'N' && strs[i][j + 1] == 'O')
                n++;
            if (strs[i][j] == 'S' && strs[i][j + 1] == 'O')
                s++;
        }
	}
	if (n != 1 || s != 1)
		return(1);
	return(0);
}

int chek_duple(char **strs)
{
    if (chek_duple1(strs) == 1)
        return(1);
    if (chek_duple2(strs) == 1)
        return(1);
    if (chek_duple3(strs) == 1)
        return(1);
    return(0);
}
