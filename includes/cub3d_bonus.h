/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcausseq <bcausseq@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 20:20:54 by bcausseq          #+#    #+#             */
/*   Updated: 2026/02/07 00:42:04 by bcausseq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_BONUS_H
# define CUB3D_BONUS_H

# include <fcntl.h>
# include <SDL2/SDL_scancode.h>
# include <math.h>
# include <stdint.h>

# include "../libft/includes/libft.h"
# include "mlx.h"
# include "mlx_extended.h"

# define EXTENSION "Error : INVALID FILE EXTENSION\nUSAGE : exemple_map[.cub]\n"
# define BAD_FILE "Error : ISSUE REGARDING FILE :\n"
# define DIRECTORY "Error : FORMAT IS A DIRECTORY :\n"
# define MAP "Error : INVALID DATA MAP\n"
# define ARGS "Error : INVALID ARGUMENT\nUSAGE : ./cub3d [map.cub]\n"
# define MLX "Error : ISSUE REGARDING MLX\n"
# define COLORS "ERROR : INVALID COLOR(S)\n"

# define WIDTH 1280
# define HEIGHT 720
# define FALSE '\0'
# define TRUE 'Y'
# define MOV_SPEED 0.025f
# define ROT_SPEED 0.015f
# define THICKNESS 0.125f
# define NEW_X 0b01
# define NEW_Y 0b10
# define SENSITIVITY 0.0021f
# define BUTT_Y 30
# define BUTT_X 100
# define HIT_NONE 0
# define HIT_WALL 1
# define HIT_DOOR 2

typedef char	t_boolean;

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

typedef struct s_ray
{
	float	dir_x;
	float	dir_y;
	int		map_x;
	int		map_y;
	float	dist_side_x;
	float	dist_side_y;
	float	delta_dist_x;
	float	delta_dist_y;
	int		step_x;
	int		step_y;
	int		side_hit;
	float	perp_wall_dist;
	float	wall_x;
	int		hit_type;
}	t_ray;

typedef struct s_player
{
	float	pos_x;
	float	pos_y;
	float	dir_x;
	float	dir_y;
	float	cam_x;
	float	cam_y;
}	t_player;

typedef struct s_mlx
{
	mlx_context				mlx_ctx;
	mlx_window				win;
	mlx_window_create_info	win_infos;
	mlx_image				img;
	mlx_color				*buf;
	mlx_color				*old_buf;
}	t_mlx;

typedef struct s_data_text
{
	mlx_image	text;
	char		*path;
	int			height;
	int			width;
	mlx_color	*text_color;
}	t_data_text;

typedef struct s_texture
{
	t_data_text	no;
	t_data_text	so;
	t_data_text	ea;
	t_data_text	we;
	t_data_text	door;
}	t_texture;

typedef struct s_map
{
	char	**map;
	char	**data_map;
	int		height;
	int		width;
	char	spawn;
	int		pos_door_x;
	int		pos_door_y;
}	t_map;

typedef struct s_ctrl_ind
{
	t_boolean	on;
	int			key;
}	t_ctrl_ind;

typedef struct s_ctrl_game
{
	t_ctrl_ind	w;
	t_ctrl_ind	a;
	t_ctrl_ind	s;
	t_ctrl_ind	d;
	t_ctrl_ind	l;
	t_ctrl_ind	r;
	t_ctrl_ind	oskour;
	t_ctrl_ind	pause;
	t_ctrl_ind	menu;
	t_ctrl_ind	escape;
}	t_ctrl_game;

typedef struct s_ctrl_sett
{
	t_ctrl_ind	l;
	t_ctrl_ind	r;
	t_ctrl_ind	u;
	t_ctrl_ind	d;
	t_ctrl_ind	select;
	t_ctrl_ind	ret;
}	t_ctrl_sett;

typedef struct s_ctrl
{
	t_ctrl_game	game;
	t_ctrl_sett	sett;
}	t_ctrl;

typedef struct s_current_texture
{
	t_data_text	*texture;
	mlx_color	color;
	float		wall_x;
	float		step;
	float		tex_pos;
	int			tex_x;
	int			tex_y;
	int			y;
	int			line_height;
	int			draw_start;
	int			draw_end;
}	t_current_texture;

typedef struct s_colors
{
	mlx_color	floor;
	mlx_color	ceiling;
	char		*c_floor;
	char		*c_ceiling;
}	t_colors;

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

typedef struct s_buttons
{
	char		*text;
	int			y;
	int			x;
	mlx_color	normal;
	mlx_color	hover;
	void		(*action)(t_game *game);
}	t_buttons;

void
draw_floor(t_game *game, int x, mlx_color *colors);

void
draw_ceiling(t_game *game, int x, mlx_color *colors);

void
wall_draw(t_game *game, int x, mlx_color *colors);

void
draw_wall(t_game *game, t_ray *ray, int x, mlx_color *colors);

t_data_text
*get_cur_text(t_game *game, t_ray *ray);

t_boolean
check_value(t_game *game, t_ray *ray, int mod);

void
init_cur_text(t_game *game, t_ray *ray);

void
key_hooks_dwn(int key, void *param);

void
key_hooks_up(int key, void *param);

void
win_hooks(int event, void *param);

char
**dup_map(void);

void
init_texture(t_game *game);

void
rotate(t_game *game);

void
cross_pad(t_game *game, float *move_x, float *move_y);

void
border_check(t_game *game, float new_x, float new_y);

void
move(t_game *game);

t_boolean
init_mlx(t_game *game);

int
free_game(t_game *game);

void
calc_wall_distance(t_game *game, t_ray *ray);

void
dda_algorithm(t_game *game, t_ray *ray);

void
find_step(t_game *game, t_ray *ray);

void
init_ray(t_game *game, t_ray *ray, int x);

void
cast_rays(void *param);

void
get_player(t_map *map, t_player *player);

void
draw_bg(t_game *game);

/*Bonuses*/

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
init_keys(t_game *game);

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
fifty_shade_of_grey(t_game *game);

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

/************************************************************/
/*                    Salabbe's Functions                   */
/************************************************************/

void			init_colors(t_game *game);
int				init_data(t_game *game);
void			init_textures(t_game *game);
int				parse_colors(t_colors *colors);
void			error(char *type, char *arg, t_game *game, t_boolean free_n);
int				check_name_file(char *filename);
int				get_fd(char *filename, t_game *game);
char			**get_map(int fd, int *width, t_game *game);
char			**get_data_map(char**map, int start, int *width);
void			free_data_texture(t_colors *colors, t_texture *textures);
int				define_data_map(t_game *game);
int				check_textures(t_texture *textures);
int				check_colors(t_colors *colors);
int				ischarset(char *set, char c);
void			skip_blank(char **map, int *start);
int				count_lines(char **tab);
int				check_textures_paths(t_texture *textures, t_game *game);

int				check_door(t_texture *texture);
int				set_data_all(t_game *game, int i, int j);
void			dda_step(t_ray *ray);
int				is_hit(t_game *game, t_ray *ray);
void			open_door(t_game *game, t_map *map, t_ray *ray);

#endif
