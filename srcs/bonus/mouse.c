/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcausseq <bcausseq@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 21:46:42 by bcausseq          #+#    #+#             */
/*   Updated: 2026/01/26 21:58:00 by bcausseq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"
#include "mlx.h"

static t_boolean	init_mouse_pos(t_game *game, int c_x, int c_y)
{
	if (!game->mouse.captured)
	{
		game->mouse.x = c_x;
		game->mouse.y = c_y;
		game->mouse.captured = TRUE;
		return (TRUE);
	}
	return (FALSE);
}

void	update_mouse(t_game *game)
{
	float	delta;
	int		c_x;
	int		c_y;

	mlx_mouse_get_pos(game->mlx_ctx.mlx_ctx, &c_x, &c_y);
	if (init_mouse_pos(game, c_x, c_y))
		return ;
	delta = (c_x - game->mouse.old_x) * SENSITIVITY;
	if (fabs(delta) > 0.001f)
		rotate_player(game, delta);
	if (!game->ctrl.oskour)
	{
		mlx_mouse_move(game->mlx_ctx.mlx_ctx, game->mlx_ctx.win,
			WIDTH / 2, HEIGHT / 2);
		game->mouse.old_x = WIDTH / 2;
		game->mouse.old_y = HEIGHT / 2;
	}
	else
	{
		game->mouse.old_x = c_x;
		game->mouse.old_y = c_y;
	}
}

void	init_mouse(t_game *game)
{
	game->mouse.x = WIDTH / 2;
	game->mouse.y = HEIGHT / 2;
	game->mouse.old_x = HEIGHT / 2;
	game->mouse.old_y = WIDTH / 2;
	game->mouse.captured = FALSE;
	mlx_mouse_hide(game->mlx_ctx.mlx_ctx);
}
