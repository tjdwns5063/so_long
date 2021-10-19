/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_func.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongjki <seongjk@student.42seoul.k>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 16:19:03 by seongjki          #+#    #+#             */
/*   Updated: 2021/10/19 11:14:05 by seongjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	check_name_extension(char *map_name, t_map *map)
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
		return ;
	}
	printf("Error\nInvalid File Extension!\n");
	exit(0);
}

void	check_map_is_rec(t_map *map)
{
	int	stand_col;
	int	temp_col;
	int	idx;

	idx = 0;
	stand_col = map->col;
	while (idx < map->row)
	{
		temp_col = ft_strlen(map->map[idx]);
		if (stand_col != temp_col)
		{
			printf("Error\nMap is Not Rectangle\n");
			clear_map(map);
			exit(0);
		}
		idx++;
	}
}

void	check_element(t_map *map)
{
	int		row;
	int		col;

	row = 0;
	while (row < map->row)
	{
		col = 0;
		while (col < map->col)
		{
			check_element_in_map(map, map->map[row][col]);
			col++;
		}
		row++;
	}
	if (map->have_c != 1 || map->have_p != 1 || map->have_e != 1 \
	|| map->have_o != 1 || map->have_z != 1)
	{
		printf("Error\nMap have not Essential Element!\n");
		clear_map(map);
		exit(0);
	}
}

void	check_surrounded_wall(t_map *map)
{
	int		row;
	int		col;
	char	word;

	row = 0;
	while (row < map->row)
	{
		col = 0;
		while (col < map->col)
		{
			word = map->map[row][col];
			if (check_map_is_surrounded(row, col, map) == 0)
			{
				printf("Error\nMap is not Surroned by Wall");
				clear_map(map);
				exit(0);
			}
			col++;
		}
		row++;
	}
}
