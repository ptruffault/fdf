/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptruffau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 18:50:39 by ptruffau          #+#    #+#             */
/*   Updated: 2020/01/31 16:39:06 by yodana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "fdf.h"



t_map *ft_get_set_map(t_map *map)
{
	static t_map *s = NULL;

	if (map != NULL)
		s = map;
	return (s);
}

int min(int a, int b)
{
	return (a < b ? a : b);
}

int max(int a, int b)
{
	return (a > b ? a : b);
}


void putmap(t_map *map)
{
	int i;
	int j;

	ft_printf(" xMAX = %i yMAX = %i\n\n", map->width, map->height);
	i = -1;
	while (++i < map->height){
		j = -1;
		while (++j < map->width)
			ft_printf("%3i  ", map->points[i][j].z);
		ft_putchar('\n');
	}
}
