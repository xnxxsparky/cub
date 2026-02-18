/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcausseq <bcausseq@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 00:16:28 by bcausseq          #+#    #+#             */
/*   Updated: 2026/02/17 19:26:10 by bcausseq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "cub3d_bonus.h"

#include "bonus.h"

// void	key_hooks_dwn(int key, void *param)
// {
// 	t_game	*game;
// 
// 	game = (t_game *)param;
// 	if (key == SDL_SCANCODE_ESCAPE)
// 		mlx_loop_end(game->mlx_ctx.mlx_ctx);
// 	else if (key == SDL_SCANCODE_A)
// 		game->ctrl.a = TRUE;
// 	else if (key == SDL_SCANCODE_D)
// 		game->ctrl.d = TRUE;
// 	else if (key == SDL_SCANCODE_W)
// 		game->ctrl.w = TRUE;
// 	else if (key == SDL_SCANCODE_S)
// 		game->ctrl.s = TRUE;
// 	else if (key == SDL_SCANCODE_LEFT)
// 		game->ctrl.l = TRUE;
// 	else if (key == SDL_SCANCODE_RIGHT)
// 		game->ctrl.r = TRUE;
// 	else if (key == SDL_SCANCODE_LALT)
// 		game->ctrl.oskour = TRUE;
// 	else if (key == SDL_SCANCODE_P)
// 		handle_pause(game);
// 	else if (key == SDL_SCANCODE_F1)
// 		handle_menu(game);
// }

// void	key_hooks_up(int key, void *param)
// {
// 	t_game	*game;
// 
// 	game = (t_game *)param;
// 	if (key == SDL_SCANCODE_A)
// 		game->ctrl.a = FALSE;
// 	if (key == SDL_SCANCODE_D)
// 		game->ctrl.d = FALSE;
// 	if (key == SDL_SCANCODE_W)
// 		game->ctrl.w = FALSE;
// 	if (key == SDL_SCANCODE_S)
// 		game->ctrl.s = FALSE;
// 	if (key == SDL_SCANCODE_LEFT)
// 		game->ctrl.l = FALSE;
// 	if (key == SDL_SCANCODE_RIGHT)
// 		game->ctrl.r = FALSE;
// 	if (key == SDL_SCANCODE_LALT)
// 		game->ctrl.oskour = FALSE;
// }

void	win_hooks(int event, void *param)
{
	if (event == 0)
		mlx_loop_end(((t_game *)param)->mlx_ctx.mlx_ctx);
}
