/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongjki <seongjk@student.42seoul.k>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 12:42:02 by seongjki          #+#    #+#             */
/*   Updated: 2021/10/02 20:08:21 by seongjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	map_checker(t_game *game, char *map_name)
{
	if (check_map(&game->map, map_name) == 0)
	{
		free(game);
		exit(0);
	}
	if (load_map(&game->map) == 0)
	{
		free(game);
		exit(0);
	}
}

int	main(int ac, char **av)
{
	t_game	*game;

	if (ac != 2)
	{
		printf("Please, Input More Argument!\n");
		exit(0);
	}
	game = (t_game *)malloc(sizeof(t_game));
	if (!game)
	{
		printf("Malloc Error!\n");
		exit(0);
	}
	map_checker(game, av[1]);
	for (int i = 0; i < game->map.row; i++)
	{
		for (int j = 0; j < game->map.col; j++)
		{
			printf("%c", game->map.map[i][j]);
		}
		printf("\n");
	}
}
