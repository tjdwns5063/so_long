/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongjki <seongjk@student.42seoul.k>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 13:59:25 by seongjki          #+#    #+#             */
/*   Updated: 2021/10/02 20:08:25 by seongjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	open_map(char *map_name)
{
	int	fd;

	fd = open(map_name, O_RDONLY);
	if (fd < 0)
	{
		printf("Cannot Open This File!\n");
		exit(0);
	}
	return (fd);
}

static int	malloc_map(t_map *map)
{
	int	idx;

	idx = 0;
	map->map = (char **)malloc(sizeof(char *) * (map->row + 1));
	if (!map->map)
	{
		clear_map(map);
		printf("Malloc Error!\n");
		return (0);
	}
	map->map[map->row] = 0;
	while (idx < map->row)
	{
		map->map[idx] = (char *)malloc(sizeof(char) * (map->col + 1));
		if (!map->map[idx])
		{
			clear_map(map);
			printf("Malloc Error!\n");
			return (0);
		}
		idx++;
	}
	return (1);
}

static void	fill_map(t_map *map)
{
	int		fd;
	int		row_idx;
	int		col_idx;
	char	buf;

	fd = open_map(map->map_name);
	row_idx = 0;
	col_idx = 0;
	while (read(fd, &buf, 1) == 1)
	{
		map->map[row_idx][col_idx] = buf;
		if (buf == '\n')
		{
			map->map[row_idx][col_idx] = '\0';
			col_idx = 0;
			row_idx++;
		}
		else
			col_idx++;
	}
}

int	load_map(t_map *map)
{
	char	buf;
	int		row_idx;
	int		col_idx;

	if (!malloc_map(map))
		return (0);
	fill_map(map);
	return (1);
}
