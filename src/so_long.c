/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongjki <seongjk@student.42seoul.k>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 12:42:02 by seongjki          #+#    #+#             */
/*   Updated: 2021/10/13 16:35:14 by seongjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_close(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	clear_map(&game->map);
	exit(0);
	return (0);
}

static int	loop_set(t_game *game)
{
	ft_move(game);
	ft_iter_draw(game);
	ft_get_collect(game);
	ft_escape(game);
	init_player(&game->player);
	return (0);
}

int	main(int ac, char **av)
{
	t_game	game;

	if (ac != 2)
	{
		printf("Please, Input More Argument!\n");
		exit(0);
	}
	load_map(&game, av[1]);
	init_game(&game);
	set_player_location(&game);
	ft_cnt_collectible(&game);
	ft_draw(&game);
	mlx_hook(game.win, RED_CROSS, 0, ft_close, &game);
	mlx_hook(game.win, KEY_PRESS, 0, ft_key_press, &game);
	mlx_loop_hook(game.mlx, loop_set, &game);
	mlx_loop(game.mlx);
}
