/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongjki <seongjk@student.42seoul.k>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 12:42:02 by seongjki          #+#    #+#             */
/*   Updated: 2021/10/06 18:56:38 by seongjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
/*	for (int i = 0; i < game->map.row; i++)
	{
		for (int j = 0; j < game->map.col; j++)
		{
			printf("%c", game->map.map[i][j]);
		}
		printf("\n");
	}*/
	//mlx_loop(game.mlx);
}
