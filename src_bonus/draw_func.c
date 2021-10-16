/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongjki <seongjk@student.42seoul.k>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 17:24:34 by seongjki          #+#    #+#             */
/*   Updated: 2021/10/16 19:51:45 by seongjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	set_img(t_game *game, char spcifir)
{
	if (spcifir == '1')
		game->img.path = "./asset/box.xpm";
	else if (spcifir == 'E')
		game->img.path = "./asset/escape.xpm";
	else
		game->img.path = "./asset/grass.xpm";
	ft_mlx_xpm_file_to_image(game, game->img.path);
}

void	draw_walk_cnt(t_game *game)
{
	char	*walk_cnt;

	walk_cnt = ft_itoa(game->walk);
	ft_mlx_xpm_file_to_image(game, "./asset/box.xpm");
	ft_mlx_put_image_to_window(game, 0, 0);
	mlx_string_put(game->mlx, game->win, 4, 32, 0x00000000, "walk:");
	mlx_string_put(game->mlx, game->win, 37, 32, 0x00000000, walk_cnt);
	free(walk_cnt);
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
	return (0);
}

int	ft_draw_sprite(t_game *game, int x, int y)
{
	static int	cnt;
	t_collect	*lst;

	lst = so_lstfind(game->collect, x, y);
	if (lst->get == 0)
	{
		ft_mlx_xpm_file_to_image(game, "./asset/grass.xpm");
		ft_mlx_put_image_to_window(game, x, y);
		ft_mlx_xpm_file_to_image(game, game->sprite.path[cnt / 10]);
		ft_mlx_put_image_to_window(game, x, y);
	}
	cnt++;
	if (cnt >= 170)
		cnt = 0;
	return (0);
}

int	ft_draw_player(t_game *game)
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
	}
	return (0);
}
