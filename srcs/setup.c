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

void init_windows(t_windows *win, t_map *data)
{
	ft_bzero(win, sizeof(t_windows));
	if (!(win->graph_id = mlx_init()))
		exit(1);
	win->width = 800;
	win->height = 800;
	win->windows = mlx_new_window(win->graph_id , win->width, win->height, "FDF");
	data->angle_y = M_PI / 2;
	data->angle_x = M_PI / 2;
	data->pas_z = 10;
	data->pas_xy = 10;
	data->pas_angle = M_PI / 12;
	data->margin_up = win->height / 2;
	data->margin_left = win->width / 2;
}
