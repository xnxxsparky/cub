/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcausseq <bcausseq@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 21:04:06 by salabbe           #+#    #+#             */
/*   Updated: 2025/12/22 20:34:03 by bcausseq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	init_data(t_game *game)
{
	game->map.map = get_map(game->fd, &(game->map.width), game);
	close(game->fd);
	if (game->map.map == NULL)
		return (1);
	if (define_data_map(game) == 1)
	{
		utl_super_free((void **)game->map.map);
		return (1);
	}
	if (check_textures_paths(&game->texture, game) == 1)
	{
		utl_super_free((void **)game->map.map);
		free_data_texture(&game->colors, &game->texture);
		return (1);
	}
	return (0);
}
