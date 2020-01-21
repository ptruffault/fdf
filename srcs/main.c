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

int main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	t_map map;
	t_windows win;
	
	if (argument_checker(argc, argv) && init_map(&map, argv[1]))
	{
		putmap(&map);
		init_windows(&win);
		mlx_loop(win.graph_id);
		free_map(&map);
	}else
		return (1);
	return (0);
}
	
