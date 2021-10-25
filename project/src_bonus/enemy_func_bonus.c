/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongjki <seongjk@student.42seoul.k>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 13:17:40 by seongjki          #+#    #+#             */
/*   Updated: 2021/10/19 11:13:11 by seongjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	set_enemy_location(t_game *game)
{
	int	x;
	int	y;

	y = game->map.row - 1;
	while (y >= 0)
	{
		x = game->map.col - 1;
		while (x >= 0)
		{
			if (game->map.map[y][x] == '0')
			{
				game->enemy.x = x;
				game->enemy.y = y;
				game->enemy.ex_x = x;
				game->enemy.ex_y = y;
				return ;
			}
			x--;
		}
		y--;
	}
}

static int	check_direction(t_game *game)
{
	static int	flag;

	if (game->map.map[game->enemy.y][game->enemy.x + 1] == '1' || \
	game->map.map[game->enemy.y][game->enemy.x + 1] == 'C')
		flag = 1;
	else if (game->map.map[game->enemy.y][game->enemy.x - 1] == '1' || \
	game->map.map[game->enemy.y][game->enemy.x - 1] == 'C')
		flag = 0;
	return (flag);
}

void	ft_enemy_move(t_game *game)
{
	static int	flag;
	static int	cnt;

	game->enemy.ex_x = game->enemy.x;
	game->enemy.ex_y = game->enemy.y;
	cnt++;
	if (flag == 0 && cnt == 50 && \
	game->map.map[game->enemy.y][game->enemy.x + 1] != '1' && \
	game->map.map[game->enemy.y][game->enemy.x + 1] != 'C')
	{
		game->enemy.x++;
		cnt = 0;
	}
	else if (flag == 1 && cnt == 50 && \
	game->map.map[game->enemy.y][game->enemy.x - 1] != '1' && \
	game->map.map[game->enemy.y][game->enemy.x - 1] != 'C')
	{
		game->enemy.x--;
		cnt = 0;
	}
	flag = check_direction(game);
}

int	ft_enemy_contact(t_game *game)
{
	if (game->enemy.y == game->player.y && game->enemy.x == game->player.x)
	{
		printf("You lose!\n");
		return (1);
	}
	return (0);
}
