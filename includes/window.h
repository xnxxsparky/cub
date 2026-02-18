/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcausseq <bcausseq@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 15:49:15 by bcausseq          #+#    #+#             */
/*   Updated: 2026/02/18 00:31:08 by bcausseq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
 
#ifndef WINDOW_H
# define WINDOW_H

# define WIDTH 1280
# define HEIGHT 720

# include "../third_parties/MLX/includes/mlx.h"
# include "utils.h"

typedef struct s_game t_game;

typedef struct s_mlx
{
	mlx_context				mlx_ctx;
	mlx_window				win;
	mlx_window_create_info	win_infos;
	mlx_image				img;
	mlx_color				*buf;
	mlx_color				*old_buf;
}	t_mlx;

t_boolean
init_mlx(t_game *game);

#endif
