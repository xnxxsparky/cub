/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcausseq <bcausseq@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 00:16:28 by bcausseq          #+#    #+#             */
/*   Updated: 2026/02/17 19:48:06 by bcausseq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "cub3d.h"

#include "manda.h"

void	key_hooks_dwn(int key, void *param)
{
	t_game		*game;
	t_ctrl_game	ctrl;

	game = (t_game *)param;
	ctrl = game->ctrl.game;
	if (key == ctrl.escape.key)
		mlx_loop_end(game->mlx_ctx.mlx_ctx);
	if (key == ctrl.a.key)
		game->ctrl.game.a.on = TRUE;
	if (key == ctrl.d.key)
		game->ctrl.game.d.on = TRUE;
	if (key == ctrl.w.key)
		game->ctrl.game.w.on = TRUE;
	if (key == ctrl.s.key)
		game->ctrl.game.s.on = TRUE;
	if (key == ctrl.l.key)
		game->ctrl.game.l.on = TRUE;
	if (key == ctrl.r.key)
		game->ctrl.game.r.on = TRUE;
}

void	key_hooks_up(int key, void *param)
{
	t_game		*game;
	t_ctrl_game	ctrl;

	game = (t_game *)param;
	ctrl = game->ctrl.game;
	if (key == ctrl.escape.key)
		mlx_loop_end(game->mlx_ctx.mlx_ctx);
	if (key == ctrl.a.key)
		game->ctrl.game.a.on = FALSE;
	if (key == ctrl.d.key)
		game->ctrl.game.d.on = FALSE;
	if (key == ctrl.w.key)
		game->ctrl.game.w.on = FALSE;
	if (key == ctrl.s.key)
		game->ctrl.game.s.on = FALSE;
	if (key == ctrl.l.key)
		game->ctrl.game.l.on = FALSE;
	if (key == ctrl.r.key)
		game->ctrl.game.r.on = FALSE;
}

void	win_hooks(int event, void *param)
{
	if (event == 0)
		mlx_loop_end(((t_game *)param)->mlx_ctx.mlx_ctx);
}
