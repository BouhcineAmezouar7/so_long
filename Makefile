CC = cc
CFLAGS = -Wall -Wextra -Werror

LIBFT_PRINTF_DIR = ft_printf
LIBFT_PRINTF = $(LIBFT_PRINTF_DIR)/libftprintf.a

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

MLX = -lmlx -lXext -lX11

SRCS = src/main.c ./get_next_line/get_next_line.c ./get_next_line/get_next_line_utils.c \
	src/read_map.c src/handle_keypress.c \
	src/find_player.c src/validate_map.c src/flood_fill.c \
	src/free_all_leaks.c src/validate_map_elements.c

BONUS_SRCS = bonus_src/main_bonus.c ./get_next_line/get_next_line.c ./get_next_line/get_next_line_utils.c \
	bonus_src/read_map_bonus.c bonus_src/handle_keypress_bonus.c bonus_src/display_move_player_alpha_bonus.c \
	bonus_src/find_player_bonus.c bonus_src/validate_map_bonus.c bonus_src/flood_fill_bonus.c \
	bonus_src/display_move_player_count_bonus.c bonus_src/free_all_leaks_bonus.c \
	bonus_src/validate_map_elements_bonus.c bonus_src/img_data_load.c

OBJ = $(SRCS:.c=.o)
BONUS_OBJ = $(BONUS_SRCS:.c=.o)

NAME = so_long

NAME_BONUS = bonus

all: $(LIBFT_PRINTF) $(LIBFT) $(NAME)

$(NAME_BONUS): $(BONUS_OBJ) $(LIBFT_PRINTF) $(LIBFT)
	touch bonus
	$(CC) $(CFLAGS) $(BONUS_OBJ) $(MLX) $(LIBFT_PRINTF) $(LIBFT) -o $(NAME)

$(LIBFT_PRINTF):
	@$(MAKE) -C $(LIBFT_PRINTF_DIR)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(OBJ) $(LIBFT_PRINTF) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ) $(MLX) $(LIBFT_PRINTF) $(LIBFT) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(BONUS_OBJ)
	@$(MAKE) -C $(LIBFT_PRINTF_DIR) clean
	@$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME) $(NAME_BONUS)
	@$(MAKE) -C $(LIBFT_PRINTF_DIR) fclean
	@$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re

.SECONDARY: $(OBJ) $(BONUS_OBJ)
