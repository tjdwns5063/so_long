/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map_func_util.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongjki <seongjk@student.42seoul.k>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 19:55:52 by seongjki          #+#    #+#             */
/*   Updated: 2021/10/16 19:55:54 by seongjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	open_map(char *map_name)
{
	int	fd;

	fd = open(map_name, O_RDONLY);
	if (fd < 0)
	{
		printf("Error!\nCannot Open This File!\n");
		exit(0);
	}
	return (fd);
}

void	clear_map(t_map *map)
{
	int	idx;

	idx = 0;
	while (idx < map->row)
	{
		free(map->map[idx]);
		idx++;
	}
	free(map->map);
}
