/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_strct.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongjki <seongjk@student.42seoul.k>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 18:04:34 by seongjki          #+#    #+#             */
/*   Updated: 2021/10/06 18:43:42 by seongjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	init_img(t_img *img)
{
	img->width = 0;
	img->height = 0;
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

static void	init_player(t_player *player)
{
	player->x = 0;
	player->y = 0;
	player->up = 0;
	player->left = 0;
	player->right = 0;
	player->down = 0;
}

void	init_game(t_game *game)
{
	game->mlx = mlx_init();
}
