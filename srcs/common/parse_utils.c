/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcausseq <bcausseq@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 21:05:29 by salabbe           #+#    #+#             */
/*   Updated: 2026/02/17 19:43:59 by bcausseq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "cub3d.h"

#include "draw.h"

int	check_textures(t_texture *textures)
{
	if (!textures->no.path)
		return (0);
	if (!textures->so.path)
		return (0);
	if (!textures->we.path)
		return (0);
	if (!textures->ea.path)
		return (0);
	return (1);
}

int	check_colors(t_colors *colors)
{
	if (!colors->c_floor)
		return (0);
	if (!colors->c_ceiling)
		return (0);
	return (1);
}

int	ischarset(char *set, char c)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

void	skip_blank(char **map, int *start)
{
	int	i;

	while (map[*start])
	{
		i = 0;
		while (map[*start][i] && (map[*start][i] == ' '
			|| map[*start][i] == '\t'))
			i++;
		if (map[*start][i] != '\0')
			break ;
		(*start)++;
	}
}

int	count_lines(char **tab)
{
	int	j;

	j = 0;
	while (tab[j])
		j++;
	return (j);
}
