/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcausseq <bcausseq@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 15:03:20 by bcausseq          #+#    #+#             */
/*   Updated: 2026/02/17 20:32:15 by bcausseq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BONUS_H
# define BONUS_H

# define BUTT_Y 30
# define BUTT_X 100
# define HIT_DOOR 2

# include "utils.h"
# include "window.h"
# include "draw.h"
# include "controls.h"
# include "game.h"

typedef struct s_game t_game;

typedef enum e_state_game
{
	NORMAL_STATE,
	PAUSE_STATE,
	MENU_STATE,
	KEYBNG_GAME_STATE,
	KEYBNG_SETT_STATE,
	WAITING_GAME_STATE,
	WAITING_SETT_STATE,
	NONE_STATE
}	t_state_game;

typedef struct s_mouse
{
	int			x;
	int			y;
	int			old_x;
	int			old_y;
	t_boolean	captured;
}	t_mouse;

typedef struct s_menu
{
	struct s_buttons	*buttons;
	int					nb_buttons;
	int					index_select;
}	t_menu;

typedef struct s_buttons
{
	char		*text;
	int			y;
	int			x;
	mlx_color	normal;
	mlx_color	hover;
	void		(*action)(t_game *game);
}	t_buttons;


typedef struct s_game
{
	t_texture			texture;
	t_current_texture	cur_text;
	t_map				map;
	t_player			player;
	t_mlx				mlx_ctx;
	t_ctrl				ctrl;
	t_colors			colors;
	t_mouse				mouse;
	t_state_game		curr_state;
	t_menu				menu;
	t_menu				key_bind;
	t_menu				set_bind;
	char				*filename;
	int					fd;
}	t_game;

void
init_mouse(t_game *game);

void
update_mouse(t_game *game);

void
rotate_player(t_game *game, float angle);

void
menu_draw(t_game *game);

void
update_state(void *param);

void
init_but(t_game *game);

void
state_key_hooks_dwn(int key, void *param);

void
state_key_hooks_up(int key, void *param);

void
key_bind(t_game *game);

void
init_keybinds(t_game *game);

void
but_display(t_game *game, t_menu menu);

void
keybind_draw(t_game *game);

void
ft_bufcpy(mlx_color *src, mlx_color *dest);

void
fifty_shade_of_grey(mlx_color *buf);

void
handle_pause(t_game *game);

void
handle_menu(t_game *game);

void
state_key_hooks_dwn(int key, void *param);

void
waiting(int key, t_game *game);

void
keybind_key_hooks_dwn(int key, t_game *game);

void
game_key_hooks_dwn(int key, t_game *game);

void
menu_key_hooks_dwn(int key, t_game *game);

void
pause_key_hooks_dwn(int key, t_game *game);

void
ft_bufcpy(mlx_color *src, mlx_color *dest);

void
sett_keybind_draw(t_game *game);

void
sett_init_keybinds(t_game *game);

void
sett_waiting(int key, t_game *game);

void
sett_keybind_key_hooks_dwn(int key, t_game *game);

void
mouse_menu(t_game *game, t_menu *menu);

void
mouse_click_handle(int key, void *param);

void
draw_text(t_buttons *button, t_menu menu, t_mlx mlx);

void
display_wait_bind(t_game *game);

t_boolean
check_key_free(int key, t_game *game);

int
check_door(t_texture *texture);

int
set_data_all(t_game *game, int i, int j);

void
dda_step(t_ray *ray);

int
is_hit(t_game *game, t_ray *ray);

void
open_door(t_game *game, t_map *map, t_ray *ray);

#endif
