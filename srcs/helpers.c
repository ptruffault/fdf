/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptruffau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 18:50:39 by ptruffau          #+#    #+#             */
/*   Updated: 2020/08/31 12:47:59 by yodana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_map	*ft_get_set_map(t_map *map)
{
	static t_map *s = NULL;

	if (map != NULL)
		s = map;
	return (s);
}

int		min(int a, int b)
{
	return (a < b ? a : b);
}

int		max(int a, int b)
{
	return (a > b ? a : b);
}
