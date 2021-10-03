/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongjki <seongjk@student.42seoul.k>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 16:58:29 by seongjki          #+#    #+#             */
/*   Updated: 2021/10/03 17:40:36 by seongjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef SO_LONG_H
#  define SO_LONG_H
#  define SIZE			64
#  define UP			126
#  define DOWN			125
#  define RIGHT			124
#  define LEFT			123
#  define ESC			53
#  define KEYPRESS		2
#  define KEYRELEASE	3

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <mlx.h>
# include "libft.h"

typedef struct	s_map
{
	char	*map_name;
	int		row;
	int		col;
	char	**map;
}				t_map;

typedef struct	s_player
{
	int		width;
	int		height;
	int		x;
	int		y;
	int		up;
	int		down;
	int		left;
	int		right;
	void	*img;
}				t_player;

typedef struct	s_game
{
	void		*mlx;
	void		*win;
    void    	*img;
	t_map		map;
	t_player	player;
}				t_game;

void	check_map(t_game *game, char *map_name);
void	load_map(t_game *game);
void    draw_map(t_game *game);
void	clear_map(t_map *map);
void	set_player(t_game *game);
int		ft_move(t_game *game);
int		ft_draw(t_game *game);
int		open_map(char *map_name);

#endif
