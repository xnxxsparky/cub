# Common sources (shared between manda and bonus)
COMMON_SRCS	:=	common/init_colors.c \
				common/init_data.c \
				common/init_textures.c \
				common/parse_color.c \
				common/parse_error.c \
				common/parse_file.c \
				common/parse_utils.c \
				common/player.c 

# Mandatory sources
MANDA_SRCS	:=	manda/display/drawing.c \
				manda/parse_texture.c \
				manda/load_textures.c \
				manda/parse_map.c \
				manda/display/drawing_utils.c \
				manda/display/mlx.c \
				manda/display/rays.c \
				manda/gameplay/keys.c \
				manda/gameplay/movements.c \
				manda/main.c

# Bonus sources
BONUS_SRCS	:=	bonus/display/drawing.c \
				bonus/display/drawing_utils.c \
				bonus/display/mlx.c \
				bonus/display/rays.c \
				bonus/gameplay/keys.c \
				bonus/gameplay/keys_dwn.c \
				bonus/gameplay/keys_up.c \
				bonus/gameplay/movements.c \
				bonus/ft_bufcpy.c \
				bonus/ft_fsog.c \
				bonus/handle_change.c \
				bonus/i_textures_bonus.c \
				bonus/keybind.c \
				bonus/key_bind_display.c \
				bonus/menu.c \
				bonus/mouse.c \
				bonus/mouse_menu.c \
				bonus/p_door_bonus.c \
				bonus/p_map_bonus.c \
				bonus/p_texture_bonus.c \
				bonus/rotate_handler.c \
				bonus/settings_keybind.c \
				bonus/settings_keybind_hooks.c \
				bonus/main.c\
				bonus/load_textures.c

# Final source list depending on target
ifeq ($(BONUS), 1)
	SRCS	:= $(COMMON_SRCS) $(BONUS_SRCS)
else
	SRCS	:= $(COMMON_SRCS) $(MANDA_SRCS)
endif
