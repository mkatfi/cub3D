/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouaziz <aouaziz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 08:18:52 by aouaziz           #+#    #+#             */
/*   Updated: 2023/07/27 14:53:10 by aouaziz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*a;

	a = ft_malloc(count * size);
	if (!a)
		return (0);
	if (count >= SIZE_MAX || size >= SIZE_MAX)
		return (0);
	ft_bzero(a, count * size);
	return (a);
}
