/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parseur.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptruffau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 18:44:01 by ptruffau          #+#    #+#             */
/*   Updated: 2020/01/21 18:44:05 by ptruffau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int map_checker(char **file_content, t_map *map)
{
	int i;
	int j;

	i = -1;
	map->width = ft_count_word(file_content[0]);
	while (file_content[++i])
	{
		if (ft_count_word(file_content[i]) != map->width)
			return (error("Broken map file", "Each line of map as to have the same width"));
		j = -1;
		while (file_content[i][++j])
			if (!ft_isdigit(file_content[i][j]) && !ft_strchr(" -,xABCDEFabcdef", file_content[i][j]))
				return (error("Broken map file", ".fdf file is corrupted."));
	}
	map->height = i;
	map->width--;
	if (!(map->points = (t_point **)malloc(sizeof(t_point) * map->height)))
		return (error("setup_map filure:", "allocation"));
	return (1);
}

static int color_by_alt(int alt)
{
/*	if (alt < -100)
		return ();
	if (-100 <= alt && alt < -50)
		return (0x00004d);
	if (-50 <= alt && alt < -20)
		return (0x000080);
	if (-20 <= alt && alt < -10)
		return (0x0000b3);
	if (-10 <= alt && alt < -1)
		return (0x);
	if (0 <= alt && alt < 10)
		return (0x);
	if (10 <= alt && alt < 20)
		return (0x);
	if (20 <= alt && alt < 50)
		return (0x);
	if (50 <= alt && alt < 100)
		return (0x);*/
	return ((alt * 100) + 1000);

}


static void setup_points_color(t_map *map, char *current_word, int i, int j)
{
	(void)current_word;
	//char *ptr;
	//char *color;

	//ptr = ft_strchr(current_word, ',');
	//color = ft_strdup(ptr ? ptr : color_by_alt(map->points[i][j].z));
	//map->points[i][j].color = ft_atoi_hex(color);
	//ft_strdel(&color);
	map->points[i][j].color = color_by_alt(map->points[i][j].z);
}

static int setup_map(t_map *map, char **file_content)
{
	int		i;
	int		j;
	char 	**words;
	
	i = -1;
	while(file_content[++i])
	{
		if (!(words = ft_strsplit_whitespace(file_content[i])))
			return (error("setup_map filure:", "allocation"));
		if (!(map->points[i] = (t_point *)malloc(sizeof(t_point) * map->width)))
		{
			ft_freestrarr(words);
			return (error("setup_map filure:", "allocation"));
		}
		j = -1;
		while (words[++j])
		{
			map->points[i][j].x = i;
			map->points[i][j].y = j;
			map->points[i][j].z = ft_atoi(words[j]);
			setup_points_color(map, words[j], i, j);
			
		}
		ft_freestrarr(words);
	}
	return (1);
}


int init_map(t_map *map, char *map_file_path)
{
	char **file_content;
	int fd;

	ft_bzero(map, sizeof(t_map));
	if ((fd = ft_open(map_file_path)) >= 0 && (file_content = ft_get_txt(fd)))
	{
		ft_close(fd);
		if (!map_checker(file_content, map) || !setup_map(map, file_content))
		{
			ft_freestrarr(file_content);
			return (error("Erreur de formatage du fichier map : ", map_file_path));
		}
		ft_freestrarr(file_content);
	}
	else
		return(error(strerror(errno) , map_file_path));
	ft_get_set_map(map);
	return (1);
}
