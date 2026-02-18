/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_dwn.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcausseq <bcausseq@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 21:41:01 by bcausseq          #+#    #+#             */
/*   Updated: 2026/02/17 19:26:37 by bcausseq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "cub3d_bonus.h"

#include "bonus.h"

void	game_key_hooks_dwn(int key, t_game *game)
{
	const t_ctrl_game	ctrl = game->ctrl.game;

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
	if (key == ctrl.oskour.key)
		game->ctrl.game.oskour.on = TRUE;
	else if (key == ctrl.pause.key)
		handle_pause(game);
	else if (key == ctrl.menu.key)
		handle_menu(game);
}

void	menu_key_hooks_dwn(int key, t_game *game)
{
	const t_ctrl_sett	ctrl = game->ctrl.sett;

	if (key == game->ctrl.game.menu.key)
		handle_menu(game);
	else if (key == ctrl.u.key)
	{
		game->menu.index_select--;
		if (game->menu.index_select < 0)
			game->menu.index_select = game->menu.nb_buttons - 1;
	}
	else if (key == ctrl.d.key)
	{
		game->menu.index_select++;
		if (game->menu.index_select > game->menu.nb_buttons - 1)
			game->menu.index_select = 0;
	}
	else if (key == ctrl.select.key)
		game->menu.buttons[game->menu.index_select].action(game);
	else if (key == ctrl.ret.key)
		handle_menu(game);
}

void	keybind_key_hooks_dwn_p2(int key, t_game *game)
{
	if (key == game->ctrl.sett.d.key)
	{
		if (game->key_bind.index_select == game->key_bind.nb_buttons - 1)
			game->curr_state = KEYBNG_SETT_STATE;
		if (game->key_bind.index_select == 7)
			game->key_bind.index_select += 2;
		else if (game->key_bind.index_select + 3 < game->key_bind.nb_buttons)
			game->key_bind.index_select += 3;
	}
	else if (key == game->ctrl.sett.select.key)
		game->key_bind.buttons[game->key_bind.index_select].action(game);
	else if (key == game->ctrl.sett.ret.key)
		game->curr_state = MENU_STATE;
}

void	keybind_key_hooks_dwn(int key, t_game *game)
{
	if (key == game->ctrl.sett.l.key)
	{
		game->key_bind.index_select--;
		if (game->key_bind.index_select < 0)
			game->key_bind.index_select = game->key_bind.nb_buttons - 1;
	}
	else if (key == game->ctrl.sett.r.key)
	{
		game->key_bind.index_select++;
		if (game->key_bind.index_select > game->key_bind.nb_buttons - 1)
			game->key_bind.index_select = 0;
	}
	else if (key == game->ctrl.sett.u.key)
	{
		if (game->key_bind.index_select == 0)
			game->curr_state = KEYBNG_SETT_STATE;
		if (game->key_bind.index_select == game->key_bind.nb_buttons - 1)
			game->key_bind.index_select -= 2;
		else if (game->key_bind.index_select - 3 >= 0)
			game->key_bind.index_select -= 3;
	}
	keybind_key_hooks_dwn_p2(key, game);
}

void	waiting(int key, t_game *game)
{
	if (check_key_free(key, game) == FALSE)
		return ;
	if (game->key_bind.index_select == 0)
		game->ctrl.game.w.key = key;
	else if (game->key_bind.index_select == 1)
		game->ctrl.game.a.key = key;
	else if (game->key_bind.index_select == 2)
		game->ctrl.game.s.key = key;
	else if (game->key_bind.index_select == 3)
		game->ctrl.game.d.key = key;
	else if (game->key_bind.index_select == 4)
		game->ctrl.game.l.key = key;
	else if (game->key_bind.index_select == 5)
		game->ctrl.game.r.key = key;
	else if (game->key_bind.index_select == 6)
		game->ctrl.game.oskour.key = key;
	else if (game->key_bind.index_select == 7)
		game->ctrl.game.pause.key = key;
	else if (game->key_bind.index_select == 8)
		game->ctrl.game.menu.key = key;
	else if (game->key_bind.index_select == 9)
		game->ctrl.game.escape.key = key;
	game->curr_state = KEYBNG_GAME_STATE;
}
