/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcausseq <bcausseq@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 21:23:57 by bcausseq          #+#    #+#             */
/*   Updated: 2025/12/18 12:56:12 by bcausseq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	get_player_data(t_map *map, t_player *player, int x, int y)
{
	player->pos_x = x + 0.5;
	player->pos_y = y + 0.5;
	if (map->data_map[y][x] == 'N' || map->data_map[y][x] == 'S')
	{
		if (map->data_map[y][x] == 'N')
			player->dir_y = -1;
		else
			player->dir_y = 1;
		player->dir_x = 0;
	}
	else
	{
		if (map->data_map[y][x] == 'W')
			player->dir_x = -1;
		else
			player->dir_x = 1;
		player->dir_y = 0;
	}
	map->data_map[y][x] = '0';
	player->cam_x = 0.66;
	player->cam_y = 0.0;
}

void	get_player(t_map *map, t_player *player)
{
	int		x;
	int		y;
	int		len;
	char	c;

	y = -1;
	while (++y < map->height)
	{
		len = ft_strlen(map->data_map[y]);
		x = -1;
		while (++x < len)
		{
			c = map->data_map[y][x];
			if (c && (c == 'N' || c == 'S' || c == 'W' || c == 'E'))
			{
				get_player_data(map, player, x, y);
				return ;
			}
		}
	}
}
