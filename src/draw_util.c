/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongjki <seongjk@student.42seoul.k>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 17:24:34 by seongjki          #+#    #+#             */
/*   Updated: 2021/10/13 16:43:28 by seongjki         ###   ########.fr       */
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
		game->img.path = "./asset/apple_0.xpm";
	else
		game->img.path = "./asset/grass.xpm";
	ft_mlx_xpm_file_to_image(game, game->img.path);
}

void	ft_count_move(t_game *game, int dir_x, int dir_y)
{
	if (dir_x != 0)
		game->player.x += dir_x;
	else if (dir_y != 0)
		game->player.y += dir_y;
	game->walk++;
	printf("Walk Count: %d\n", game->walk);
}

int	ft_move(t_game *game)
{
	game->player.ex_x = game->player.x;
	game->player.ex_y = game->player.y;
	if (game->player.left == 1 && \
	game->map.map[game->player.y][game->player.x - 1] != '1')
		ft_count_move(game, -1, 0);
	if (game->player.right == 1 && \
	game->map.map[game->player.y][game->player.x + 1] != '1')
		ft_count_move(game, 1, 0);
	if (game->player.up == 1 && \
	game->map.map[game->player.y - 1][game->player.x] != '1')
		ft_count_move(game, 0, -1);
	if (game->player.down == 1 && \
	game->map.map[game->player.y + 1][game->player.x] != '1')
		ft_count_move(game, 0, 1);
	return (0);
}

int	ft_draw(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map.row)
	{
		x = 0;
		while (x < game->map.col)
		{
			ft_mlx_xpm_file_to_image(game, "./asset/grass.xpm");
			ft_mlx_put_image_to_window(game, x, y);
			set_img(game, game->map.map[y][x]);
			ft_mlx_put_image_to_window(game, x, y);
			x++;
		}
		y++;
	}
	ft_mlx_xpm_file_to_image(game, "./asset/man_d0.xpm");
	ft_mlx_put_image_to_window(game, game->player.x, game->player.y);
	return (0);
}

int	ft_iter_draw(t_game *game)
{
	if (game->map.map[game->player.y][game->player.x] == 'C')
	{
		ft_mlx_xpm_file_to_image(game, "./asset/grass.xpm");
		ft_mlx_put_image_to_window(game, game->player.x, game->player.y);
	}
	ft_mlx_xpm_file_to_image(game, "./asset/man_d0.xpm");
	ft_mlx_put_image_to_window(game, game->player.x, game->player.y);
	if (game->player.x != game->player.ex_x || \
	game->player.y != game->player.ex_y)
	{
		set_img(game, game->map.map[game->player.ex_y][game->player.ex_x]);
		ft_mlx_put_image_to_window(game, game->player.ex_x, game->player.ex_y);
		if (game->map.map[game->player.ex_y][game->player.ex_x] == 'C')
		{
			ft_mlx_xpm_file_to_image(game, "./asset/grass.xpm");
			ft_mlx_put_image_to_window(\
			game, game->player.ex_x, game->player.ex_y);
		}
	}
	return (0);
}
