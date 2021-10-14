/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_player.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongjki <seongjk@student.42seoul.k>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 14:52:06 by seongjki          #+#    #+#             */
/*   Updated: 2021/10/14 15:50:34 by seongjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_count_move(t_game *game, int dir_x, int dir_y)
{
	if (dir_x != 0)
		game->player.x += dir_x;
	else if (dir_y != 0)
		game->player.y += dir_y;
	game->walk++;
	printf("Walk Count: %d\n", game->walk);
}

int	ft_move(t_game *game)
{
	game->player.ex_x = game->player.x;
	game->player.ex_y = game->player.y;
	if (game->player.left == 1 && \
	game->map.map[game->player.y][game->player.x - 1] != '1')
		ft_count_move(game, -1, 0);
	if (game->player.right == 1 && \
	game->map.map[game->player.y][game->player.x + 1] != '1')
		ft_count_move(game, 1, 0);
	if (game->player.up == 1 && \
	game->map.map[game->player.y - 1][game->player.x] != '1')
		ft_count_move(game, 0, -1);
	if (game->player.down == 1 && \
	game->map.map[game->player.y + 1][game->player.x] != '1')
		ft_count_move(game, 0, 1);
	return (0);
}

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
