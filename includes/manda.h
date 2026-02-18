/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manda.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcausseq <bcausseq@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 19:38:44 by bcausseq          #+#    #+#             */
/*   Updated: 2026/02/18 12:23:21 by bcausseq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MANDA_H
# define MANDA_H

# include "utils.h"
# include "window.h"
# include "draw.h"
# include "controls.h"
# include "game.h"

typedef struct s_game
{
	t_texture			texture;
	t_current_texture	cur_text;
	t_map				map;
	t_player			player;
	t_mlx				mlx_ctx;
	t_ctrl				ctrl;
	t_colors			colors;
	char				*filename;
	int					fd;
}	t_game;

void
clear_buffers(t_texture texture);

#endif
