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


static int angle_update(int angle)
{
	if (angle >= 360)
		return (360 - angle);
	if (angle <= -360)
		return (ft_abs(angle + 360));
	return (angle);
}

static void rotation_x(int sens, t_windows *win)
{
	t_map *data;

	data = ft_get_set_map(NULL);
	data->angle_x = angle_update(data->angle_x + sens);
	mlx_clear_window(win->graph_id, win->windows);
	mlx_destroy_image(win->graph_id, win->img_ptr);
	draw_new_map(win, data);
}

static void rotation_y(int sens, t_windows *win)
{
	t_map *data;

	data = ft_get_set_map(NULL);
	data->angle_y = angle_update(data->angle_y  + sens);
	mlx_clear_window(win->graph_id, win->windows);
	mlx_destroy_image(win->graph_id, win->img_ptr);
	draw_new_map(win, data);
}

static void zoom(int sens, t_windows *win){
	t_map *data;

	data = ft_get_set_map(NULL);
	data->dist_pts_x += sens;
	data->dist_pts_y += sens;
	mlx_clear_window(win->graph_id, win->windows);
	mlx_destroy_image(win->graph_id, win->img_ptr);
	draw_new_map(win, data);
}


int	ft_event(int key, t_windows *win)
{
	//key = 2;
	//mlx_clear_window(win->windows, win->graph_id);
	ft_printf("key == %d\n", key);
	if (key == 126)
		rotation_y(-10, win);
	if (key == 125)
		rotation_y(10, win);
	if (key == 123)
		rotation_x(10, win);
	if (key == 124)
		rotation_x(-10, win);
	if (key == 69)
		zoom(1, win);
	if (key == 78)
		zoom(-1, win);


	if (key == 53)
	{
		mlx_clear_window(win->graph_id, win->windows);
		mlx_destroy_window(win->graph_id, win->windows);
		exit(0);
	}
	return (0);
}
