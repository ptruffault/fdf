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
#include <unistd.h>

void    draw_pixel(int x, int y, t_windows *window)
{
    mlx_pixel_put(window->graph_id, window->windows, x, y, window->color);
}

void draw_lines()
{

}





void	draw_map_pts(t_windows *window, t_map *data)
{
	int i;
	int j;
	t_point a;
	t_point b;

	i = -1;
	init_pov(data, window);
	window->color = 0xDC143C;
	while (++i < data->height)
	{
		j = -1;
		while (++j < data->width)
		{
			a.x = data->margin_left + j  * data->dist_pts_x + (data->angle_x == 0 ? 0 : data->points[i][j].z * data->z_multiplicateur);
			a.y = data->margin_up + i * data->dist_pts_y + (data->angle_y == 0 ? 0 : data->points[i][j].z * data->z_multiplicateur);
			a.color = data->points[i][j].color;

			// right line
			if (j != data->width - 1)
			{
				// right
				b.x = data->margin_left + (j + 1) * data->dist_pts_x + (data->angle_x == 0 ? 0 : data->points[i][j + 1].z * data->z_multiplicateur);
				b.y = data->margin_up + i * data->dist_pts_y + (data->angle_y == 0 ? 0 : data->points[i][j + 1].z * data->z_multiplicateur);
				b.color = data->points[i][j + 1].color;
				init_brensenham(&a, &b, window);
			}

			// down line
			if (i != data->height - 1)
			{
				b.x = data->margin_left + j * data->dist_pts_x + (data->angle_x == 0 ? 0 : data->points[i + 1][j].z * data->z_multiplicateur);
				b.y = data->margin_up + (i + 1) * data->dist_pts_y + (data->angle_y == 0 ? 0 : data->points[i + 1][j].z * data->z_multiplicateur);
				b.color = data->points[i + 1][j].color;
				init_brensenham(&a, &b, window);
			}

		}
	}
}
