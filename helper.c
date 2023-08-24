/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkatfi <mkatfi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 16:34:24 by mkatfi            #+#    #+#             */
/*   Updated: 2023/08/21 17:17:33 by mkatfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "prototypes.h"

// int	cheak(char c, char *set)
// {
// 	int	i;

// 	i = 0;
// 	while (set[i])
// 	{
// 		if (set[i] == c)
// 			return (1);
// 		i++;
// 	}
// 	return (0);
// }

// char	*ft_strtrim(char *s1, char *set)
// {
// 	int		i;
// 	int		a;
// 	int		b;
// 	char	*f;

// 	if (!s1)
// 		return (NULL);
// 	a = 0;
// 	while (cheak(s1[a], set) == 1)
// 		a++;
// 	if (!s1[a])
// 		return (ft_strdup(""));
// 	b = ft_strlen(s1);
// 	while (cheak(s1[b - 1], set) == 1)
// 		b--;
// 	f = malloc(sizeof(char) * (b - a) + 1);
// 	if (!f)
// 		return (NULL);
// 	i = 0;
// 	while (s1[a] && a < b)
// 		f[i++] = s1[a++];
// 	f[i] = '\0';
// 	return (f);
// }