/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_change.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcausseq <bcausseq@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 01:25:34 by bcausseq          #+#    #+#             */
/*   Updated: 2026/02/17 17:58:06 by bcausseq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "cub3d_bonus.h"
#include "bonus.h"

void	update_state(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (game->curr_state == NORMAL_STATE)
		cast_rays((void *)game);
	else if (game->curr_state == MENU_STATE)
		menu_draw(game);
	else if (game->curr_state == KEYBNG_GAME_STATE)
		keybind_draw(game);
	else if (game->curr_state == KEYBNG_SETT_STATE)
		sett_keybind_draw(game);
	else if (game->curr_state == WAITING_GAME_STATE)
		display_wait_bind(game);
	else if (game->curr_state == WAITING_SETT_STATE)
		display_wait_bind(game);
}

void	handle_pause(t_game *game)
{
	static int	i;

	i++;
	if (i % 2 && game->curr_state == NORMAL_STATE)
	{
		game->curr_state = PAUSE_STATE;
		mlx_mouse_show(game->mlx_ctx.mlx_ctx);
	}
	else
	{
		game->curr_state = NORMAL_STATE;
		mlx_mouse_hide(game->mlx_ctx.mlx_ctx);
	}
}

void	handle_menu(t_game *game)
{
	if (game->curr_state == NORMAL_STATE)
	{
		ft_bufcpy(game->mlx_ctx.buf, game->mlx_ctx.old_buf);
		game->curr_state = MENU_STATE;
		mlx_mouse_show(game->mlx_ctx.mlx_ctx);
	}
	else
	{
		game->curr_state = NORMAL_STATE;
		mlx_mouse_hide(game->mlx_ctx.mlx_ctx);
	}
}

void	state_key_hooks_dwn(int key, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (game->curr_state == NORMAL_STATE)
		game_key_hooks_dwn(key, game);
	else if (game->curr_state == MENU_STATE)
		menu_key_hooks_dwn(key, game);
	else if (game->curr_state == PAUSE_STATE)
		pause_key_hooks_dwn(key, game);
	else if (game->curr_state == KEYBNG_GAME_STATE)
		keybind_key_hooks_dwn(key, game);
	else if (game->curr_state == KEYBNG_SETT_STATE)
		sett_keybind_key_hooks_dwn(key, game);
	else if (game->curr_state == WAITING_GAME_STATE)
		waiting(key, game);
	else if (game->curr_state == WAITING_SETT_STATE)
		sett_waiting(key, game);
}

void	pause_key_hooks_dwn(int key, t_game *game)
{
	if (key == game->ctrl.game.pause.key)
		handle_pause(game);
	else if (key == game->ctrl.game.escape.key)
		mlx_loop_end(game->mlx_ctx.mlx_ctx);
}
