/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcausseq <bcausseq@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 00:25:45 by bcausseq          #+#    #+#             */
/*   Updated: 2026/01/13 18:38:27 by bcausseq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	calc_wall_distance(t_game *game, t_ray *ray)
{
	if (ray->side_hit == 0)
		ray->perp_wall_dist = (ray->map_x - game->player.pos_x
				+ (1 - ray->step_x) / 2) / ray->dir_x;
	else
		ray->perp_wall_dist = (ray->map_y - game->player.pos_y
				+ (1 - ray->step_y) / 2) / ray->dir_y;
}

void	dda_algorithm(t_game *game, t_ray *ray)
{
	int	hit;

	hit = 0;
	while (hit == 0)
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
		if (ray->map_x < 0 || ray->map_x >= game->map.width
			|| ray->map_y < 0 || ray->map_y >= game->map.height)
			hit = 1;
		else if (game->map.data_map[ray->map_y][ray->map_x] == '1')
			hit = 1;
	}
}

void	find_step(t_game *game, t_ray *ray)
{
	if (ray->dir_x < 0)
	{
		ray->step_x = -1;
		ray->dist_side_x = (game->player.pos_x - ray->map_x)
			* ray->delta_dist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->dist_side_x = (ray->map_x + 1.0 - game->player.pos_x)
			* ray->delta_dist_x;
	}
	if (ray->dir_y < 0)
	{
		ray->step_y = -1;
		ray->dist_side_y = (game->player.pos_y - ray->map_y)
			* ray->delta_dist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->dist_side_y = (ray->map_y + 1.0 - game->player.pos_y)
			* ray->delta_dist_y;
	}
}

void	init_ray(t_game *game, t_ray *ray, int x)
{
	float	camera_x;

	camera_x = 2 * x / (float)WIDTH - 1;
	ray->dir_x = game->player.dir_x + game->player.cam_x * camera_x;
	ray->dir_y = game->player.dir_y + game->player.cam_y * camera_x;
	ray->map_x = (int)game->player.pos_x;
	ray->map_y = (int)game->player.pos_y;
	if (ray->dir_x == 0)
		ray->delta_dist_x = 1e30;
	else
		ray->delta_dist_x = fabs(1 / ray->dir_x);
	if (ray->dir_y == 0)
		ray->delta_dist_y = 1e30;
	else
		ray->delta_dist_y = fabs(1 / ray->dir_y);
	find_step(game, ray);
}

void	cast_rays(void *param)
{
	t_game		*game;
	t_ray		ray;
	int			x;

	x = 0;
	game = (t_game *)param;
	ft_bzero(&ray, sizeof(t_ray));
	mlx_clear_window(game->mlx_ctx.mlx_ctx, game->mlx_ctx.win,
		(mlx_color){.rgba = 0x000000FF});
	draw_bg(game);
	move(game);
	while (x < WIDTH)
	{
		init_ray(game, &ray, x);
		dda_algorithm(game, &ray);
		calc_wall_distance(game, &ray);
		draw_wall(game, &ray, x, game->mlx_ctx.buf);
		x++;
	}
	mlx_set_image_region(game->mlx_ctx.mlx_ctx, game->mlx_ctx.img,
		0, 0, WIDTH, HEIGHT, game->mlx_ctx.buf);
	mlx_put_image_to_window(game->mlx_ctx.mlx_ctx, game->mlx_ctx.win,
		game->mlx_ctx.img, 0, 0);
}
