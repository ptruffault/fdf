/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptruffau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 19:00:00 by ptruffau          #+#    #+#             */
/*   Updated: 2020/01/21 19:00:06 by ptruffau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <mlx.h>
#include "fdf.h"

void ft_freeint_arr(int **arr, int y_max){
	int i;

	i = -1;
	while (++i < y_max)
		free(arr[i]);
	free(arr);
}

void free_map(t_map *map)
{
	int i;
	int j;

	i = -1;
	while (++i < map->height)
	{
		j = -1;
		while (++j < map->width)
		{
			free(&map->points[i][j]);
		}
		free(&map->points[i]);
	}
}

