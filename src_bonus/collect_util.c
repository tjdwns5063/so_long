/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collect_util.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongjki <seongjk@student.42seoul.k>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 16:04:49 by seongjki          #+#    #+#             */
/*   Updated: 2021/10/14 15:02:51 by seongjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_find_collectible(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map.row)
	{
		x = 0;
		while (x < game->map.col)
		{
			if (game->map.map[y][x] == 'C')
			{
				so_lstfind(&game->collect, x, y);
				game->collect_cnt++;
			}
			x++;
		}
		y++;
	}
}

int	ft_iter_collect(t_game *game)
{
	int	x_pos;
	int	y_pos;
	static t_collect	*head;
	static t_collect	*lst;

	if (!game->collect)
		return (0);
	head = game->collect;
	if (!lst)
		lst = head;
	x_pos = lst->x;
	y_pos = lst->y;
	ft_draw_sprite(game, x_pos, y_pos);
	lst = lst->next;
	if (!lst)
		lst = head;
	return (0);
}

void	ft_get_collect(t_game *game)
{
	t_collect *tmp;

	if (game->map.map[game->player.y][game->player.x] == 'C')
	{
		tmp = game->collect;
		while (tmp)
		{
			if (game->player.y == tmp->y && game->player.x == tmp->x)
			{
				so_clear(&game->collect, tmp);
				game->collect_cnt--;
				break ;
			}
			tmp = tmp->next;
		}
	}
	if (game->collect_cnt == 0)
		game->all_collect_flag = 1;
}

void	ft_escape(t_game *game)
{
	if (game->all_collect_flag == 1)
	{
		if (game->map.map[game->player.y][game->player.x] == 'E')
			exit(0);
	}
}
