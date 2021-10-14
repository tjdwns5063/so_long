/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_player.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongjki <seongjk@student.42seoul.k>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 14:52:06 by seongjki          #+#    #+#             */
/*   Updated: 2021/10/14 15:40:01 by seongjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_key_press(int keycode, t_game *game)
{
	if (keycode == ESC)
	{
		mlx_destroy_window(game->mlx, game->win);
		clear_map(&game->map);
		exit(0);
	}
	if (keycode == UP || keycode == W)
		game->player.up = 1;
	if (keycode == DOWN || keycode == S)
		game->player.down = 1;
	if (keycode == RIGHT || keycode == D)
		game->player.right = 1;
	if (keycode == LEFT || keycode == A)
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
				game->player.ex_x = game->player.x;
				game->player.ex_y = game->player.y;
				return ;
			}
			x++;
		}
		y++;
	}
}
