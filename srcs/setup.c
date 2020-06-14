/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptruffau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 18:38:25 by ptruffau          #+#    #+#             */
/*   Updated: 2020/01/21 18:38:30 by ptruffau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"


void init_pov(t_map *data, t_windows *win){
	
	//data->dist_pts_x = (((90 - ft_abs(data->angle_x)) * min(win->width, win->height)) / 100) / max(data->width, data->height);
	//data->dist_pts_y = (((90 - ft_abs(data->angle_y)) * min(win->width, win->height))  / 100) / max(data->width, data->height);

	data->margin_up = (50 * win->height) / 100;
	data->margin_left = (50 * win->width) / 100;
	//data->margin_right = (10 * win->width) / 100;
}


void init_windows(t_windows *win, t_map *data)
{
	ft_bzero(win, sizeof(t_windows));
	if (!(win->graph_id = mlx_init()))
		exit(1);
	win->width = 800;
	win->height = 800;
	win->windows = mlx_new_window(win->graph_id , win->width, win->height, "FDF");
	data->angle_y = 0;
	data->angle_x = 0;
	data->sens_x = 0;
	data->sens_y = 0;
	data->z_multiplicateur = 10;

	data->dist_pts_x = ((ft_abs(data->angle_x) * min(win->width, win->height)) / 100) / max(data->width, data->height);
	data->dist_pts_y = ((ft_abs(data->angle_y) * min(win->width, win->height))  / 100) / max(data->width, data->height);
		ft_printf("SETUP\nangle X = %i | angle Y = %i \ndist per X = %i dist per y = %i\n", data->angle_x, data->angle_y, data->dist_pts_x, data->dist_pts_y);
	init_pov(data, win);

}
