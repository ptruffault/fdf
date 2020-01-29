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

#include <mlx.h>
#include "fdf.h"


void init_pov(t_map *data, t_windows *win){
	data->dist_pts_x = (((90 - ft_abs(data->angle_x)) * min(win->width, win->height)) / 100) / max(data->width, data->height);
	data->dist_pts_y = (((90 - ft_abs(data->angle_y)) * min(win->width, win->height))  / 100) / max(data->width, data->height);
	data->z_multiplicateur = data->angle_y >= 0 ? -5 : 5;
	data->margin_up = (win->height - data->dist_pts_y * data->height) / 2;
	//data->margin_down = (10 * win->height) / 100;
	data->margin_left = (win->width - data->dist_pts_x * data->width) / 2;;
	//data->margin_right = (10 * win->width) / 100;
}


void init_windows(t_windows *new, t_map *data)
{
	ft_bzero(new, sizeof(t_windows));
	new->graph_id = mlx_init();
	new->width = 1800;
	new->height = 1200;
	new->windows = mlx_new_window(new->graph_id , new->width, new->height, "FDF");
	data->angle_y = 0;
	data->angle_x = 0;
	data->angle_z = 0;
	init_pov(data, new);
}
