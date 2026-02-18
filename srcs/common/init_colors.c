/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_colors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcausseq <bcausseq@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 21:03:52 by salabbe           #+#    #+#             */
/*   Updated: 2026/02/17 23:03:51 by bcausseq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "cub3d.h"
#ifndef BONUS
# include "manda.h"
#else
# include "bonus.h"
#endif

void	init_colors(t_game *game)
{
	game->colors.c_floor = NULL;
	game->colors.c_ceiling = NULL;
}
