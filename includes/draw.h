/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcausseq <bcausseq@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 15:31:23 by bcausseq          #+#    #+#             */
/*   Updated: 2026/02/18 00:20:13 by bcausseq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_H
# define DRAW_H

# include <math.h>

# include "../third_parties/MLX/includes/mlx.h"
# include "../third_parties/MLX/includes/mlx_extended.h"
# include "utils.h"

typedef struct s_game t_game;
typedef struct s_map t_map;
typedef struct s_colors t_colors;

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
init_texture(t_game *game);

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
draw_bg(t_game *game);

void
free_data_texture(t_colors *colors, t_texture *textures);

int
check_textures(t_texture *textures);

int
check_colors(t_colors *colors);

#endif
