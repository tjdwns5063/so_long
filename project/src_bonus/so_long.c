/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongjki <seongjk@student.42seoul.k>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 12:42:02 by seongjki          #+#    #+#             */
/*   Updated: 2021/10/19 11:54:57 by seongjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static int	ft_close(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	clear_map(&game->map);
	so_lst_all_clear(&game->collect);
	exit(0);
	return (0);
}

static void	ft_exit(t_game *game)
{
	if (ft_enemy_contact(game) || ft_escape(game))
	{
		clear_map(&game->map);
		so_lst_all_clear(&game->collect);
		exit(0);
	}
	return ;
}

static int	loop_set(t_game *game)
{
	move_loop(game);
	draw_loop(game);
	ft_exit(game);
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
	set_enemy_location(&game);
	ft_find_collect(&game);
	ft_draw(&game);
	mlx_hook(game.win, RED_CROSS, 0, ft_close, &game);
	mlx_hook(game.win, KEY_PRESS, 0, ft_key_press, &game);
	mlx_loop_hook(game.mlx, loop_set, &game);
	mlx_loop(game.mlx);
}
