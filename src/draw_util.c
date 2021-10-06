/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongjki <seongjk@student.42seoul.k>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 17:24:34 by seongjki          #+#    #+#             */
/*   Updated: 2021/10/03 19:39:44 by seongjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_img(t_game *game, char spcifir)
{
	int	width;
	int	height;

	if (spcifir == '1')
		game->img = mlx_xpm_file_to_image(game->mlx, "./asset/box.xpm", &width, &height);
	else if (spcifir == 'E')
		game->img = mlx_xpm_file_to_image(game->mlx, "./asset/escape.xpm", &width, &height);
	else if (spcifir == 'C')
		game->img = mlx_xpm_file_to_image(game->mlx, "./asset/collect.xpm", &width, &height);
}

int		ft_move(t_game *game)
{
	if (game->player.left == 1 && game->player.x > 0)
		game->player.x -= 1;
	if (game->player.right == 1 && game->player.x < game->map.col - 1)
		game->player.x += 1;
	if (game->player.up == 1 && game->player.y > 0)
		game->player.y -= 1;
	if (game->player.down == 1 && game->player.y < game->map.row - 1)
		game->player.y += 1;
	return (0);
}

int		ft_draw(t_game *game)
{
	int	x;
	int	y;
	int	height;
	int	width;

	y = 0;
	while (y < game->map.row)
	{
		x = 0;
		while (x < game->map.col)
		{
			game->img = mlx_xpm_file_to_image(game->mlx, "./asset/grass.xpm", &width, &height);
			mlx_put_image_to_window(game->mlx, game->win, game->img, x * SIZE, y * SIZE);
			set_img(game, game->map.map[y][x]);
			mlx_put_image_to_window(game->mlx, game->win, game->img, x * SIZE, y * SIZE);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(game->mlx, game->win, game->player.img, game->player.x * SIZE, game->player.y * SIZE);
	return (0);
}
