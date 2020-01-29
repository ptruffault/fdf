/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptruffau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 18:44:19 by ptruffau          #+#    #+#             */
/*   Updated: 2020/01/21 18:44:25 by ptruffau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <mlx.h>


int argument_checker(int argc, char **argv)
{
	if (argc == 1)
		return(error("No map given", "fdf need a map file path as argument. This map as to be a .fdf extention file."));
	else if (argc > 2)
		warning("Too much argument given", "fdf only need one argument: the map file path. This map as to be a .fdf extention file.");
	else if (!ft_str_endwith(argv[1], ".fdf"))
		return (error("Wrong map format", "fdf requiere a .fdf map format file."));
	return (1);
}

int	ft_event(int key, t_windows *win)
{
	//key = 2;
	//mlx_clear_window(win->windows, win->graph_id);
	ft_printf("key == %d\n", key);
	if (key == 126) // UP
	{
		mlx_clear_window(win->graph_id, win->windows);
		
		ft_printf("UP\n");
	}	
	if (key == 125) // DOWN
	{
		ft_printf("down\n");
	}
	if (key == 53)
	{
		//mlx_clear_window(win->graph_id, win->windows);
		mlx_destroy_window(win->graph_id, win->windows);
		//exit(0);
	}
	return (0);
}

int main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	t_map map;
	t_windows win;
	
	if (argument_checker(argc, argv) && init_map(&map, argv[1]))
	{
		putmap(&map);
		init_windows(&win, &map);
		draw_map_pts(&win, &map);
		mlx_key_hook(win.windows, ft_event, &win);
		//mlx_hook(win.windows, 2, 0, ft_close_win, &win);
		mlx_loop(win.graph_id);
		free_map(&map);
	}
	else
		return (1);
	return (0);
}
	
