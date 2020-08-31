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
#include <math.h>

void init_point(t_map *data, t_point *a, int i,int  j){
	int x;
	int y;

	x = j * data->pas_xy;
	y = i * data->pas_xy;

	//  Vue isometrique! Le trace des ordonées ne s'affiche pas
	//a->x = x * cos(0.523599);
    //a->y = y * sin(0.523599);
	
	 
	a->x = x *cos(data->angle_x) - y * sin(data->angle_y);
	a->y = y *cos(data->angle_x) + x * sin(data->angle_y);

	//a->x = cos(data->angle_x) * x -sin(data->angle_x) * y;
	//a->y = cos(data->angle_x) * data->points[i][j].z * data->pas_z - sin(data->angle_y) * (sin(data->angle_x) * x + cos(data->angle_y));

	a->x +=  data->margin_left;
	a->y += data->margin_up;
	if ((-M_PI / 2 < data->angle_y && data->angle_y < M_PI /2) && data->angle_x != 0){
		a->y -= data->points[i][j].z;
	}else if ((M_PI / 2 + data->pas_angle <= data->angle_y || data->angle_y <= -M_PI / 2 - data->pas_angle) && data->angle_x != 0 ){
		a->y += data->points[i][j].z;
	}
	a->color = data->points[i][j].color;
}

void	draw_map_pts(t_windows *window, t_map *data)
{
	int i;
	int j;
	t_point a;
	t_point b;

	i = -1;
	printf("angle x == %f && angle y == %f\n", data->angle_x, data->angle_y);
	while (++i < data->height)
	{
		j = -1;
		while (++j < data->width)
		{
			init_point(data, &a, i, j);
			if (j != data->width - 1)
			{
				init_point(data, &b, i , j + 1);
				init_brensenham(&a, &b, window);
			}
			if (i != data->height - 1)
			{	
				init_point(data, &b, i + 1 , j);
				init_brensenham(&a, &b, window);
			}
		}
	}
}
 
void	draw_new_map(t_windows *win, t_map *map)
{
	int bpp;
	int s_l;
	int endian;

	win->img_ptr = mlx_new_image(win->graph_id, win->width, win->height);
	win->img_str = (unsigned char*)mlx_get_data_addr(win->img_ptr, &bpp, &s_l, &endian);

	draw_map_pts(win, map);
	mlx_put_image_to_window(win->graph_id, win->windows, win->img_ptr, 0,0);
}

