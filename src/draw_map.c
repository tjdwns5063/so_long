/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongjki <seongjk@student.42seoul.k>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 13:07:07 by seongjki          #+#    #+#             */
/*   Updated: 2021/10/03 17:37:37 by seongjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	set_img(t_game *game, char spcifir)
{
	int	width;
	int	height;

	if (spcifir == '1')
		game->img = mlx_xpm_file_to_image(game->mlx, "./asset/box.xpm", &width, &height);
	else if (spcifir == 'E')
		game->img = mlx_xpm_file_to_image(game->mlx, "./asset/escape.xpm", &width, &height);
	/*else if (spcifir == 'C')
		game->img = mlx_xpm_file_to_image(game->mlx, "./asset/collect.xpm", &width, &height);*/
}

static void	draw_grass(t_game *game, int x, int y)
{
	int	width;
	int	height;

	game->img = mlx_xpm_file_to_image(game->mlx, "./asset/grass.xpm", &width, &height);
	mlx_put_image_to_window(game->mlx, game->win, game->img, x * SIZE, y * SIZE);
}

static void	draw_map_img(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map.row)
	{
		x = 0;
		while (x < game->map.col)
		{
			draw_grass(game, x, y);
			set_img(game, game->map.map[y][x]);
			mlx_put_image_to_window(game->mlx, game->win, game->img, x * SIZE, y * SIZE);
			x++;
		}
		y++;
	}
}

void	draw_map(t_game *game)
{
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, game->map.col * SIZE, game->map.row * SIZE, "so_long");
	draw_map_img(game);
	set_player(game);
}
