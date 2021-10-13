/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collect_util.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongjki <seongjk@student.42seoul.k>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 16:04:49 by seongjki          #+#    #+#             */
/*   Updated: 2021/10/13 16:35:12 by seongjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_cnt_collectible(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map.row)
	{
		x = 0;
		while (x < game->map.col)
		{
			if (game->map.map[y][x] == 'C')
				game->collect.cnt++;
			x++;
		}
		y++;
	}
}

void	ft_get_collect(t_game *game)
{
	if (game->map.map[game->player.y][game->player.x] == 'C')
	{
		game->map.map[game->player.y][game->player.x] = 'G';
		game->collect.cnt--;
	}
	if (game->collect.cnt == 0)
		game->collect.all_collect_flag = 1;
}

void	ft_escape(t_game *game)
{
	if (game->collect.all_collect_flag == 1)
	{
		if (game->map.map[game->player.y][game->player.x] == 'E')
			exit(0);
	}
}
