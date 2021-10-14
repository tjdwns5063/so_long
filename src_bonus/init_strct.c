/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_strct.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongjki <seongjk@student.42seoul.k>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 18:04:34 by seongjki          #+#    #+#             */
/*   Updated: 2021/10/14 18:55:11 by seongjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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

void	init_sprite(t_sprite *sprite)
{
	sprite->path[0] = "./asset/apple_0.xpm";
	sprite->path[1] = "./asset/apple_1.xpm";
	sprite->path[2] = "./asset/apple_2.xpm";
	sprite->path[3] = "./asset/apple_3.xpm";
	sprite->path[4] = "./asset/apple_4.xpm";
	sprite->path[5] = "./asset/apple_5.xpm";
	sprite->path[6] = "./asset/apple_6.xpm";
	sprite->path[7] = "./asset/apple_7.xpm";
	sprite->path[8] = "./asset/apple_8.xpm";
	sprite->path[9] = "./asset/apple_9.xpm";
	sprite->path[10] = "./asset/apple_10.xpm";
	sprite->path[11] = "./asset/apple_11.xpm";
	sprite->path[12] = "./asset/apple_12.xpm";
	sprite->path[13] = "./asset/apple_13.xpm";
	sprite->path[14] = "./asset/apple_14.xpm";
	sprite->path[15] = "./asset/apple_15.xpm";
	sprite->path[16] = "./asset/apple_16.xpm";
}

void	init_game(t_game *game)
{
	t_map	map;

	map = game->map;
	game->mlx = mlx_init();
	ft_mlx_new_window(game, map.col * SIZE, map.row * SIZE);
	game->collect_cnt = 0;
	game->walk = 0;
	game->all_collect_flag = 0;
	init_player(&game->player);
	init_sprite(&game->sprite);
}
