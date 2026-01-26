/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcausseq <bcausseq@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 21:05:03 by salabbe           #+#    #+#             */
/*   Updated: 2025/12/22 21:39:27 by bcausseq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_name_file(char *filename)
{
	if (ft_strlen(filename) == 4)
	{
		ft_fprintf(1, "File need a name before extension\n");
		exit (1);
	}
	else if (!str_llstr(filename, ".cub", 4, (ft_strlen(filename) - 4)))
	{
		ft_fprintf(1, "The file doesnt have the extension .cub\n");
		exit (1);
	}
	return (0);
}

int	get_fd(char *filename, t_game *game)
{
	int	fd;

	fd = open(filename, O_DIRECTORY);
	if (fd > 0)
	{
		close(fd);
		error(DIRECTORY, filename, game, FALSE);
		return (-1);
	}
	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		error(BAD_FILE, filename, game, FALSE);
		return (-1);
	}
	return (fd);
}

static int	verify_paths(char *path, t_game *game)
{
	int	fd;

	fd = open(path, O_DIRECTORY);
	if (fd > 0)
	{
		close(fd);
		error(DIRECTORY, path, game, FALSE);
		return (-1);
	}
	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		utl_super_free((void **)game->map.data_map);
		error(BAD_FILE, path, game, TRUE);
		return (-1);
	}
	close(fd);
	return (fd);
}

int	check_textures_paths(t_texture *textures, t_game *game)
{
	if (verify_paths(textures->no.path, game) == -1)
		return (1);
	else if (verify_paths(textures->so.path, game) == -1)
		return (1);
	else if (verify_paths(textures->we.path, game) == -1)
		return (1);
	else if (verify_paths(textures->ea.path, game) == -1)
		return (1);
	else
		return (0);
}
