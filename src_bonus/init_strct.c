/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_strct.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongjki <seongjk@student.42seoul.k>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 18:04:34 by seongjki          #+#    #+#             */
/*   Updated: 2021/10/13 19:54:27 by seongjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	init_collect(t_collect *collect)
{
	collect->cnt = 0;
	collect->all_collect_flag = 0;
	collect->path[0] = "./asset/apple_0.xpm";
	collect->path[1] = "./asset/apple_1.xpm";
	collect->path[2] = "./asset/apple_2.xpm";
	collect->path[3] = "./asset/apple_3.xpm";
	collect->path[4] = "./asset/apple_4.xpm";
	collect->path[5] = "./asset/apple_5.xpm";
	collect->path[6] = "./asset/apple_6.xpm";
	collect->path[7] = "./asset/apple_7.xpm";
	collect->path[8] = "./asset/apple_8.xpm";
	collect->path[9] = "./asset/apple_9.xpm";
}

void	init_map(t_map *map)
{
	map->row = 0;
	map->col = 0;
	map->have_p = 0;
	map->have_e = 0;
	map->have_c = 0;
	map->have_z = 0;
	map->have_o = 0;
}

void	init_player(t_player *player)
{
	player->up = 0;
	player->left = 0;
	player->right = 0;
	player->down = 0;
}

void	init_game(t_game *game)
{
	t_map	map;

	map = game->map;
	game->mlx = mlx_init();
	ft_mlx_new_window(game, map.col * SIZE, map.row * SIZE);
	game->walk = 0;
	init_collect(&game->collect);
}
