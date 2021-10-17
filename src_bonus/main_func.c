/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongjki <seongjk@student.42seoul.k>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 16:41:12 by seongjki          #+#    #+#             */
/*   Updated: 2021/10/17 16:51:41 by seongjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	draw_loop(t_game *game)
{
	draw_walk_cnt(game);
	ft_draw_player(game);
	ft_draw_enemy(game);
	ft_get_collect(game);
	ft_iter_collect(game);
}

void	move_loop(t_game *game)
{
	ft_move(game);
	ft_enemy_move(game);
	init_player(&game->player);
}
