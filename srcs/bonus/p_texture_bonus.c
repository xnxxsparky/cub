/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_texture_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcausseq <bcausseq@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 19:02:35 by salabbe           #+#    #+#             */
/*   Updated: 2026/02/18 02:11:34 by bcausseq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "cub3d_bonus.h"

#include "bonus.h"

void	free_data_texture(t_colors *colors, t_texture *textures)
{
	if (textures)
	{
		if (textures->no.path)
			free(textures->no.path);
		if (textures->so.path)
			free(textures->so.path);
		if (textures->we.path)
			free(textures->we.path);
		if (textures->ea.path)
			free(textures->ea.path);
		if (textures->door.path)
			free(textures->door.path);
		textures = NULL;
	}
	if (colors)
	{
		if (colors->c_floor)
			free(colors->c_floor);
		if (colors->c_ceiling)
			free(colors->c_ceiling);
		colors = NULL;
	}
}

static int	verify_data(t_game *game, int j)
{
	game->map.data_map = get_data_map(game->map.map, j, &(game->map.height));
	if (game->map.data_map == NULL)
	{
		free_data_texture(&game->colors, &game->texture);
		error(MAP, NULL, game);
	}
	get_player(&(game->map), &(game->player));
	if (parse_colors(&game->colors) == 1)
	{
		utl_super_free((void **)game->map.data_map);
		free_data_texture(&game->colors, &game->texture);
		error(COLORS, NULL, game);
	}
	else
		return (0);
	return (1);
}

int	define_data_map(t_game *game)
{
	int		i;
	int		j;

	j = 0;
	while ((game->map.map[j] && check_textures(&game->texture) == 0)
		|| check_colors(&game->colors) == 0 || check_door(&game->texture) == 0)
	{
		i = 0;
		while (ft_isspace(game->map.map[j][i]))
			i++;
		if (set_data_all(game, i, j))
			return (1);
		j++;
	}
	if (verify_data(game, j) == 1)
		return (1);
	return (0);
}
