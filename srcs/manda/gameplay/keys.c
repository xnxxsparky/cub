/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcausseq <bcausseq@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 00:16:28 by bcausseq          #+#    #+#             */
/*   Updated: 2025/12/11 00:17:39 by bcausseq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	key_hooks_dwn(int key, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (key == SDL_SCANCODE_ESCAPE)
		mlx_loop_end(game->mlx_ctx.mlx_ctx);
	if (key == SDL_SCANCODE_A)
		game->ctrl.a = TRUE;
	if (key == SDL_SCANCODE_D)
		game->ctrl.d = TRUE;
	if (key == SDL_SCANCODE_W)
		game->ctrl.w = TRUE;
	if (key == SDL_SCANCODE_S)
		game->ctrl.s = TRUE;
	if (key == SDL_SCANCODE_LEFT)
		game->ctrl.l = TRUE;
	if (key == SDL_SCANCODE_RIGHT)
		game->ctrl.r = TRUE;
}

void	key_hooks_up(int key, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (key == SDL_SCANCODE_A)
		game->ctrl.a = FALSE;
	if (key == SDL_SCANCODE_D)
		game->ctrl.d = FALSE;
	if (key == SDL_SCANCODE_W)
		game->ctrl.w = FALSE;
	if (key == SDL_SCANCODE_S)
		game->ctrl.s = FALSE;
	if (key == SDL_SCANCODE_LEFT)
		game->ctrl.l = FALSE;
	if (key == SDL_SCANCODE_RIGHT)
		game->ctrl.r = FALSE;
}

void	win_hooks(int event, void *param)
{
	if (event == 0)
		mlx_loop_end(((t_game *)param)->mlx_ctx.mlx_ctx);
}
