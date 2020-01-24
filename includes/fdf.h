/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptruffau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 17:55:59 by ptruffau          #+#    #+#             */
/*   Updated: 2018/10/04 17:56:02 by ptruffau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "libft.h"
# include "mlx.h"

typedef struct s_windows
{
	void	*graph_id;
	void	*windows;
	int		width;
	int		height;
} t_windows;

typedef struct s_map
{
	int		**map;
	int		width;
	int		height;
} t_map;

/*
 * HELPERS
*/
void putmap(t_map *map);


/*
 * parseur.c
*/
int init_map(t_map *map, char *map_file_path);

/*
 * setup.c
*/
void init_windows(t_windows *new);


/*
 * free_struct.c
*/
void free_map(t_map *map);

/*
 * draw
*/
void    draw_pixel(int x, int y, t_windows *window);
void    brensenham(int x1, int y1, int x2, int y2, t_windows *window);
#endif
