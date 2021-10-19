/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_func_util.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongjki <seongjk@student.42seoul.k>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 17:15:42 by seongjki          #+#    #+#             */
/*   Updated: 2021/10/16 17:43:56 by seongjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	check_element_in_map(t_map *map, char word)
{
	if (word == 'E')
		map->have_e = 1;
	else if (word == 'P')
		map->have_p = 1;
	else if (word == 'C')
		map->have_c = 1;
	else if (word == '1')
		map->have_o = 1;
	else if (word == '0')
		map->have_z = 1;
	else
	{
		printf("Error\nMap have Invalid Element!\n");
		clear_map(map);
		exit(0);
	}
}

int	check_map_is_surrounded(int row, int col, t_map *map)
{
	if (row == 0 && map->map[row][col] != '1')
		return (0);
	else if (row == map->row - 1 && map->map[row][col] != '1')
		return (0);
	else if (col == 0 && map->map[row][col] != '1')
		return (0);
	else if (col == map->col - 1 && map->map[row][col] != '1')
		return (0);
	else
		return (1);
}
