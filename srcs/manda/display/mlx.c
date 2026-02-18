/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcausseq <bcausseq@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 00:23:50 by bcausseq          #+#    #+#             */
/*   Updated: 2026/02/17 20:34:33 by bcausseq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "cub3d.h"

#include "manda.h"

void	init_keys(t_game *game)
{
	t_ctrl	ctrl;

	ft_bzero(&ctrl, sizeof(t_ctrl));
	ctrl.game.w.key = SDL_SCANCODE_W;
	ctrl.game.a.key = SDL_SCANCODE_A;
	ctrl.game.s.key = SDL_SCANCODE_S;
	ctrl.game.d.key = SDL_SCANCODE_D;
	ctrl.game.l.key = SDL_SCANCODE_LEFT;
	ctrl.game.r.key = SDL_SCANCODE_RIGHT;
	ctrl.game.oskour.key = SDL_SCANCODE_LALT;
	ctrl.game.pause.key = SDL_SCANCODE_P;
	ctrl.game.menu.key = SDL_SCANCODE_F1;
	ctrl.game.escape.key = SDL_SCANCODE_ESCAPE;
	ctrl.sett.l.key = SDL_SCANCODE_LEFT;
	ctrl.sett.r.key = SDL_SCANCODE_RIGHT;
	ctrl.sett.u.key = SDL_SCANCODE_UP;
	ctrl.sett.d.key = SDL_SCANCODE_DOWN;
	ctrl.sett.select.key = SDL_SCANCODE_RETURN;
	ctrl.sett.ret.key = SDL_SCANCODE_BACKSPACE;
	game->ctrl = ctrl;
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
	init_keys(game);
	game->mlx_ctx.img = mlx_new_image(game->mlx_ctx.mlx_ctx, WIDTH, HEIGHT);
	return (TRUE);
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
}

int	free_game(t_game *game)
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
	utl_super_free((void **)game->map.data_map);
	free(game->map.map);
	free(game->mlx_ctx.buf);
	return (1);
}
