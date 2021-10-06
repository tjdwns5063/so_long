/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongjki <seongjk@student.42seoul.k>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 16:58:29 by seongjki          #+#    #+#             */
/*   Updated: 2021/10/06 18:53:30 by seongjki         ###   ########.fr       */
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
# include "get_next_line.h"
# include "libft.h"

typedef struct	s_img
{
	int		width;
	int		height;
	char	*path;
	void	*img;
}				t_img;

typedef struct	s_map
{
	char	*map_name;
	int		row;
	int		col;
	char	**map;
	int		have_p;
	int		have_e;
	int		have_c;
	int		have_z;
	int		have_o;
}				t_map;

typedef struct	s_player
{
	int		x;
	int		y;
	int		up;
	int		down;
	int		left;
	int		right;
}				t_player;

typedef struct	s_game
{
	void		*mlx;
	void		*win;
	t_img		img;
	t_map		map;
	t_player	player;
}				t_game;

int		check_name_extension(char *map_name, t_map *map);
int		check_map_is_rec(t_map *map);
int		check_element(t_map *map);
int		check_surrounded_wall(t_map *map);
void	load_map(t_game *game, char *map_name);
void	clear_map(t_map *map);
void	set_player(t_game *game);
int		ft_move(t_game *game);
int		ft_draw(t_game *game);
int		open_map(char *map_name);
void	init_game(t_game *game);
void	init_map(t_map *map);

#endif
