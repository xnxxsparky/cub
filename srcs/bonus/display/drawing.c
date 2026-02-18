/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcausseq <bcausseq@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 00:07:21 by bcausseq          #+#    #+#             */
/*   Updated: 2026/02/17 19:31:35 by bcausseq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "cub3d_bonus.h"

#include "bonus.h"

void	init_cur_text(t_game *game, t_ray *ray)
{
	game->cur_text.texture = get_cur_text(game, ray);
	game->cur_text.line_height = (int)(HEIGHT / ray->perp_wall_dist);
	game->cur_text.draw_start = (-game->cur_text.line_height / 2)
		+ (HEIGHT / 2);
	game->cur_text.draw_end = (game->cur_text.line_height / 2)
		+ (HEIGHT / 2);
	game->cur_text.step = 1.0 * game->cur_text.texture->height
		/ game->cur_text.line_height;
}

void	wall_draw(t_game *game, int x, mlx_color *colors)
{
	int	index;

	game->cur_text.tex_y = (int)game->cur_text.tex_pos;
	if (game->cur_text.tex_y < 0)
		game->cur_text.tex_y = 0;
	if (game->cur_text.tex_y > game->cur_text.texture->height)
		game->cur_text.tex_y = game->cur_text.texture->height - 1;
	index = game->cur_text.tex_y
		* game->cur_text.texture->width + game->cur_text.tex_x;
	game->cur_text.tex_pos += game->cur_text.step;
	game->cur_text.color = game->cur_text.texture->text_color[index];
	colors[game->cur_text.y * WIDTH + x] = game->cur_text.color;
}

void	draw_wall(t_game *game, t_ray *ray, int x, mlx_color *colors)
{
	init_cur_text(game, ray);
	if (!check_value(game, ray, 0))
		return ;
	if (ray->side_hit == 0)
		game->cur_text.wall_x = game->player.pos_y
			+ (ray->perp_wall_dist * ray->dir_y);
	else
		game->cur_text.wall_x = game->player.pos_x
			+ (ray->perp_wall_dist * ray->dir_x);
	game->cur_text.wall_x -= floor(game->cur_text.wall_x);
	game->cur_text.tex_x = (int)
		(game->cur_text.wall_x * game->cur_text.texture->width);
	check_value(game, ray, 1);
	game->cur_text.tex_pos = (game->cur_text.draw_start - HEIGHT / 2
			+ game->cur_text.line_height / 2) * game->cur_text.step;
	game->cur_text.y = game->cur_text.draw_start - 1;
	while (++(game->cur_text.y) < game->cur_text.draw_end + 1
		&& game->cur_text.y < HEIGHT)
		wall_draw(game, x, colors);
}

static int	door_detector(t_game *game, t_ray *ray)
{
	if (game->map.data_map[ray->map_y][ray->map_x + 1] == 'D')
	{
		game->map.pos_door_x = ray->map_x + 1;
		game->map.pos_door_y = ray->map_y;
	}
	else if (game->map.data_map[ray->map_y][ray->map_x - 1] == 'D')
	{
		game->map.pos_door_x = ray->map_x - 1;
		game->map.pos_door_y = ray->map_y;
	}
	else if (game->map.data_map[ray->map_y + 1][ray->map_x] == 'D')
	{
		game->map.pos_door_y = ray->map_y + 1;
		game->map.pos_door_x = ray->map_x;
	}
	else if (game->map.data_map[ray->map_y - 1][ray->map_x] == 'D')
	{
		game->map.pos_door_y = ray->map_y - 1;
		game->map.pos_door_x = ray->map_x;
	}
	else
		return (0);
	return (1);
}

void	open_door(t_game *game, t_map *map, t_ray *ray)
{
	if (door_detector(game, ray) == 1)
		map->data_map[map->pos_door_y][map->pos_door_x] = '0';
	else
		map->data_map[map->pos_door_y][map->pos_door_x] = 'D';
}
