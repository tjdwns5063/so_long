/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_strct.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongjki <seongjk@student.42seoul.k>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 18:04:34 by seongjki          #+#    #+#             */
/*   Updated: 2021/10/11 16:10:57 by seongjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	init_collect(t_collect *collect)
{
	collect->cnt = 0;
	collect->all_collect_flag = 0;
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
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, game->map.col * SIZE, game->map.row * SIZE, "so_long");
	init_collect(&game->collect);
}
