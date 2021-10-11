/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongjki <seongjk@student.42seoul.k>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 12:42:02 by seongjki          #+#    #+#             */
/*   Updated: 2021/10/11 16:42:16 by seongjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	loop_set(t_game *game)
{
	printf("row: %d col: %d\n", game->map.row, game->map.col);
	printf("cnt: %d flag: %d\n", game->collect.cnt, game->collect.all_collect_flag);
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
	mlx_hook(game.win, 2, 0, ft_key_press, &game);
	mlx_loop_hook(game.mlx, loop_set, &game);
	mlx_loop(game.mlx);
}
