/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_bind_display.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcausseq <bcausseq@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 20:31:17 by bcausseq          #+#    #+#             */
/*   Updated: 2026/02/17 17:53:05 by bcausseq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "cub3d_bonus.h"
#include "bonus.h"

t_boolean	check_key_free(int key, t_game *game)
{
	const t_ctrl_game	g = game->ctrl.game;
	const t_ctrl_sett	s = game->ctrl.sett;
	const int			keys[16] = {g.w.key, g.a.key, g.s.key, g.d.key,
		g.l.key, g.r.key, g.oskour.key, g.pause.key, g.menu.key, g.escape.key,
		s.l.key, s.r.key, s.u.key, s.d.key, s.select.key, s.ret.key};
	int					i;

	i = -1;
	while (++i < 16)
	{
		if (key == keys[i])
			return (FALSE);
	}
	return (TRUE);
}

void	display_wait_bind(t_game *game)
{
	mlx_clear_window(game->mlx_ctx.mlx_ctx, game->mlx_ctx.win,
		(mlx_color){.rgba = 0x000000FF});
	ft_bufcpy(game->mlx_ctx.old_buf, game->mlx_ctx.buf);
	fifty_shade_of_grey(game->mlx_ctx.buf);
	mlx_string_put(game->mlx_ctx.mlx_ctx, game->mlx_ctx.win,
		game->menu.buttons[1].x, game->menu.buttons[1].y,
		(mlx_color){.rgba = 0x08CB00FF},
		"Please enter a key that isn't already in use");
}
