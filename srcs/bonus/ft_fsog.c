/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fsog.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcausseq <bcausseq@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 01:05:08 by bcausseq          #+#    #+#             */
/*   Updated: 2026/01/31 01:05:45 by bcausseq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	fifty_shade_of_grey(t_game *game)
{
	int	x;
	int	y;

	x = -1;
	y = -1;
	while (++y < HEIGHT)
	{
		while (++x < WIDTH)
		{
			if (y >= 0 && y < HEIGHT && x >= 0 && x < WIDTH)
				game->mlx_ctx.buf[y * WIDTH + x].a = 0x88;
		}
		x = -1;
	}
}
