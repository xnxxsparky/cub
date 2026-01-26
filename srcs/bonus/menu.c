/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcausseq <bcausseq@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 20:08:06 by bcausseq          #+#    #+#             */
/*   Updated: 2026/01/26 18:20:17 by bcausseq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	menu_draw(t_game *game)
{
	int	x;
	int	y;

	if (game->curr_state != MENU_STATE)
		return ;
	x = -1;
	y = -1;
	mlx_clear_window(game->mlx_ctx.mlx_ctx, game->mlx_ctx.win,
		(mlx_color){.rgba = 0x000000FF});
	while (++y < HEIGHT)
	{
		while (++x < WIDTH)
		{
			if (y >= 0 && y < HEIGHT && x >= 0 && x < WIDTH)
				game->mlx_ctx.buf[y * WIDTH + x].a = 0x88;
		}
		x = -1;
	}
	mlx_set_image_region(game->mlx_ctx.mlx_ctx, game->mlx_ctx.img,
		0, 0, WIDTH, HEIGHT, game->mlx_ctx.buf);
	mlx_put_image_to_window(game->mlx_ctx.mlx_ctx, game->mlx_ctx.win,
		game->mlx_ctx.img, 0, 0);
}
