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

void init_windows(t_windows *new)
{
	ft_bzero(new, sizeof(t_windows));
	new->graph_id = mlx_init();
	new->width = 800;
	new->height = 600;
	new->windows = mlx_new_window(new->graph_id , new->width, new->height, "FDF");
}
