NAME = so_long

CC = gcc
CFLAGS = -Wall -Wextra
INCLUDE = -I./include -I./libft
LINK = -L$(MINI_LIB_DIR) -l$(MINI_LIB_NAME) -framework OpenGL -framework Appkit -L$(LIB_FT_DIR) -l$(LIB_FT_NAME)

MINI_LIB_DIR = ./minilibx_opengl/
MINI_LIB_NAME = mlx
MINI_LIB = $(MINI_LIB_DIR)lib$(MINI_LIB_NAME).a

LIB_FT_DIR = ./libft/
LIB_FT_NAME = ft
LIB_FT = $(LIB_FT_DIR)lib$(LIB_FT_NAME).a

SRC = ./src/so_long.c ./src/map_util.c ./src/load_map.c\
	./src/set_player.c ./src/draw_util.c ./src/check_map_func.c\
	./src/get_next_line.c ./src/get_next_line_utils.c\
	./src/init_strct.c ./src/collect_util.c ./src/mlx_util.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(MINI_LIB) $(OBJ)
	$(CC) $(CFLAGS) $(INCLUDE) $(LINK) $(OBJ) -o $@

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(MINI_LIB):
	make -C $(MINI_LIB_DIR) all
	make -C $(LIB_FT_DIR) all

clean:
	rm -f $(OBJ)
	make -C $(MINI_LIB_DIR) clean
	make -C $(LIB_FT_DIR) clean

fclean: clean
	rm -f $(NAME)

re: fclean all
