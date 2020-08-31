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

void	init_windows(t_windows *w, t_map *data)
{
	int ratio;

	ft_bzero(w, sizeof(t_windows));
	if (!(w->graph_id = mlx_init()))
		exit(1);
	ratio = max(data->width, data->height) / min(data->width, data->height);
	data->pas_xy = ratio * 5;
	if (data->width < 30 || data->height < 30)
		data->pas_xy = 15;
	data->angle_y = 0;
	data->angle_x = 0;
	data->pas_z = 10;
	w->width = data->pas_xy * data->width;
	w->height = data->pas_xy * data->height;
	data->margin_up = w->height / 3;
	data->margin_left = w->width / 3;
	w->width += 2 * w->width / 3;
	w->height += 2 * w->height / 3;
	w->windows = mlx_new_window(w->graph_id, w->width, w->height, "FDF");
}
