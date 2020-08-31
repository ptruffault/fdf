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

static int	map_checker(char **file_content, t_map *map)
{
	int i;
	int j;

	i = -1;
	map->width = ft_count_word(file_content[0]);
	while (file_content[++i])
	{
		if (ft_count_word(file_content[i]) != map->width)
			return (error("Broken map", ".fdf file is corrupted."));
		j = -1;
		while (file_content[i][++j])
			if (!ft_isdigit(file_content[i][j])
			&& !ft_strchr(" -,xABCDEFabcdef", file_content[i][j]))
				return (error("Broken map", ".fdf file is corrupted."));
	}
	map->height = i;

	if (!(map->points = (t_point **)malloc(sizeof(t_point) * map->height)))
		return (error("setup_map filure:", "allocation"));
	return (1);
}

static int	color_by_alt(int alt)
{
	return ((ft_abs(alt) + 5000) * 10000);
}

static void	setup_point(t_map *map, char *word, int i, int j)
{
	char *ptr;

	map->points[i][j].x = i;
	map->points[i][j].y = j;
	map->points[i][j].z = ft_atoi(word);
	if ((ptr = ft_strchr(word, ',')))
		map->points[i][j].color = ft_atoi_hex(ptr + 1);
	else
		map->points[i][j].color = color_by_alt(map->points[i][j].z);
}

static int	setup_map(t_map *map, char **file_content)
{
	int		i;
	int		j;
	char 	**words;
	
	i = -1;
	while(file_content[++i])
	{
		if (!(words = ft_strsplit_whitespace(file_content[i])))
			return (error("setup_map filure:", "allocation"));
		if (!(map->points[i] = (t_point *)malloc(sizeof(t_point) * (map->width + 1))))
		{
			ft_freestrarr(words);
			return (error("setup_map filure:", "allocation"));
		}
		j = -1;
		while (words[++j])
			setup_point(map, words[j], i, j);
		ft_freestrarr(words);
	}
	map->points[i] = NULL;
	putmap(map);
	return (1);
}

int			init_map(t_map *map, char *map_file_path)
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
