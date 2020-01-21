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
			if (!ft_isdigit(file_content[i][j]) && file_content[i][j] != ' ' && file_content[i][j] != '-')
				return (error("Broken map file", ".fdf file is corrupted."));
	}
	map->height = i;
	if (!(map->map = (int **)malloc(sizeof(int *) * map->height)))
		return (error("Allocation failure", NULL));
	return (1);
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
			return (0);
		if (!(map->map[i] = (int *)malloc(sizeof(int) * map->width)))
		{
			ft_freestrarr(words);
			return (0);
		}
		j = -1;
		while (words[++j])
			map->map[i][j] = ft_atoi(words[j]);
		ft_freestrarr(words);
	}
	return (1);
}


int init_map(t_map *map, char *map_file_path){
	char **file_content;
	int fd;

	ft_bzero(map, sizeof(t_map));
	if ((fd = ft_open(map_file_path)) >= 0 && (file_content = ft_get_txt(fd)))
	{
		ft_close(fd);
		if (!map_checker(file_content, map) || !setup_map(map, file_content)){
			ft_freestrarr(file_content);
			return (error("Erreur de formatage du fichier map : ", map_file_path));
		}
		ft_freestrarr(file_content);
	}else
		return(error(strerror(errno) , map_file_path));
	return (1);
}
