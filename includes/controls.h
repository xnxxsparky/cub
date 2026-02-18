/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcausseq <bcausseq@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 15:07:06 by bcausseq          #+#    #+#             */
/*   Updated: 2026/02/17 20:32:14 by bcausseq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTROLS_H
# define CONTROLS_H

# include "utils.h"

typedef struct s_game t_game;

typedef struct s_ctrl_ind
{
	t_boolean	on;
	int			key;
}	t_ctrl_ind;

typedef struct s_ctrl_game
{
	t_ctrl_ind	w;
	t_ctrl_ind	a;
	t_ctrl_ind	s;
	t_ctrl_ind	d;
	t_ctrl_ind	l;
	t_ctrl_ind	r;
	t_ctrl_ind	oskour;
	t_ctrl_ind	pause;
	t_ctrl_ind	menu;
	t_ctrl_ind	escape;
}	t_ctrl_game;

typedef struct s_ctrl_sett
{
	t_ctrl_ind	l;
	t_ctrl_ind	r;
	t_ctrl_ind	u;
	t_ctrl_ind	d;
	t_ctrl_ind	select;
	t_ctrl_ind	ret;
}	t_ctrl_sett;

typedef struct s_ctrl
{
	t_ctrl_game	game;
	t_ctrl_sett	sett;
}	t_ctrl;

void
key_hooks_dwn(int key, void *param);

void
key_hooks_up(int key, void *param);

void
win_hooks(int event, void *param);

void
rotate(t_game *game);

void
cross_pad(t_game *game, float *move_x, float *move_y);

void
move(t_game *game);

void
border_check(t_game *game, float new_x, float new_y);

void
init_keys(t_game *game);

#endif
