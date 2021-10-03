/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_player.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongjki <seongjk@student.42seoul.k>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 14:52:06 by seongjki          #+#    #+#             */
/*   Updated: 2021/10/03 17:48:40 by seongjki         ###   ########.fr       */
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

int		ft_key_release(int keycode, t_game *game)
{
	if (keycode == UP)
		game->player.up = 0;
	else if (keycode == DOWN)
		game->player.down = 0;
	else if (keycode == RIGHT)
		game->player.right = 0;
	else if (keycode == LEFT)
		game->player.left = 0;
	return (0);
}

int		main_loop(t_game *game)
{
	//mlx_destroy_image(game->win, game->player.img);
	ft_draw(game);
	//mlx_destroy_image(game->win, game->player.img);
	ft_move(game);
	return (0);	
}

void	init_player(t_game *game)
{
	int	x;
	int	y;
	game->player.img = mlx_xpm_file_to_image(game->mlx, "./asset/man_d0.xpm", &game->player.width, &game->player.height);
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
			}
			x++;
		}
		y++;
	}
}

void	set_player(t_game *game)
{
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, game->map.col * SIZE, game->map.row * SIZE, "so_long");
	init_player(game);
	mlx_hook(game->win, KEYPRESS, 0, ft_key_press, game);
	mlx_hook(game->win, KEYRELEASE, 0, ft_key_release, game);
	mlx_loop_hook(game->mlx, main_loop, game);
}
