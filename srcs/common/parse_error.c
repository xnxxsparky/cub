/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcausseq <bcausseq@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 21:04:49 by salabbe           #+#    #+#             */
/*   Updated: 2026/02/18 12:34:58 by bcausseq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "cub3d.h"

#ifndef BONUS
# include "manda.h"
#else
# include "bonus.h"
#endif

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

void	error(char *type, char *arg, t_game *game)
{
	ft_fprintf(2, "%s ", type);
	if (arg)
		ft_fprintf(2, "\"%s\"\n", arg);
	free_errs(game);
	exit (1);
}
