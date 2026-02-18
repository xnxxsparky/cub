/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings_keybind_hooks.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcausseq <bcausseq@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 00:49:24 by bcausseq          #+#    #+#             */
/*   Updated: 2026/02/17 18:11:53 by bcausseq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "cub3d_bonus.h"

#include "bonus.h"

void	sett_keybind_key_hooks_dwn_p2(int key, t_game *game)
{
	if (key == game->ctrl.sett.d.key)
	{
		if (game->set_bind.index_select == game->set_bind.nb_buttons - 1)
			game->curr_state = KEYBNG_GAME_STATE;
		else if (game->set_bind.index_select + 2 < game->set_bind.nb_buttons)
			game->set_bind.index_select += 2;
	}
	else if (key == game->ctrl.sett.select.key)
		game->set_bind.buttons[game->set_bind.index_select].action(game);
	else if (key == game->ctrl.sett.ret.key)
		game->curr_state = MENU_STATE;
}

void	sett_keybind_key_hooks_dwn(int key, t_game *game)
{
	if (key == game->ctrl.sett.l.key)
	{
		game->set_bind.index_select--;
		if (game->set_bind.index_select < 0)
			game->set_bind.index_select = game->set_bind.nb_buttons - 1;
	}
	else if (key == game->ctrl.sett.r.key)
	{
		game->set_bind.index_select++;
		if (game->set_bind.index_select > game->set_bind.nb_buttons - 1)
			game->set_bind.index_select = 0;
	}
	else if (key == game->ctrl.sett.u.key)
	{
		if (game->set_bind.index_select == 0)
			game->curr_state = KEYBNG_GAME_STATE;
		else if (game->set_bind.index_select - 2 >= 0)
			game->set_bind.index_select -= 2;
	}
	sett_keybind_key_hooks_dwn_p2(key, game);
}
