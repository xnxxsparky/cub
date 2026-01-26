/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcausseq <bcausseq@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 00:23:50 by bcausseq          #+#    #+#             */
/*   Updated: 2026/01/24 21:53:45 by bcausseq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	update_state(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (game->curr_state == NORMAL_STATE)
		cast_rays((void *)game);
	else if (game->curr_state == MENU_STATE)
		menu_draw(game);
}

t_boolean	init_mlx(t_game *game)
{
	game->mlx_ctx.mlx_ctx = mlx_init();
	if (!(game->mlx_ctx.mlx_ctx))
		return (FALSE);
	game->mlx_ctx.win_infos.title = "El Cubo 3D";
	game->mlx_ctx.win_infos.height = HEIGHT;
	game->mlx_ctx.win_infos.width = WIDTH;
	game->mlx_ctx.win = mlx_new_window(game->mlx_ctx.mlx_ctx,
			&(game->mlx_ctx.win_infos));
	if (!(game->mlx_ctx.win))
		return (FALSE);
	game->mlx_ctx.buf = ft_calloc(sizeof(mlx_color), HEIGHT * WIDTH);
	if (!(game->mlx_ctx.buf))
		return (FALSE);
	game->mlx_ctx.img = mlx_new_image(game->mlx_ctx.mlx_ctx, WIDTH, HEIGHT);
	game->curr_state = NORMAL_STATE;
	init_mouse(game);
	return (TRUE);
}

void	text_free(t_game *game)
{
	if (game->texture.door.text_color)
	{
		free(game->texture.door.text_color);
		free(game->texture.door.path);
		mlx_destroy_image(game->mlx_ctx.mlx_ctx, game->texture.door.text);
	}
}

void	free_text(t_game *game)
{
	if (game->texture.no.text_color)
	{
		free(game->texture.no.text_color);
		free(game->texture.no.path);
		mlx_destroy_image(game->mlx_ctx.mlx_ctx, game->texture.no.text);
	}
	if (game->texture.so.text_color)
	{
		free(game->texture.so.text_color);
		free(game->texture.so.path);
		mlx_destroy_image(game->mlx_ctx.mlx_ctx, game->texture.so.text);
	}
	if (game->texture.we.text_color)
	{
		free(game->texture.we.text_color);
		free(game->texture.we.path);
		mlx_destroy_image(game->mlx_ctx.mlx_ctx, game->texture.we.text);
	}
	if (game->texture.ea.text_color)
	{
		free(game->texture.ea.text_color);
		free(game->texture.ea.path);
		mlx_destroy_image(game->mlx_ctx.mlx_ctx, game->texture.ea.text);
	}
	text_free(game);
}

void	free_game(t_game *game)
{
	int	i;

	i = -1;
	free_text(game);
	if (game->mlx_ctx.win)
		mlx_destroy_window(game->mlx_ctx.mlx_ctx, game->mlx_ctx.win);
	if (game->mlx_ctx.img)
		mlx_destroy_image(game->mlx_ctx.mlx_ctx, game->mlx_ctx.img);
	while (game->map.map[++i])
		free(game->map.map[i]);
	if (game->mlx_ctx.mlx_ctx)
		mlx_destroy_context(game->mlx_ctx.mlx_ctx);
	if (game->colors.c_floor)
		free(game->colors.c_floor);
	if (game->colors.c_ceiling)
		free(game->colors.c_ceiling);
	i = -1;
	if (game->map.data_map)
	{
		while (game->map.data_map[++i])
			free(game->map.data_map[i]);
		free(game->map.data_map);
	}
	free(game->map.map);
	free(game->mlx_ctx.buf);
}
