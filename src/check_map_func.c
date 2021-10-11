/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_func.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongjki <seongjk@student.42seoul.k>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 16:19:03 by seongjki          #+#    #+#             */
/*   Updated: 2021/10/11 18:00:28 by seongjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_name_extension(char *map_name, t_map *map)
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
	printf("Error!\nInvalid File Extension!\n");
	exit(0);
}

int	check_map_is_rec(t_map *map)
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
			printf("Error!\nMap is Not Rectangle\n");
			clear_map(map);
			exit(0);
		}
		idx++;
	}
	return (1);
}

static void	check_element_util(t_map *map, char word)
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
		printf("Error!\nMap have Invalid Element!\n");
		clear_map(map);
		exit(0);
	}
}

int	check_element(t_map *map)
{
	int		row;
	int		col;

	row = 0;
	while (row < map->row)
	{
		col = 0;
		while (col < map->col)
		{
			check_element_util(map, map->map[row][col]);
			col++;
		}
		row++;
	}
	if (map->have_c != 1 || map->have_p != 1 || map->have_e != 1 \
	|| map->have_o != 1 || map->have_z != 1)
	{
		printf("Error!\nMap have not Essential Element!\n");
		clear_map(map);
		exit(0);
	}
	return (1);
}

int	check_surrounded_wall(t_map *map)
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
			if ((row == 0 && word != '1') || \
			(row == map->row - 1 && word != '1') || \
			(col == 0 && word != '1') || \
			(col == map->col - 1 && word != '1'))
			{
				printf("Error!\nMap is not Surroned by Wall");
				clear_map(map);
				exit(0);
			}
			col++;
		}
		row++;
	}
	return (1);
}
