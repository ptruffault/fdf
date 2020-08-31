/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptruffau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 17:55:59 by ptruffau          #+#    #+#             */
/*   Updated: 2020/08/31 12:58:22 by yodana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "libft.h"
# include "mlx.h"
# include "math.h"

typedef struct		s_point
{
	int				x;
	int				y;
	int				z;
	int				color;
}					t_point;

typedef struct		s_windows
{
	void			*graph_id;
	void			*windows;
	void			*img_ptr;
	unsigned char	*img_str;
	int				width;
	int				height;
	int				color;
}					t_windows;

typedef struct		s_bresenham
{
	int				dx;
	int				dy;
	int				start;
	int				stop;
	int				p_increm;
	int				e;
	int				m;
	int				sub;
	int				color_a;
	int				color_b;
}					t_bresenham;

typedef struct		s_map
{
	t_point			**points;
	int				width;
	int				height;
	float			angle_x;
	float			angle_y;
	int				pas_xy;
	int				pas_z;
	float			pas_angle;
	int				margin_up;
	int				margin_left;
}					t_map;

void				putmap(t_map *map);
int					max(int a, int b);
int					min(int a, int b);
t_map				*ft_get_set_map(t_map *map);
int					ft_event(int key, t_windows *win);
int					init_map(t_map *map, char *map_file_path);
void				init_pov(t_map *data, t_windows *win);
void				init_windows(t_windows *new, t_map *data);
void				free_map(t_map *map);
void				init_brensenham(t_point *a, t_point *b, t_windows *window);
void				draw_new_map(t_windows *win, t_map *map);

#endif
