/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongjki <seongjk@student.42seoul.k>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 16:58:29 by seongjki          #+#    #+#             */
/*   Updated: 2021/10/02 19:28:40 by seongjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef SO_LONG_H
#  define SO_LONG_H
#  define SIZE 64

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

typedef struct	s_game
{
	void	*mlx;
	void	*win;
	t_map	map;
}				t_game;

int		check_map(t_map *map, char *map_name);
int		load_map(t_map *map);
void	clear_map(t_map *map);
int		open_map(char *map_name);

#endif
