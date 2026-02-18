/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcausseq <bcausseq@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 00:09:37 by bcausseq          #+#    #+#             */
/*   Updated: 2026/02/17 19:31:20 by bcausseq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "cub3d_bonus.h"

#include "bonus.h"

t_data_text	*get_cur_text(t_game *game, t_ray *ray)
{
	if (ray->hit_type == HIT_DOOR)
		return (&game->texture.door);
	if (ray->side_hit == 0)
	{
		if (ray->step_x > 0)
			return (&game->texture.ea);
		return (&game->texture.we);
	}
	if (ray->step_y > 0)
		return (&game->texture.so);
	return (&game->texture.no);
}

t_boolean	check_value(t_game *game, t_ray *ray, int mod)
{
	if (mod == 0)
	{
		if (game->cur_text.draw_start < 0)
			game->cur_text.draw_start = 0;
		if (game->cur_text.draw_end >= HEIGHT)
			game->cur_text.draw_end = HEIGHT - 1;
		if (game->cur_text.draw_start >= game->cur_text.draw_end)
			return (FALSE);
	}
	else if (mod == 1)
	{
		if (!((ray->side_hit == 0 && ray->dir_x > 0)
				|| (ray->side_hit == 1 && ray->dir_y < 0)))
			game->cur_text.tex_x = game->cur_text.texture->width
				- game->cur_text.tex_x - 1;
		if (game->cur_text.tex_x < 0)
			game->cur_text.tex_x = 0;
		if (game->cur_text.tex_x >= game->cur_text.texture->width)
			game->cur_text.tex_x = game->cur_text.texture->width - 1;
	}
	return (TRUE);
}

void	draw_bg(t_game *game)
{
	int	height;

	height = -1;
	while (++height < (HEIGHT * WIDTH) / 2)
	{
		game->mlx_ctx.buf[height] = game->colors.ceiling;
		game->mlx_ctx.buf[height].a = 255;
	}
	--height;
	while (++height < HEIGHT * WIDTH)
	{
		game->mlx_ctx.buf[height] = game->colors.floor;
		game->mlx_ctx.buf[height].a = 255;
	}
}

void	dda_step(t_ray *ray)
{
	if (ray->dist_side_x < ray->dist_side_y)
	{
		ray->dist_side_x += ray->delta_dist_x;
		ray->map_x += ray->step_x;
		ray->side_hit = 0;
	}
	else
	{
		ray->dist_side_y += ray->delta_dist_y;
		ray->map_y += ray->step_y;
		ray->side_hit = 1;
	}
}

int	is_hit(t_game *game, t_ray *ray)
{
	char	tile;

	if (ray->map_x < 0 || ray->map_x >= game->map.width
		|| ray->map_y < 0 || ray->map_y >= game->map.height)
		return (HIT_WALL);
	tile = game->map.data_map[ray->map_y][ray->map_x];
	if (tile == '1')
		return (HIT_WALL);
	if (tile == 'D')
		return (HIT_DOOR);
	return (HIT_NONE);
}
