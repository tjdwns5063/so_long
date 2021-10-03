/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongjki <seongjk@student.42seoul.k>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 15:21:29 by seongjki          #+#    #+#             */
/*   Updated: 2021/10/03 17:24:27 by seongjki         ###   ########.fr       */
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
