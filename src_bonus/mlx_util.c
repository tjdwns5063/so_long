/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_util.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongjki <seongjk@student.42seoul.k>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 11:38:51 by seongjki          #+#    #+#             */
/*   Updated: 2021/10/13 20:23:52 by seongjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_mlx_new_window(t_game *game, int x, int y)
{
	game->win = mlx_new_window(game->mlx, x, y, "so_long");
}

void	ft_mlx_xpm_file_to_image(t_game *game, char *path)
{
	game->img.img = \
mlx_xpm_file_to_image(game->mlx, path, &game->img.width, &game->img.height);
}

void	ft_mlx_put_image_to_window(t_game *game, int x, int y)
{
	mlx_put_image_to_window(\
	game->mlx, game->win, game->img.img, x * SIZE, y * SIZE);
}
