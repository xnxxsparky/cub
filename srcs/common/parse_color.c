/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcausseq <bcausseq@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 21:04:36 by salabbe           #+#    #+#             */
/*   Updated: 2026/02/17 19:37:52 by bcausseq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "cub3d.h"

#include "draw.h"

static int	check_comma(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == ',' && !str[i + 1])
			return (1);
		if (str[i] == ',' && str[i + 1])
		{
			if (str[i + 1] == ',')
				return (1);
		}
		i++;
	}
	return (0);
}

static int	check_decimal_colors(mlx_color *i_colors, char **color)
{
	int		i;
	int		i_stash;

	i = 0;
	while (color[i])
	{
		i_stash = ft_atoi(color[i]);
		if (i_stash < 0 || i_stash > 255)
			return (1);
		if (i == 0)
			i_colors->r = i_stash;
		else if (i == 1)
			i_colors->g = i_stash;
		else if (i == 2)
			i_colors->b = i_stash;
		i++;
	}
	if (i != 3)
		return (1);
	return (0);
}

int	parse_colors(t_colors *colors)
{
	char	**floor;
	char	**ceil;

	if (check_comma(colors->c_floor) == 1
		|| check_comma(colors->c_ceiling) == 1)
		return (1);
	floor = ft_split(colors->c_floor, ',');
	if (floor == NULL || floor[0] == NULL)
		return (1);
	ceil = ft_split(colors->c_ceiling, ',');
	if (ceil == NULL || ceil[0] == NULL)
		return (1);
	if (check_decimal_colors(&(colors->floor), floor) == 1
		|| check_decimal_colors(&(colors->ceiling), ceil) == 1)
	{
		utl_super_free((void **)floor);
		utl_super_free((void **)ceil);
		return (1);
	}
	utl_super_free((void **)floor);
	utl_super_free((void **)ceil);
	return (0);
}
