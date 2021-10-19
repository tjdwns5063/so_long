/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_func_util.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongjki <seongjk@student.42seoul.k>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 13:43:05 by seongjki          #+#    #+#             */
/*   Updated: 2021/10/17 13:43:27 by seongjki         ###   ########.fr       */
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
