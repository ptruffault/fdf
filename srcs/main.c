/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptruffau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 18:44:19 by ptruffau          #+#    #+#             */
/*   Updated: 2020/08/31 13:06:27 by yodana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	argument_checker(int argc, char **argv)
{
	if (argc == 1)
		return (error("No map given",
					"fdf need a map file path as argument."));
	else if (argc > 2)
		warning("Too much argument given",
				"fdf only need one argument: the map file path.");
	else if (!ft_str_endwith(argv[1], ".fdf"))
		return (error("Wrong map format", "fdf need a .fdf map format file."));
	return (1);
}

int			main(int argc, char **argv)
{
	t_map		map;
	t_windows	win;

	if (argument_checker(argc, argv) && init_map(&map, argv[1]))
	{
		init_windows(&win, &map);
		draw_new_map(&win, &map);
		mlx_key_hook(win.windows, ft_event, &win);
		mlx_hook(win.windows, 2, 0, ft_event, &win);
		mlx_loop(win.graph_id);
		free_map(&map);
	}
	else
		return (1);
	return (0);
}
