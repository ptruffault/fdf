/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptruffau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 18:50:39 by ptruffau          #+#    #+#             */
/*   Updated: 2020/01/21 18:50:42 by ptruffau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "fdf.h"

void putmap(t_map *map)
{
	int i;
	int j;

	ft_printf(" xMAX = %i yMAX = %i\n\n", map->width, map->height);
	i = -1;
	while (++i < map->height){
		j = -1;
		while (++j < map->width)
			ft_printf("%3i  ", map->map[i][j]);
		ft_putchar('\n');
	}
}
