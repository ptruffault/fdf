/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brensenham.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodana <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/31 12:31:08 by yodana            #+#    #+#             */
/*   Updated: 2020/08/31 12:34:00 by yodana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		draw_pixel(int x, int y, t_windows *window, int color)
{
	int pixel;
	int hex;

	hex = color;
	if (window && x >= 0 && y >= 0 && x < window->width && y < window->height)
	{
		pixel = (x * 4) + (4 * window->width * y);
		window->img_str[pixel] = (hex / 64) + 10;
		window->img_str[pixel + 1] = (hex / 32) + 10;
		window->img_str[pixel + 2] = (hex / 16) + 10;
	}
}

static void		go_brensenham(t_bresenham bre, t_windows *win, int inc, int h_v)
{
	int color;
	int median;

	median = (bre.start + bre.stop) / 2;
	color = bre.color_a;
	while (bre.start <= bre.stop)
	{
		if (bre.start > median)
			color = bre.color_b;
		if (h_v == 0)
			draw_pixel(bre.start, bre.p_increm, win, color);
		else
			draw_pixel(bre.p_increm, bre.start, win, color);
		bre.e = bre.e + bre.m;
		if (bre.e >= 0)
		{
			bre.e = bre.e + bre.sub;
			bre.p_increm = bre.p_increm + inc;
		}
		bre.start++;
	}
}

static void		put_bre_for_a(t_point *a, t_point *b, t_bresenham *bre)
{
	if (a->x <= b->x)
	{
		bre->start = a->x;
		bre->stop = b->x;
	}
	else
	{
		bre->start = b->x;
		bre->stop = a->x;
	}
	bre->p_increm = a->y;
	bre->e = -bre->dx;
	bre->m = bre->dy * 2;
	bre->sub = -bre->dx * 2;
}

static void		put_bre_for_b(t_point *a, t_point *b, t_bresenham *bre)
{
	if (a->y <= b->y)
	{
		bre->start = a->y;
		bre->stop = b->y;
	}
	else
	{
		bre->start = b->y;
		bre->stop = a->y;
	}
	bre->p_increm = a->x;
	bre->e = -bre->dy;
	bre->m = bre->dx * 2;
	bre->sub = -bre->dy * 2;
}

void			init_brensenham(t_point *a, t_point *b, t_windows *window)
{
	t_bresenham bre;

	bre.dx = ft_abs(b->x - a->x);
	bre.dy = ft_abs(b->y - a->y);
	bre.color_a = b->color;
	bre.color_b = a->color;
	if (bre.dx >= bre.dy)
	{
		put_bre_for_a(a, b, &bre);
		if (b->y >= a->y)
			go_brensenham(bre, window, 1, 0);
		else
			go_brensenham(bre, window, -1, 0);
	}
	else
	{
		put_bre_for_b(a, b, &bre);
		if (b->x >= a->x)
			go_brensenham(bre, window, 1, 1);
		else
			go_brensenham(bre, window, -1, 1);
	}
}
