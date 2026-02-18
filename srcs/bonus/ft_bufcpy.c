/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bufcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcausseq <bcausseq@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 01:38:38 by bcausseq          #+#    #+#             */
/*   Updated: 2026/02/17 17:18:15 by bcausseq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "cub3d_bonus.h"

#include "window.h"

void	ft_bufcpy(mlx_color *src, mlx_color *dest)
{
	int	x;
	int	y;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
			dest[y * WIDTH + x] = src[y * WIDTH + x];
	}
}
