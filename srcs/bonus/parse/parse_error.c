/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcausseq <bcausseq@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 21:04:49 by salabbe           #+#    #+#             */
/*   Updated: 2025/12/22 21:38:56 by bcausseq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	free_errs(t_game *game)
{
	int	i;

	if (game->map.map)
	{
		i = -1;
		while (game->map.map[++i])
			free(game->map.map[i]);
		free(game->map.map);
	}
}

void	error(char *type, char *arg, t_game *game, t_boolean free_n)
{
	ft_fprintf(2, "%s ", type);
	if (arg)
		ft_fprintf(2, "\"%s\"\n", arg);
	if (free_n)
		free_data_texture(&(game->colors), &(game->texture));
	free_errs(game);
	exit (1);
}
