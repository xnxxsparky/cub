/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcausseq <bcausseq@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 19:02:35 by salabbe           #+#    #+#             */
/*   Updated: 2025/12/18 21:03:45 by bcausseq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static char	*set_data(char *line)
{
	int		i;

	i = 0;
	while (ft_isspace(line[i]))
		i++;
	if ((line[i] == 'C' || line[i] == 'F') && (ft_strlen(line) > 3))
		return (ft_substr(line, i + 2, ft_strlen(line)));
	else if (line[i] == '.' && line[i + 1] == '/')
		return (ft_substr(line, i + 2, ft_strlen(line)));
	return (NULL);
}

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
	}
	if (colors)
	{
		if (colors->c_floor)
			free(colors->c_floor);
		if (colors->c_ceiling)
			free(colors->c_ceiling);
	}
}

static int	set_data_map(t_game *game, int i, int j)
{
	char	*sub;

	sub = ft_substr(game->map.map[j], i, ft_strlchr(&game->map.map[j][i], ' '));
	if (!sub)
		return (1);
	if (game->texture.no.path == NULL && ft_strncmp(sub, "NO", 3) == 0)
		game->texture.no.path = set_data(&game->map.map[j][i + 2]);
	else if (game->texture.so.path == NULL && ft_strncmp(sub, "SO", 3) == 0)
		game->texture.so.path = set_data(&game->map.map[j][i + 2]);
	else if (game->texture.we.path == NULL && ft_strncmp(sub, "WE", 3) == 0)
		game->texture.we.path = set_data(&game->map.map[j][i + 2]);
	else if (game->texture.ea.path == NULL && ft_strncmp(sub, "EA", 3) == 0)
		game->texture.ea.path = set_data(&game->map.map[j][i + 2]);
	else if (game->colors.c_floor == NULL && ft_strncmp(sub, "F", 2) == 0)
		game->colors.c_floor = set_data(&game->map.map[j][i]);
	else if (game->colors.c_ceiling == NULL && ft_strncmp(sub, "C", 2) == 0)
		game->colors.c_ceiling = set_data(&game->map.map[j][i]);
	else if (ft_strlen(game->map.map[j]) > 0 && game->map.map[j][i] != '\0')
	{
		free(sub);
		free_data_texture(&game->colors, &game->texture);
		error(MAP, NULL);
	}
	free(sub);
	return (0);
}

static int	verify_data(t_game *game, int j)
{
	game->map.data_map = get_data_map(game->map.map, j, &(game->map.height));
	if (game->map.data_map == NULL)
	{
		free_data_texture(&game->colors, &game->texture);
		error(MAP, NULL);
	}
	get_player(&(game->map), &(game->player));
	if (parse_colors(&game->colors) == 1)
	{
		utl_super_free((void **)game->map.data_map);
		free_data_texture(&game->colors, &game->texture);
		error(COLORS, NULL);
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
		|| check_colors(&game->colors) == 0)
	{
		i = 0;
		while (ft_isspace(game->map.map[j][i]))
			i++;
		if (set_data_map(game, i, j) == 1)
			return (1);
		j++;
	}
	if (verify_data(game, j) == 1)
		return (1);
	return (0);
}
