/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptruffau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 15:22:43 by ptruffau          #+#    #+#             */
/*   Updated: 2020/08/31 13:25:56 by yodana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	update_angle(float x, float y, t_windows *win)
{
	t_map *data;

	data = ft_get_set_map(NULL);
	data->angle_x = x;
	data->angle_y = y;
	mlx_clear_window(win->graph_id, win->windows);
	mlx_destroy_image(win->graph_id, win->img_ptr);
	draw_new_map(win, data);
}

static void	zoom(int sens, t_windows *win)
{
	t_map *data;

	data = ft_get_set_map(NULL);
	if (sens > 0)
		data->pas_xy += 5;
	else
		data->pas_xy -= data->pas_xy / 5;
	mlx_clear_window(win->graph_id, win->windows);
	mlx_destroy_image(win->graph_id, win->img_ptr);
	draw_new_map(win, data);
}

int			ft_event(int key, t_windows *win)
{
	if (key == 18)
		update_angle(0, 0, win);
	if (key == 19)
		update_angle(0.523599, 0.523599, win);
	if (key == 69 || key == 65451)
		zoom(1, win);
	if (key == 78 || key == 65453)
		zoom(-1, win);
	if (key == 53)
	{
		mlx_clear_window(win->graph_id, win->windows);
		mlx_destroy_window(win->graph_id, win->windows);
		exit(0);
	}
	return (0);
}
