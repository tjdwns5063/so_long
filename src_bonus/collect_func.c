/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collect_util.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongjki <seongjk@student.42seoul.k>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 16:04:49 by seongjki          #+#    #+#             */
/*   Updated: 2021/10/16 20:19:24 by seongjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_fill_collect_lst(t_game *game, int x, int y)
{
	t_collect	*new;

	if (so_lstfind(game->collect, x, y) == 0)
	{
		new = so_lstnew(x, y);
		if (!new)
		{
			so_lst_all_clear(&game->collect);
			printf("Error!\nMalloc Error!\n");
			exit(0);
		}
		new->next = game->collect;
		game->collect = new;
	}
	game->collect_cnt++;
}

void	ft_find_collect(t_game *game)
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
				ft_fill_collect_lst(game, x, y);
			x++;
		}
		y++;
	}
}

int	ft_iter_collect(t_game *game)
{
	t_collect	*lst;

	if (!game->collect)
		return (0);
	lst = game->collect;
	while (lst)
	{
		ft_draw_sprite(game, lst->x, lst->y);
		lst = lst->next;
	}
	return (0);
}

void	ft_get_collect(t_game *game)
{
	t_collect	*tmp;

	if (!game->collect)
		return ;
	if (game->map.map[game->player.y][game->player.x] == 'C')
	{
		game->map.map[game->player.y][game->player.x] = 'G';
		tmp = so_lstfind(game->collect, game->player.x, game->player.y);
		tmp->get = 1;
		game->collect_cnt--;
	}
	if (game->collect_cnt == 0)
		game->all_collect_flag = 1;
}

void	ft_escape(t_game *game)
{
	if (game->all_collect_flag == 1 && \
	game->map.map[game->player.y][game->player.x] == 'E')
	{
		so_lst_all_clear(&game->collect);
		exit(0);
	}
}
