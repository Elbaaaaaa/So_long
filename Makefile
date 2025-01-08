# Variables
CC = cc
CFLAGS = -Wall -Wextra -Werror
INCLUDE = -I./includes -I./libft -I./mlx

LIBFT_DIR = lib/libft
LIBFT = $(LIBFT_DIR)/libft.a

MLX_DIR = lib/mlx
MLX = $(MLX_DIR)/libmlx.a

MLX_FLAGS = -L$(MLX_DIR) -lmlx -L/usr/lib/X11 -lXext -lX11

NAME = so_long

SRCS = src/main.c \
		src/parsing.c \
		src/so_long_utils.c \
		src/pathfinding.c \
		src/render.c \
		src/player.c \
		src/utils.c \

SRCS_BONUS = src_bonus/main_bonus.c \
			 src_bonus/parsing_bonus.c \
			 src_bonus/so_long_utils_bonus.c \
			 src_bonus/pathfinding_bonus.c \
			 src_bonus/render_bonus.c \
			 src_bonus/player_bonus.c \
			 src_bonus/utils_bonus.c \
			 src_bonus/animation_bonus.c \
			 src_bonus/enemy_bonus.c \
			 src_bonus/hooks_bonus.c \

OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)

# Rules
all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(MLX)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT) $(MLX) $(MLX_FLAGS)

bonus: $(OBJS_BONUS) $(LIBFT) $(MLX)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS_BONUS) $(LIBFT) $(MLX) $(MLX_FLAGS)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(MLX):
	$(MAKE) -C $(MLX_DIR)

.c.o:
	$(CC) $(CFLAGS) -c -o $@ $< $(INCLUDE)

clean:
	rm -f $(OBJS) $(OBJS_BONUS)
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(MLX_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(MLX_DIR) clean

re: fclean all

.PHONY: all clean fclean re bonus
