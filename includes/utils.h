/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcausseq <bcausseq@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 15:32:59 by bcausseq          #+#    #+#             */
/*   Updated: 2026/02/18 00:57:14 by bcausseq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# define EXTENSION "Error : INVALID FILE EXTENSION\nUSAGE : exemple_map[.cub]\n"
# define BAD_FILE "Error : ISSUE REGARDING FILE :\n"
# define DIRECTORY "Error : FORMAT IS A DIRECTORY :\n"
# define MAP "Error : INVALID DATA MAP\n"
# define ARGS "Error : INVALID ARGUMENT\nUSAGE : ./cub3d [map.cub]\n"
# define MLX "Error : ISSUE REGARDING MLX\n"
# define COLORS "ERROR : INVALID COLOR(S)\n"

# define FALSE '\0'
# define TRUE 'Y'
# define NEW_X 0b01
# define NEW_Y 0b10
# define HIT_NONE 0
# define HIT_WALL 1

# include "../third_parties/libft/includes/libft.h"
# include "SDL2/SDL_scancode.h"

typedef char	t_boolean;
typedef struct s_game t_game;

typedef struct s_map
{
	char	**map;
	char	**data_map;
	int		height;
	int		width;
	char	spawn;
	int		pos_door_x;
	int		pos_door_y;
}	t_map;

void
error(char *type, char *arg, t_game *game);

int
ischarset(char *set, char c);

void
skip_blank(char **map, int *start);

int
count_lines(char **tab);

// int
// compare_char(char *str);
// 
// int
// map_closed(char **map, char *str, int x, int y);

#endif
