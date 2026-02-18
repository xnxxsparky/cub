/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcausseq <bcausseq@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 00:20:28 by bcausseq          #+#    #+#             */
/*   Updated: 2026/02/17 19:28:44 by bcausseq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "cub3d_bonus.h"

#include "bonus.h"

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

void	cross_pad(t_game *game, float *move_x, float *move_y)
{
	if (game->ctrl.game.w.on)
	{
		(*move_x) += game->player.dir_x * MOV_SPEED;
		(*move_y) += game->player.dir_y * MOV_SPEED;
	}
	if (game->ctrl.game.s.on)
	{
		(*move_x) -= game->player.dir_x * MOV_SPEED;
		(*move_y) -= game->player.dir_y * MOV_SPEED;
	}
	if (game->ctrl.game.d.on)
	{
		(*move_x) += game->player.cam_x * MOV_SPEED;
		(*move_y) += game->player.cam_y * MOV_SPEED;
	}
	if (game->ctrl.game.a.on)
	{
		(*move_x) -= game->player.cam_x * MOV_SPEED;
		(*move_y) -= game->player.cam_y * MOV_SPEED;
	}
}

t_boolean	collides(char **data_map, int type, float y_pos, float x_pos)
{
	if (type & NEW_X && type & NEW_Y)
	{
		if (data_map[(int)(y_pos + THICKNESS)][(int)(x_pos + THICKNESS)] == '1'
			|| data_map[(int)(y_pos - THICKNESS)][(int)(x_pos - THICKNESS)]
			== '1')
			return (TRUE);
		if (data_map[(int)(y_pos - THICKNESS)][(int)(x_pos + THICKNESS)] == '1'
			|| data_map[(int)(y_pos + THICKNESS)][(int)(x_pos - THICKNESS)]
			== '1')
			return (TRUE);
	}
	else if (type & NEW_Y)
	{
		if (data_map[(int)(y_pos + THICKNESS)][(int)x_pos] == '1'
			|| data_map[(int)(y_pos - THICKNESS)][(int)x_pos] == '1')
			return (TRUE);
	}
	else if (type & NEW_X)
	{
		if (data_map[(int)y_pos][(int)(x_pos + THICKNESS)] == '1'
			|| data_map[(int)y_pos][(int)(x_pos - THICKNESS)] == '1')
			return (TRUE);
	}
	return (FALSE);
}

void	border_check(t_game *game, float new_x, float new_y)
{
	if (new_x >= 0 && new_x < game->map.width)
	{
		if (!collides(game->map.data_map, NEW_X, game->player.pos_y, new_x))
			game->player.pos_x = new_x;
	}
	if (new_y >= 0 && new_y < game->map.height)
	{
		if (!collides(game->map.data_map, NEW_Y, new_y, game->player.pos_x))
			game->player.pos_y = new_y;
	}
	if (new_x >= 0 && new_x < game->map.width
		&& new_y >= 0 && new_y < game->map.height)
	{
		if (!collides(game->map.data_map, (NEW_X | NEW_Y), new_y, new_x))
		{
			game->player.pos_x = new_x;
			game->player.pos_y = new_y;
		}
	}
}

void	move(t_game *game)
{
	float	new_x;
	float	new_y;
	float	move_x;
	float	move_y;

	new_x = 0.0f;
	new_y = 0.0f;
	move_x = 0.0f;
	move_y = 0.0f;
	cross_pad(game, &move_x, &move_y);
	update_mouse(game);
	rotate(game);
	if (move_x != 0.0f || move_y != 0.0f)
	{
		new_x = game->player.pos_x + move_x;
		new_y = game->player.pos_y + move_y;
		border_check(game, new_x, new_y);
	}
}
