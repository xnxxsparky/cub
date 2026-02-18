/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_up.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcausseq <bcausseq@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 22:08:04 by bcausseq          #+#    #+#             */
/*   Updated: 2026/02/17 19:26:53 by bcausseq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "cub3d_bonus.h"
#include "bonus.h"

void	game_key_hooks_up(int key, t_game *game)
{
	if (key == game->ctrl.game.a.key)
		game->ctrl.game.a.on = FALSE;
	if (key == game->ctrl.game.s.key)
		game->ctrl.game.s.on = FALSE;
	if (key == game->ctrl.game.w.key)
		game->ctrl.game.w.on = FALSE;
	if (key == game->ctrl.game.d.key)
		game->ctrl.game.d.on = FALSE;
	if (key == game->ctrl.game.l.key)
		game->ctrl.game.l.on = FALSE;
	if (key == game->ctrl.game.r.key)
		game->ctrl.game.r.on = FALSE;
	if (key == game->ctrl.game.oskour.key)
		game->ctrl.game.oskour.on = FALSE;
}

void	state_key_hooks_up(int key, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (game->curr_state == NORMAL_STATE)
		game_key_hooks_up(key, game);
	else if (game->curr_state == MENU_STATE)
		;
	else if (game->curr_state == KEYBNG_GAME_STATE)
		;
}
