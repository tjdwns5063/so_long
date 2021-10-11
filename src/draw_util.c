/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongjki <seongjk@student.42seoul.k>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 17:24:34 by seongjki          #+#    #+#             */
/*   Updated: 2021/10/11 19:53:39 by seongjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_img(t_game *game, char spcifir)
{
	if (spcifir == '1')
		game->img.path = "./asset/box.xpm";
	else if (spcifir == 'E')
		game->img.path = "./asset/escape.xpm";
	else if (spcifir == 'C')
		game->img.path = "./asset/collect.xpm";
	else
		game->img.path = "./asset/grass.xpm";
	game->img.img = mlx_xpm_file_to_image(game->mlx, game->img.path, &game->img.width, &game->img.height);
}

int		ft_move(t_game *game)
{
	game->player.ex_x = game->player.x;
	game->player.ex_y = game->player.y;
	if (game->player.left == 1 && game->map.map[game->player.y][game->player.x - 1] != '1')
	{
		game->player.x -= 1;
		game->walk += 1;
		printf("Walk Count: %d\n", game->walk);
	}
	if (game->player.right == 1 && game->map.map[game->player.y][game->player.x + 1] != '1')
	{
		game->player.x += 1;
		game->walk += 1;
		printf("Walk Count: %d\n", game->walk);
	}
	if (game->player.up == 1 && game->map.map[game->player.y - 1][game->player.x] != '1')
	{
		game->player.y -= 1;
		game->walk += 1;
		printf("Walk Count: %d\n", game->walk);
	}
	if (game->player.down == 1 && game->map.map[game->player.y + 1][game->player.x] != '1')
	{
		game->player.y += 1;
		game->walk += 1;
		printf("Walk Count: %d\n", game->walk);
	}
	return (0);
}

int		ft_draw(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map.row)
	{
		x = 0;
		while (x < game->map.col)
		{
			game->img.img = mlx_xpm_file_to_image(game->mlx, "./asset/grass.xpm", &game->img.width, &game->img.height);
			mlx_put_image_to_window(game->mlx, game->win, game->img.img, x * SIZE, y * SIZE);
			set_img(game, game->map.map[y][x]);
			mlx_put_image_to_window(game->mlx, game->win, game->img.img, x * SIZE, y * SIZE);
			x++;
		}
		y++;
	}
	game->img.img = mlx_xpm_file_to_image(game->mlx, "./asset/man_d0.xpm", &game->img.width, &game->img.height);
	mlx_put_image_to_window(game->mlx, game->win, game->img.img, game->player.x * SIZE, game->player.y * SIZE);
	return (0);
}

int		ft_iter_draw(t_game *game)
{
	if (game->map.map[game->player.y][game->player.x] == 'C')
	{
		game->img.img = mlx_xpm_file_to_image(game->mlx, "./asset/grass.xpm", &game->img.width, &game->img.height);
		mlx_put_image_to_window(game->mlx, game->win, game->img.img, game->player.x * SIZE, game->player.y * SIZE);
	}
	game->img.img = mlx_xpm_file_to_image(game->mlx, "./asset/man_d0.xpm", &game->img.width, &game->img.height);
	mlx_put_image_to_window(game->mlx, game->win, game->img.img, game->player.x * SIZE, game->player.y * SIZE);

	if (game->player.x != game->player.ex_x || game->player.y != game->player.ex_y)
	{
		set_img(game, game->map.map[game->player.ex_y][game->player.ex_x]);
		mlx_put_image_to_window(game->mlx, game->win, game->img.img, game->player.ex_x * SIZE, game->player.ex_y * SIZE);
		if (game->map.map[game->player.ex_y][game->player.ex_x] == 'C')
		{
			game->img.img = mlx_xpm_file_to_image(game->mlx, "./asset/grass.xpm", &game->img.width, &game->img.height);
			mlx_put_image_to_window(game->mlx, game->win, game->img.img, game->player.ex_x * SIZE, game->player.ex_y * SIZE);
		}
	}
	return (0);
}
