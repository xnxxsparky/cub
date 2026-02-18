# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bcausseq <bcausseq@42angouleme.fr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/17 01:17:51 by bcausseq          #+#    #+#              #
#    Updated: 2026/02/18 13:40:04 by bcausseq         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME := cub3D
BNAME := cub3D_bonus
MAKE := make --no-print-directory --debug=none

ifeq ($(DEVELOPMENT), 1)
DEBUG := 1
USE_WARNINGS := 1
endif

DEBUG ?= 0

CC := clang
CFLAGS := -Wall -Wextra -Iincludes -g
ifneq ($(USE_WARNINGS), 1)
CFLAGS += -Werror
endif
LDFLAGS :=

SRC_DIR := srcs
BUILD_DIR := build
OBJ_DIR := $(BUILD_DIR)/obj

ifeq ($(DEBUG), 1)
CFLAGS += -g3 -gdwarf-3 -ggdb
endif

ifeq ($(BONUS), 1)
CFLAGS += -DBONUS
endif

include sources.mk

OBJS := $(patsubst %.c,%.o,$(patsubst %.S,%.o,$(patsubst %.s,%.o,$(patsubst %.cpp,%.o,$(SRCS)))))
SRCS := $(addprefix $(SRC_DIR)/,$(SRCS))
OBJS := $(addprefix $(OBJ_DIR)/,$(OBJS))

LIB_DIR := third_parties
LIBRARIES += libft
libft_DIR := $(LIB_DIR)/libft
libft_DEP := $(libft_DIR)/libft.a
CFLAGS += -I$(libft_DIR)/include -I$(libft_DIR)/includes
LDFLAGS += $(libft_DEP)
DEPFILES += $(libft_DEP)
LIBRARIES += MacroLibX
MacroLibX_URL := https://github.com/seekrs/MacroLibX.git
MacroLibX_DIR := $(LIB_DIR)/MLX
MacroLibX_DEP := $(MacroLibX_DIR)/libmlx.so
CFLAGS += -I$(MacroLibX_DIR)/include -I$(MacroLibX_DIR)/includes
LDFLAGS += $(MacroLibX_DEP)
DEPFILES += $(MacroLibX_DEP)
LDFLAGS += -lSDL2 -lm

all: $(MacroLibX_DIR)
	@$(MAKE) $(NAME) BONUS=0

bonus: $(MacroLibX_DIR)
	@$(MAKE) $(BNAME) BONUS=1

$(MacroLibX_DIR):
	@if [ ! -d "$(MacroLibX_DIR)" ]; then \
		git clone https://github.com/Seekrs/MacroLibX $(MacroLibX_DIR); \
	fi

$(NAME): $(OBJS) $(DEPFILES)
	$(CC) $(LDFLAGS) -o $@ $^

$(BNAME): $(OBJS) $(DEPFILES)
	$(CC) $(LDFLAGS) -o $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

$(libft_DEP):
	make -C $(libft_DIR) -j$(shell nproc)

$(MacroLibX_DEP):
	make -C $(MacroLibX_DIR) -j$(shell nproc)

oclean:
	rm -rf $(BUILD_DIR)

clean: oclean
	make -C $(libft_DIR) clean
	make -C $(MacroLibX_DIR) clean

fclean: oclean
	make -C $(libft_DIR) fclean
	rm -rf $(NAME)
	rm -rf $(BNAME)
	make -C $(MacroLibX_DIR) fclean

re: fclean
	@$(MAKE) -j$(shell nproc) $(NAME)

rb: fclean bonus

.PHONY: all clean oclean fclean re bonus rb
