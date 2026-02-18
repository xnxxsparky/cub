/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcausseq <bcausseq@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 02:03:46 by bcausseq          #+#    #+#             */
/*   Updated: 2026/02/17 18:10:58 by bcausseq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "cub3d_bonus.h"
#include "bonus.h"

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
	if (game->ctrl.game.l.on)
		angle = -ROT_SPEED;
	if (game->ctrl.game.r.on)
		angle = ROT_SPEED;
	if (angle != 0.0f)
		rotate_player(game, angle);
}
