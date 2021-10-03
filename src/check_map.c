/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongjki <seongjk@student.42seoul.k>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 13:05:01 by seongjki          #+#    #+#             */
/*   Updated: 2021/10/02 20:08:24 by seongjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	check_name_extension(char *map_name, t_map *map)
{
	int		cnt;
	char	*name_ptr;
	char	*extension;

	cnt = 4;
	name_ptr = map_name;
	extension = ".ber";
	while (*name_ptr)
		name_ptr++;
	while (cnt--)
		name_ptr--;
	if (ft_strncmp(name_ptr, extension, 4) == 0)
	{
		map->map_name = map_name;
		return (1);
	}
	printf("Invalid File Extension!\n");
	return (0);
}

static int	check_map_is_rec(t_map *map, int fd)
{
	int		tmp_col_idx;
	char	c;

	map->row = 0;
	map->col = 0;
	tmp_col_idx = 0;
	while (read(fd, &c, 1) == 1)
	{
		if (c == '\n')
		{
			map->row++;
			if (map->row > 1 && map->col != tmp_col_idx)
			{
				printf("Map is not Rectangle\n");
				return (0);
			}
			map->col = tmp_col_idx;
			tmp_col_idx = 0;
		}
		else
			tmp_col_idx++;
	}
	return (1);
}

static int	check_element(t_map *map, int fd)
{
	char	buf;
	int		have_e;
	int		have_c;
	int		have_p;

	have_e = 0;
	have_c = 0;
	have_p = 0;
	while (read(fd, &buf, 1) == 1)
	{
		if (buf == 'E')
			have_e = 1;
		else if (buf == 'P')
			have_p = 1;
		else if (buf == 'C')
			have_c = 1;
		if (buf != '0' && buf != '1' && buf != 'E'\
		&& buf != 'P' && buf != 'C' && buf != '\n')
			return (0);
	}
	if (have_e == 1 && have_p == 1 && have_c == 1)
		return (1);
	return (0);
}

static int	check_surrounded_wall(t_map *map, int fd)
{
	int		row_idx;
	int		col_idx;
	char	buf;

	row_idx = 0;
	col_idx = 0;
	fd = open_map(map->map_name);
	while (read(fd, &buf, 1))
	{
		if (buf == '\n')
		{
			row_idx++;
			col_idx = 0;
		}
		else
		{
			if ((row_idx == 0 && buf != '1') || \
			(row_idx == map->row - 1 && buf != '1') || \
			(col_idx == 0 && buf != '1') || \
			(col_idx == map->col - 1 && buf != '1'))
				return (0);
			col_idx++;
		}
	}
	return (1);
}

int	check_map(t_map *map, char *map_name)
{
	int	fd;

	if (check_name_extension(map_name, map) == 0)
		return (0);
	fd = open_map(map_name);
	if (check_map_is_rec(map, fd) == 0)
		return (0);
	close(fd);
	fd = open_map(map_name);
	if (check_element(map, fd) == 0 || check_surrounded_wall(map, fd) == 0)
	{
		printf("Map have Invalid element!\n");
		return (0);
	}
	close(fd);
	return (1);
}
