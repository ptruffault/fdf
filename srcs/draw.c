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
	int x1;
	int y1;
	int x2;
	int y2;

    (void)window;
	i = -1;
	window->color = 0xDC143C;
	while (++i < data->height)
	{
		j = -1;
		while (++j < data->width)
		{
			x1 = data->margin_left + j  * data->dist_pts_x;
			y1 = data->margin_up + i * data->dist_pts_y - data->points[i][j].z * data->z_multiplicateur;
			//draw_pixel(x1 , y1, window);
			
			// right line
			if (j != data->width - 1)
			{
				// right
				x2 = data->margin_left + (j + 1) * data->dist_pts_x;
				//ft_printf("data point = %d", )
				//if (data->points[i][j + 1].z > 0 && data->points[i + 1][j].z > 0)
				//	window->color = 0x00FFFF;
				y2 = data->margin_up + i * data->dist_pts_y - data->points[i][j + 1].z * data->z_multiplicateur;
				init_brensenham(x1, y1, x2, y2, window);
				
				
			}
			

			// down line
			if (i != data->height - 1)
			{
				//if (data->points[i + 1][j].z > 0 && data->points[i][j + 1].z > 0)
				//	window->color = 0x00FFFF;
				x2 = data->margin_left + j * data->dist_pts_x;
				y2 = data->margin_up + (i + 1) * data->dist_pts_y - data->points[i + 1][j].z * data->z_multiplicateur;
				init_brensenham(x1, y1, x2, y2, window);
			}

		}
	}
}
