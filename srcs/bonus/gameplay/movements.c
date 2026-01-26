/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcausseq <bcausseq@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 00:20:28 by bcausseq          #+#    #+#             */
/*   Updated: 2026/01/22 22:47:30 by bcausseq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	rotate_player(t_game *game, float angle)
{
	float	old_dir_x;
	float	old_cam_x;

	old_dir_x = 0.0f;
	old_cam_x = 0.0f;
	old_dir_x = game->player.dir_x;
	old_cam_x = game->player.cam_x;
	game->player.dir_x = game->player.dir_x * cos(angle)
		- game->player.dir_y * sin(angle);
	game->player.dir_y = old_dir_x * sin(angle)
		+ game->player.dir_y * cos(angle);
	game->player.cam_x = game->player.cam_x * cos(angle)
		- game->player.cam_y * sin(angle);
	game->player.cam_y = old_cam_x * sin(angle)
		+ game->player.cam_y * cos(angle);
}

void	rotate(t_game *game)
{
	float	angle;

	angle = 0.0f;
	if (game->ctrl.l)
		angle = -ROT_SPEED;
	if (game->ctrl.r)
		angle = ROT_SPEED;
	if (angle != 0.0f)
		rotate_player(game, angle);
}

void	cross_pad(t_game *game, float *move_x, float *move_y)
{
	if (game->ctrl.w)
	{
		(*move_x) += game->player.dir_x * MOV_SPEED;
		(*move_y) += game->player.dir_y * MOV_SPEED;
	}
	if (game->ctrl.s)
	{
		(*move_x) -= game->player.dir_x * MOV_SPEED;
		(*move_y) -= game->player.dir_y * MOV_SPEED;
	}
	if (game->ctrl.d)
	{
		(*move_x) += game->player.cam_x * MOV_SPEED;
		(*move_y) += game->player.cam_y * MOV_SPEED;
	}
	if (game->ctrl.a)
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
