# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bcausseq <bcausseq@42angouleme.fr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/17 01:17:51 by bcausseq          #+#    #+#              #
#    Updated: 2026/01/24 21:22:52 by bcausseq         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
CC 			= cc

CFLAGS		= -Wall -Wextra -Werror -g
#CFLAGS		= -Wall -Wextra -Werror=vla -g -O0 -fno-builtin -mno-omit-leaf-frame-pointer -fno-omit-frame-pointer -fsanitize=address,pointer-compare,pointer-subtract,leak,undefined,shift,shift-exponent,shift-base,integer-divide-by-zero,unreachable,vla-bound,null,signed-integer-overflow,bounds,alignment,float-divide-by-zero,float-cast-overflow,nonnull-attribute,returns-nonnull-attribute,bool,enum,pointer-overflow,builtin -fsanitize-address-use-after-scope

NAME		= cub

LIBFT		= ./libft

LIBFT_LIB	= $(LIBFT)/libft.a

HEADER		= includes

MLX_PATH	= ./MLX
MLX_INC		= $(MLX_PATH)/includes
MLX			= $(MLX_PATH)/libmlx.so

SRCS		= srcs/manda/display/drawing.c\
			srcs/manda/display/drawing_utils.c\
			srcs/manda/display/load_textures.c\
			srcs/manda/init/init_colors.c\
			srcs/manda/init/init_data.c\
			srcs/manda/init/init_textures.c\
			srcs/manda/gameplay/keys.c\
			main.c\
			srcs/manda/display/mlx.c\
			srcs/manda/gameplay/movements.c\
			srcs/manda/parse/parse_color.c\
			srcs/manda/parse/parse_error.c\
			srcs/manda/parse/parse_file.c\
			srcs/manda/parse/parse_map.c\
			srcs/manda/parse/parse_texture.c\
			srcs/manda/parse/parse_utils.c\
			srcs/manda/gameplay/player.c\
			srcs/manda/display/rays.c\

BONUS_SRCS	= srcs/bonus/display/drawing.c\
			  srcs/bonus/i_textures_bonus.c\
			  main.c\
			  srcs/bonus/display/drawing_utils.c\
			  srcs/bonus/display/load_textures.c\
			  srcs/bonus/init/init_colors.c\
			  srcs/bonus/init/init_data.c\
			  srcs/bonus/gameplay/keys.c\
			  srcs/bonus/display/mlx.c\
			  srcs/bonus/gameplay/movements.c\
			  srcs/bonus/parse/parse_color.c\
			  srcs/bonus/parse/parse_error.c\
			  srcs/bonus/parse/parse_file.c\
			  srcs/bonus/p_map_bonus.c\
			  srcs/bonus/p_texture_bonus.c\
			  srcs/bonus/p_door_bonus.c\
			  srcs/bonus/parse/parse_utils.c\
			  srcs/bonus/gameplay/player.c\
			  srcs/bonus/display/rays.c\
			  srcs/bonus/mouse.c\
			  srcs/bonus/menu.c

BONUS_OBJ	= $(addprefix $(OBJ_DIR)/bonus/,$(BONUS_SRCS:.c=.o))

OBJ_DIR		= build

OBJ			= $(SRCS:.c=.o)

OBJ			:= $(addprefix $(OBJ_DIR)/manda/,$(OBJ))

# Colors
RED = \033[0;31m
GREEN = \033[0;32m
YELLOW = \033[0;33m
BLUE = \033[0;34m
PURPLE = \033[0;35m
CYAN = \033[0;36m
WHITE = \033[0;37m
BOLD = \033[1m
RESET = \033[0m

all:					$(NAME)

$(MLX_PATH):
	@if [ ! -d "$(MLX_PATH)" ]; then \
		git clone https://github.com/Seekrs/MacroLibX $(MLX_PATH); \
	fi

$(NAME):				$(OBJ) | $(MLX_PATH)
	@make --no-print-directory -C $(LIBFT)
	@make --no-print-directory -C $(MLX_PATH) -j
	@$(CC) $(CFLAGS) -o $@ $^ $(LIBFT_LIB) $(MLX) -lSDL2 -lm

$(OBJ_DIR)/manda/%.o:	%.c | $(MLX_PATH)
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -I$(LIBFT) -I$(HEADER) -I$(MLX_INC) -c $< -o $@

clean:
	@echo "$(YELLOW)🧹 Cleaning object files...$(RESET)"
	@make --no-print-directory -C $(LIBFT) clean
	@make --no-print-directory -C $(MLX_PATH) clean
	@rm -f $(OBJ)
	@rm -rf $(OBJ_DIR)
	@echo "$(GREEN)✨ Clean completed!$(RESET)"

fclean:					clean
	@echo "$(YELLOW)🗑️  Full clean in progress...$(RESET)"
	@make --no-print-directory -C $(LIBFT) fclean
	#@make --no-print-directory -C $(MLX_PATH) fclean
	@rm -f $(NAME)
	@rm -f $(NAME) $(NAME)_bonus
	@echo "$(GREEN)💀 Everything purged from Hell!$(RESET)"

re:						fclean all

bonus: $(BONUS_OBJ) | $(MLX_PATH)
	@make --no-print-directory -C $(LIBFT)
	@make --no-print-directory -C $(MLX_PATH) -j
	@$(CC) $(CFLAGS) -o $(NAME)_bonus $^ $(LIBFT_LIB) $(MLX) -lSDL2 -lm

$(OBJ_DIR)/bonus/%.o: %.c | $(MLX_PATH)
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -I$(LIBFT) -I$(HEADER) -I$(MLX_INC) -c $< -o $@

.PHONY: all clean fclean re bonus
