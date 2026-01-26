/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcausseq <bcausseq@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 21:05:17 by salabbe           #+#    #+#             */
/*   Updated: 2025/12/22 21:40:05 by bcausseq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

char	**get_map(int fd, int *width, t_game *game)
{
	char	**map;
	char	*line;
	char	*tmp;

	line = get_next_line(fd);
	if (line == NULL)
	{
		error(MAP, NULL, game, FALSE);
		return (NULL);
	}
	(*width) = ft_strlen(line);
	tmp = get_next_line(fd);
	while (tmp != NULL)
	{
		if ((int)ft_strlen(tmp) > (*width))
			(*width) = ft_strlen(tmp);
		line = ft_strjoin(line, tmp, 1, 1);
		tmp = get_next_line(fd);
	}
	map = ft_split(line, '\n');
	free(line);
	free(tmp);
	return (map);
}

static int	compare_char(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '1' && str[i] != '0' && str[i] != ' ' && str[i] != 'N'
			&& str[i] != 'S' && str[i] != 'W' && str[i] != 'E')
			return (1);
		i++;
	}
	return (0);
}

static int	map_closed(char **map, char *str, int x, int y)
{
	while (str[x])
	{
		if (ischarset("0NSWE", str[x]) == 1)
		{
			if (!map[y + 1] || x > (int)ft_strlen(map[y + 1])
				|| ischarset("10NSWE", map[y + 1][x]) == 0)
				return (1);
			if (!map[y - 1] || x > (int)ft_strlen(map[y - 1])
				|| ischarset("10NSWE", map[y - 1][x]) == 0)
				return (1);
			if (!map[y][x + 1] || ischarset("10NSWE", map[y][x + 1]) == 0)
				return (1);
			if (!map[y][x - 1] || ischarset("10NSWE", map[y][x - 1]) == 0)
				return (1);
		}
		x++;
	}
	return (0);
}

static int	parse_map_content(char **map, int j)
{
	int		i;
	int		player;

	player = 0;
	while (map[j])
	{
		i = 0;
		if (compare_char(&map[j][i]) || map_closed(map, map[j], i, j))
			return (1);
		else if (map[j][i] != '1' && map[j][i] != ' ')
			return (1);
		while (map[j][i])
		{
			if (map[j][i] == 'N' || map[j][i] == 'S'
				|| map[j][i] == 'W' || map[j][i] == 'E')
				player++;
			i++;
		}
		j++;
	}
	if (player != 1)
		return (1);
	return (0);
}

char	**get_data_map(char **map, int start, int *height)
{
	char	**data;
	int		j;

	skip_blank(map, &start);
	if (parse_map_content(map, start))
		return (NULL);
	data = malloc(sizeof(char *) * (count_lines(map) + 1));
	if (data == NULL)
		return (NULL);
	j = 0;
	while (map[start])
	{
		data[j] = ft_substr(map[start], 0, ft_strlen(map[start]));
		if (data[j] == NULL)
		{
			utl_super_free((void **)data);
			return (NULL);
		}
		j++;
		start++;
	}
	(*height) = j;
	data[j] = NULL;
	return (data);
}
