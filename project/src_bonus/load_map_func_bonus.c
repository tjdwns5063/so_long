/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongjki <seongjk@student.42seoul.k>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 13:05:01 by seongjki          #+#    #+#             */
/*   Updated: 2021/10/19 11:03:52 by seongjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static int	get_row(int fd)
{
	int		cnt;
	char	*line;

	cnt = 0;
	while (get_next_line(fd, &line) > 0)
	{
		cnt++;
		free(line);
	}
	free(line);
	close(fd);
	return (cnt);
}

static int	make_map(t_map *map, int fd)
{
	int		idx;
	char	*line;

	idx = 0;
	map->row = get_row(fd);
	map->map = (char **)malloc(sizeof(char *) * (map->row + 1));
	fd = open_map(map->map_name);
	if (!map->map)
		malloc_error(map);
	map->map[map->row] = 0;
	while (idx < map->row)
	{
		if (get_next_line(fd, &line) < 0)
			malloc_error(map);
		map->map[idx] = line;
		idx++;
	}
	map->col = ft_strlen(map->map[0]);
	return (1);
}

static void	show_map(t_map map)
{
	int	x;
	int	y;

	y = 0;
	while (map.map[y])
	{
		x = 0;
		while (map.map[y][x])
		{
			printf("%c", map.map[y][x]);
			x++;
		}
		printf("\n");
		y++;
	}
}

void	load_map(t_game *game, char *map_name)
{
	int	fd;

	init_map(&game->map);
	check_name_extension(map_name, &game->map);
	game->map.map_name = map_name;
	fd = open_map(game->map.map_name);
	make_map(&game->map, fd);
	close(fd);
	show_map(game->map);
	check_map_is_rec(&game->map);
	check_element(&game->map);
	check_surrounded_wall(&game->map);
}
