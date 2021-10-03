#include "so_long.h"
#define SIZE 64 
int main(int ac, char **av)
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	int		width;
	int		height;
	char	*map_name;
	char	**map;
	int		fd;
	char	*line;
	int		x;
	int		y;
	int		cnt;

	if (ac != 2)
		write(1, "Error!\n", 8);
	else
	{
		map_name = av[1];
		fd = open(map_name, O_RDONLY);
		cnt = 0;
		while (get_next_line(fd, &line) > 0)
		{
			cnt++;
			free(line);
		}
		free(line);
		close(fd);
		fd = open(map_name, O_RDONLY);
		map = (char **)malloc(sizeof(char *) * (cnt + 1));
		int idx = 0;
		map[cnt] = 0;
		while (idx < cnt)
		{
			get_next_line(fd, &line);
			map[idx] = line;
			idx++;
		}
		close(fd);
		mlx_ptr = mlx_init();
		win_ptr = mlx_new_window(mlx_ptr, ft_strlen(map[0]) * SIZE, cnt * SIZE, "mlx 42");
		y = 0;
		while (y < cnt)
		{
			x = 0;
			while (x < (int)ft_strlen(map[0]))
			{
				if (map[y][x] == '1')
				{
					img_ptr = mlx_xpm_file_to_image(mlx_ptr, "./asset/box.xpm", &width, &height);
					mlx_put_image_to_window(mlx_ptr, win_ptr, img_ptr, x * SIZE, y * SIZE);
				}
				else if (map[y][x] == 'E')
				{
					img_ptr = mlx_xpm_file_to_image(mlx_ptr, "./asset/escape.xpm", &width, &height);
					mlx_put_image_to_window(mlx_ptr, win_ptr, img_ptr, x * SIZE, y * SIZE);
				}
				else
				{
					img_ptr = mlx_xpm_file_to_image(mlx_ptr, "./asset/grass.xpm", &width, &height);
					mlx_put_image_to_window(mlx_ptr, win_ptr, img_ptr, x * SIZE, y * SIZE);
					if (map[y][x] == 'P')
					{
						img_ptr = mlx_xpm_file_to_image(mlx_ptr, "./asset/man_d0.xpm", &width, &height);
						mlx_put_image_to_window(mlx_ptr, win_ptr,img_ptr, x * SIZE, y * SIZE);
					}
				}
				x++;
			}
			y++;
		}
		
		mlx_loop(mlx_ptr);
		for (int i = 0; i < cnt; i++)
			free(map[i]);
		free(map);
		system("leaks so_long> leaks_result_temp; cat leaks_result_temp | grep leaked && rm -rf leaks_result_temp");
/*
		mlx_ptr = mlx_init();
		win_ptr = mlx_new_window(mlx_ptr, 1000, 1000, "mlx 42");
		img_ptr = mlx_xpm_file_to_image(mlx_ptr, "./asset/grass.xpm", &width, &height);
		mlx_put_image_to_window(mlx_ptr, win_ptr, img_ptr, x, y);
		img_ptr = mlx_xpm_file_to_image(mlx_ptr, "./asset/man_d0.xpm", &width, &height);
		mlx_put_image_to_window(mlx_ptr, win_ptr, img_ptr, x, y);
		mlx_loop(mlx_ptr);
	*/
	}
}
