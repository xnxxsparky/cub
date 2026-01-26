/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_door_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcausseq <bcausseq@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 20:46:43 by salabbe           #+#    #+#             */
/*   Updated: 2026/01/22 20:47:24 by bcausseq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static char	*set_data(char *line)
{
	int		i;

	i = 0;
	while (ft_isspace(line[i]))
		i++;
	if ((line[i] == 'D' || line[i] == 'F' || line[i] == 'C')
		&& (ft_strlen(line) > 3))
		return (ft_substr(line, i + 2, ft_strlen(line)));
	else if (line[i] == '.' && line[i + 1] == '/')
		return (ft_substr(line, i + 2, ft_strlen(line)));
	return (NULL);
}

int	check_door(t_texture *texture)
{
	if (!texture->door.path)
		return (0);
	return (1);
}

static int	setter_data(t_game *game, int i, int j, char *sub)
{
	if (game->texture.no.path == NULL && ft_strncmp(sub, "NO", 3) == 0)
		game->texture.no.path = set_data(&game->map.map[j][i + 2]);
	else if (game->texture.so.path == NULL && ft_strncmp(sub, "SO", 3) == 0)
		game->texture.so.path = set_data(&game->map.map[j][i + 2]);
	else if (game->texture.we.path == NULL && ft_strncmp(sub, "WE", 3) == 0)
		game->texture.we.path = set_data(&game->map.map[j][i + 2]);
	else if (game->texture.ea.path == NULL && ft_strncmp(sub, "EA", 3) == 0)
		game->texture.ea.path = set_data(&game->map.map[j][i + 2]);
	else if (game->texture.door.path == NULL && ft_strncmp(sub, "D", 2) == 0)
		game->texture.door.path = set_data(&game->map.map[j][i]);
	else if (game->colors.c_floor == NULL && ft_strncmp(sub, "F", 2) == 0)
		game->colors.c_floor = set_data(&game->map.map[j][i]);
	else if (game->colors.c_ceiling == NULL && ft_strncmp(sub, "C", 2) == 0)
		game->colors.c_ceiling = set_data(&game->map.map[j][i]);
	else if (ft_strlen(game->map.map[j]) > 0 && game->map.map[j][i] != '\0')
	{
		free(sub);
		free_data_texture(&game->colors, &game->texture);
		error(MAP, NULL, game, FALSE);
	}
	return (0);
}

int	set_data_all(t_game *game, int i, int j)
{
	char	*sub;

	sub = ft_substr(game->map.map[j], i, ft_strlchr(&game->map.map[j][i], ' '));
	if (!sub)
		return (1);
	setter_data(game, i, j, sub);
	free(sub);
	return (0);
}
