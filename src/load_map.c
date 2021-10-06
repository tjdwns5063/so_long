/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongjki <seongjk@student.42seoul.k>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 13:05:01 by seongjki          #+#    #+#             */
/*   Updated: 2021/10/06 18:56:41 by seongjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	get_row(t_map *map)
{
	int		cnt;
	int		fd;
	char	*line;

	fd = open_map(map->map_name);
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

static int	make_map(t_map *map)
{
	int		idx;
	int		fd;
	char	*line;

	idx = 0;
	fd = open_map(map->map_name);
	map->row = get_row(map);
	map->map = (char **)malloc(sizeof(char *) * (map->row + 1));
	if (!map->map)
	{
		clear_map(map);
		printf("Malloc Error!\n");
		exit(0);
	}
	map->map[map->row] = 0;
	while (idx < map->row)
	{
		get_next_line(fd, &line);
		map->map[idx] = line;
		idx++;
	}
	map->col = ft_strlen(map->map[0]);
	close(fd);
	return (1);
}

void	load_map(t_game *game, char *map_name)
{
	init_map(&game->map);
	check_name_extension(map_name, &game->map);
	game->map.map_name = map_name;
	make_map(&game->map);
	for (int i = 0; i < game->map.row; i++)
	{
		for (int j = 0; j < game->map.col; j++)
		{
			printf("%c", game->map.map[i][j]);
		}
		printf("\n");
	}
	check_map_is_rec(&game->map);
	check_element(&game->map);
	check_surrounded_wall(&game->map);
}
