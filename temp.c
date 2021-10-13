#include "so_long_bonus.h"

typedef struct s_temp
{
	void *mlx;
	void *win;
	void *img;
	void *img2;
	char	*arr[17];
}				t_temp;

int	apple(t_temp *temp)
{
	int width;
	int	height;
	static int idx;

	printf("%d\n", idx);
	temp->img = mlx_xpm_file_to_image(temp->mlx, "./asset/grass.xpm", &width, &height);
	mlx_put_image_to_window(temp->mlx, temp->win, temp->img, 500, 500);				temp->img = mlx_xpm_file_to_image(temp->mlx, temp->arr[idx], &width, &height);
	mlx_put_image_to_window(temp->mlx, temp->win, temp->img, 500, 500);
	idx++;
	if (idx >= 17)
		idx = 0;
	return (0);
}

int	print(t_temp *temp)
{
	apple(temp);
//	apple2(temp);
}

int main()
{
	t_temp temp;

	temp.mlx = mlx_init();
	temp.win = mlx_new_window(temp.mlx, 1000, 1000, "temp");
	temp.arr[0] = "./asset/apple_0.xpm";
	temp.arr[1] = "./asset/apple_1.xpm";
	temp.arr[2] = "./asset/apple_2.xpm";
	temp.arr[3] = "./asset/apple_3.xpm";
	temp.arr[4] = "./asset/apple_4.xpm";
	temp.arr[5] = "./asset/apple_5.xpm";
	temp.arr[6] = "./asset/apple_6.xpm";
	temp.arr[7] = "./asset/apple_7.xpm";
	temp.arr[8] = "./asset/apple_8.xpm";
	temp.arr[9] = "./asset/apple_9.xpm";
	temp.arr[10] = "./asset/apple_10.xpm";
	temp.arr[11] = "./asset/apple_11.xpm";
	temp.arr[12] = "./asset/apple_12.xpm";
	temp.arr[13] = "./asset/apple_13.xpm";
	temp.arr[14] = "./asset/apple_14.xpm";
	temp.arr[15] = "./asset/apple_15.xpm";
	temp.arr[16] = "./asset/apple_16.xpm";
	mlx_loop_hook(temp.mlx, print, &temp);
	mlx_loop(temp.mlx);
}
