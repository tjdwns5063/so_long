/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongjki <seongjk@student.42seoul.k>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 16:58:29 by seongjki          #+#    #+#             */
/*   Updated: 2021/10/16 20:20:27 by seongjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define SIZE			64
# define W				13
# define S				1
# define D				2
# define A				0
# define UP				126
# define DOWN			125
# define RIGHT			124
# define LEFT			123
# define ESC			53
# define RED_CROSS		17
# define KEY_PRESS		2

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <mlx.h>
# include "get_next_line.h"
# include "libft.h"

typedef struct s_img
{
	int		width;
	int		height;
	char	*path;
	void	*img;
}				t_img;

typedef struct s_map
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

typedef struct s_player
{
	int		x;
	int		ex_x;
	int		y;
	int		ex_y;
	char	*ex_img;
	int		up;
	int		down;
	int		left;
	int		right;
}				t_player;

typedef struct s_collect
{
	int		cnt;
	int		all_collect_flag;
}				t_collect;

typedef struct s_sprite
{
    char	*path[17];
}				t_sprite;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	int			walk;
	t_img		img;
	t_map		map;
	t_player	player;
	t_collect	collect;
}				t_game;

void		check_name_extension(char *map_name, t_map *map);
void		check_map_is_rec(t_map *map);
void		check_element(t_map *map);
void		check_surrounded_wall(t_map *map);
void	check_element_in_map(t_map *map, char word);
int	check_map_is_surrounded(int row, int col, t_map *map);
void	load_map(t_game *game, char *map_name);
void	clear_map(t_map *map);
int		ft_move(t_game *game);
int		ft_iter_draw(t_game *game);
int		ft_draw(t_game *game);
int		ft_key_press(int keycode, t_game *game);
void	set_player_location(t_game *game);
int		open_map(char *map_name);
void	init_game(t_game *game);
void	init_map(t_map *map);
void	init_player(t_player *player);
void	ft_mlx_new_window(t_game *game, int x, int y);
void	ft_mlx_xpm_file_to_image(t_game *game, char *path);
void	ft_mlx_put_image_to_window(t_game *game, int x, int y);
void	ft_cnt_collectible(t_game *game);
void	ft_get_collect(t_game *game);
void	ft_escape(t_game *game);

#endif
