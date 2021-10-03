/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongjki <seongjk@student.42seoul.k>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 15:21:29 by seongjki          #+#    #+#             */
/*   Updated: 2021/10/02 15:23:15 by seongjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
