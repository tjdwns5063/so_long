NAME = so_long

CC = gcc
CFLAGS = -Wall -Wextra -Werror
INCLUDE = -I./include -I./libft
LINK = -L$(MINI_LIB_DIR) -l$(MINI_LIB_NAME) -framework OpenGL -framework AppKit -L$(LIB_FT_DIR) -l$(LIB_FT_NAME)

MINI_LIB_DIR = ./minilibx_opengl/
MINI_LIB_NAME = mlx
MINI_LIB = $(MINI_LIB_DIR)lib$(MINI_LIB_NAME).a

LIB_FT_DIR = ./libft/
LIB_FT_NAME = ft
LIB_FT = $(LIB_FT_DIR)lib$(LIB_FT_NAME).a

SRC_DIR = ./src/
SRC_NAME = so_long.c load_map_func_util.c load_map_func.c\
	player_func.c draw_func.c check_map_func.c\
	get_next_line.c get_next_line_utils.c check_map_func_util.c\
	init_func.c collect_func.c mlx_util.c
SRC = $(addprefix $(SRC_DIR),$(SRC_NAME))
OBJ = $(SRC:.c=.o)

BONUS = so_long_bonus
BONUS_SRC_DIR = ./src_bonus/
BONUS_SRC_NAME = so_long.c load_map_func_util.c load_map_func.c\
	player_func.c draw_func.c check_map_func.c\
	get_next_line.c get_next_line_utils.c\
	init_func.c collect_func.c mlx_util.c\
	lst_util.c check_map_func_util.c enemy_func.c\
	draw_func_util.c main_func.c
BONUS_SRC = $(addprefix $(BONUS_SRC_DIR),$(BONUS_SRC_NAME))
BONUS_OBJ = $(BONUS_SRC:.c=.o)

all: $(NAME)

$(NAME): $(MINI_LIB) $(OBJ)
	$(CC) $(CFLAGS) $(INCLUDE) $(LINK) $(OBJ) -o $@

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

bonus: $(BONUS)

$(BONUS): $(MINI_LIB) $(BONUS_OBJ)
	$(CC) $(CFLAGS) $(INCLUDE) $(LINK) $(BONUS_OBJ) -o $(BONUS)

$(MINI_LIB):
	make -C $(MINI_LIB_DIR) all
	make -C $(LIB_FT_DIR) all

clean:
	rm -f $(OBJ)
	rm -f $(BONUS_OBJ)
	make -C $(MINI_LIB_DIR) clean
	make -C $(LIB_FT_DIR) clean

fclean: clean
	rm -f $(NAME)
	rm -f $(BONUS)

re: fclean all
