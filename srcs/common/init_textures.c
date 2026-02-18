/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcausseq <bcausseq@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 21:04:21 by salabbe           #+#    #+#             */
/*   Updated: 2026/02/18 00:58:57 by bcausseq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "cub3d.h"

#ifndef BONUS
# include "manda.h"
void	init_textures(t_game *game)
{
	game->texture.no.path = NULL;
	game->texture.so.path = NULL;
	game->texture.ea.path = NULL;
	game->texture.we.path = NULL;
}
#else
# include "bonus.h"
void	init_textures(t_game *game)
{
	game->texture.no.path = NULL;
	game->texture.so.path = NULL;
	game->texture.ea.path = NULL;
	game->texture.we.path = NULL;
	game->texture.door.path = NULL;
}
#endif

