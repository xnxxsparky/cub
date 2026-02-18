/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcausseq <bcausseq@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 15:08:32 by bcausseq          #+#    #+#             */
/*   Updated: 2026/02/17 20:14:22 by bcausseq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

# define MOV_SPEED 0.025f
# define ROT_SPEED 0.015f
# define THICKNESS 0.125f
# define SENSITIVITY 0.0021f

# include "draw.h"
# include "controls.h"
# include "window.h"

void
get_player(t_map *map, t_player *player);

char
**dup_map(void);

void
init_colors(t_game *game);

void
init_textures(t_game *game);

char
**get_map(int fd, int *width, t_game *game);

char
**get_data_map(char**map, int start, int *width);

int
init_data(t_game *game);

int
parse_colors(t_colors *colors);

int
check_name_file(char *filename);

int
get_fd(char *filename, t_game *game);

int
define_data_map(t_game *game);

int
check_textures_paths(t_texture *textures, t_game *game);

int
free_game(t_game *game);

#endif
