/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptruffau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 15:14:23 by ptruffau          #+#    #+#             */
/*   Updated: 2020/01/24 15:14:28 by ptruffau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void    draw_pixel(int x, int y, t_windows *window)
{
    mlx_pixel_put(window->graph_id, window->windows, x, y, 0xE2EDEC);
}

void draw_lines(int i, int j,int x1,int y1, t_windows *win, t_map *data)
{
	int x2;
	int y2;

	x2 = data->margin_left + (i + 1)  * data->dist_pts_x;
	y2 = data->margin_up + (j + 1) * data->dist_pts_y + data->map[i][j + 1] * 10;
	brensenham(x1, y1, x2, y2, win);
}

void	draw_map_pts(t_windows *window, t_map *data)
{
	int i;
	int j;
	int x1;
	int y1;

	i = -1;
	while (++i < data->width)
	{
		j = -1;
		while (++j < data->height)
		{
			x1 = data->margin_left + i  * data->dist_pts_x;
			y1 = data->margin_up + j * data->dist_pts_y + data->map[i][j] * 10;
			draw_pixel(x1 , y1, window);
			draw_lines(i, j, x1, y1, window, data);
		}
	}
}
