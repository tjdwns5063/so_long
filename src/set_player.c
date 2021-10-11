/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_player.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongjki <seongjk@student.42seoul.k>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 14:52:06 by seongjki          #+#    #+#             */
/*   Updated: 2021/10/11 14:51:26 by seongjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int		ft_key_press(int keycode, t_game *game)
{
	if (keycode == ESC)
	{
		mlx_destroy_window(game->mlx, game->win);
		exit(0);
	}
	if (keycode == UP)
		game->player.up = 1;
	else if (keycode == DOWN)
		game->player.down = 1;
	else if (keycode == RIGHT)
		game->player.right = 1;
	else if (keycode == LEFT)
		game->player.left = 1;
	return (0);
}

void	set_player_location(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map.row)
	{
		x = 0;
		while (x < game->map.col)
		{
			if (game->map.map[y][x] == 'P')
			{
				game->player.x = x;
				game->player.y = y;
				game->player.ex_x = x;
				game->player.ex_y = y;
			}
			x++;
		}
		y++;
	}
}
