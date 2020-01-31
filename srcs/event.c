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

static void rotation_x(int sens, t_windows *win)
{
	t_map *data;

	data = ft_get_set_map(NULL);
	//ft_printf("angle X = %i", data->angle_x);
	data->angle_x += sens;
	data->sens_x = data->angle_x >= 0 ? 1 : -1;
	data->dist_pts_x = (((90 - ft_abs(data->angle_x)) * min(win->width, win->height)) / 100) / max(data->width, data->height);
	mlx_clear_window(win->graph_id, win->windows);
	mlx_destroy_image(win->graph_id, win->img_ptr);
	draw_new_map(win, data);
}

static void rotation_y(int sens, t_windows *win)
{
	t_map *data;

	data = ft_get_set_map(NULL);
	ft_printf("angle Y = %i", data->angle_y);
	if (-90 > data->angle_y && data->angle_y >= 90)
		return;
	
	data->angle_y += sens;
	data->sens_y = data->angle_y >= 0 ? 1 : -1;
	data->dist_pts_y = (((90 - ft_abs(data->angle_y)) * min(win->width, win->height))  / 100) / max(data->width, data->height);
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
