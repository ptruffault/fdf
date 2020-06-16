/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptruffau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 15:22:43 by ptruffau          #+#    #+#             */
/*   Updated: 2020/01/29 15:22:45 by ptruffau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"


static float angle_update(float angle, int sens){
	return (angle +  sens * M_PI / 24);
}

static void rotation_x(int sens, t_windows *win)
{
	t_map *data;

	data = ft_get_set_map(NULL);
	data->angle_x = angle_update(data->angle_x, sens);
	mlx_clear_window(win->graph_id, win->windows);
	mlx_destroy_image(win->graph_id, win->img_ptr);
	draw_new_map(win, data);
}

static void rotation_y(int sens, t_windows *win)
{
	t_map *data;

	data = ft_get_set_map(NULL);
	data->angle_y = angle_update(data->angle_y, sens);
	mlx_clear_window(win->graph_id, win->windows);
	mlx_destroy_image(win->graph_id, win->img_ptr);
	draw_new_map(win, data);
}

static void zoom(int sens, t_windows *win){
	t_map *data;

	data = ft_get_set_map(NULL);
	if (sens > 0)
		data->dist_pts_xy += 5;
	else
		data->dist_pts_xy -= data->dist_pts_xy / 5 ;
	mlx_clear_window(win->graph_id, win->windows);
	mlx_destroy_image(win->graph_id, win->img_ptr);
	draw_new_map(win, data);
}


int	ft_event(int key, t_windows *win)
{
	if(key == 126 || key == 65362)
		rotation_y(-1, win);
	if(key == 125 || key == 65364)
		rotation_y(1, win);
	if(key == 123 || key == 65361)
		rotation_x(1, win);
	if(key == 124 || key == 65363)
		rotation_x(-1, win);
	if(key == 69 || key == 65451)
		zoom(1, win);
	if(key == 78 || key == 65453)
		zoom(-1, win);
	if(key == 53)
	{
		mlx_clear_window(win->graph_id, win->windows);
		mlx_destroy_window(win->graph_id, win->windows);
		exit(0);
	}
	return (0);
}
