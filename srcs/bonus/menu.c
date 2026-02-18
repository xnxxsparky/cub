/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcausseq <bcausseq@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 20:08:06 by bcausseq          #+#    #+#             */
/*   Updated: 2026/02/17 17:59:24 by bcausseq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "cub3d_bonus.h"
#include "bonus.h"

void	quit(t_game *game)
{
	mlx_loop_end(game->mlx_ctx.mlx_ctx);
}

void	resume_game(t_game *game)
{
	game->curr_state = NORMAL_STATE;
	mlx_mouse_hide(game->mlx_ctx.mlx_ctx);
}

void	init_but(t_game *game)
{
	const t_buttons	buttons[] = {
	{"CONTINUE", HEIGHT / 4, WIDTH / 2, (mlx_color){.rgba = 0x333333FF},
		(mlx_color){.rgba = 0x666666FF}, resume_game},
	{"CUSTOM KEY", HEIGHT / 2, WIDTH / 2, (mlx_color){.rgba = 0x333333FF},
		(mlx_color){.rgba = 0x666666FF}, key_bind},
	{"QUIT", 3 * HEIGHT / 4, WIDTH / 2, (mlx_color){.rgba = 0x333333FF},
		(mlx_color){.rgba = 0x666666FF}, quit}
	};

	game->menu.nb_buttons = 3;
	game->menu.buttons = ft_calloc(3, sizeof(t_buttons));
	if (!game->menu.buttons)
		return ;
	ft_memcpy(game->menu.buttons, buttons, sizeof(t_buttons) * 3);
	game->menu.index_select = 0;
}

void	draw_but(t_buttons button, mlx_color *buf, t_boolean selected)
{
	int	x;
	int	y;

	y = button.y - BUTT_Y - 1;
	while (++y < button.y + BUTT_Y)
	{
		x = button.x - BUTT_X - 1;
		while (++x < button.x + BUTT_X)
		{
			if (selected)
				buf[y * WIDTH + x] = button.hover;
			else
				buf[y * WIDTH + x] = button.normal;
		}
	}
}

void	but_display(t_game *game, t_menu menu)
{
	int			i;
	t_boolean	selected;

	i = -1;
	if (!menu.buttons)
		return ;
	while (++i < menu.nb_buttons)
	{
		selected = menu.index_select == i;
		draw_but(menu.buttons[i], game->mlx_ctx.buf, selected);
	}
}
