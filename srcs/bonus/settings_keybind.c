/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings_keybind.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcausseq <bcausseq@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 22:09:57 by bcausseq          #+#    #+#             */
/*   Updated: 2026/02/17 18:11:39 by bcausseq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "cub3d_bonus.h"

#include "bonus.h"

void	pipi(t_game *game)
{
	game->curr_state = WAITING_SETT_STATE;
}

void	sett_init_keybinds(t_game *game)
{
	const mlx_color	shade[2] = {(mlx_color){.rgba = 0x333333FF},
		(mlx_color){.rgba = 0x666666FF}};
	const char		*name[7] = {"LEFT", "RIGHT", "UP", "DOWN", "OK", "BACK",
		NULL};
	const int		yx[2] = {HEIGHT / 4, WIDTH / 3};
	int				i;
	int				j;

	i = 0;
	j = 0;
	game->set_bind.nb_buttons = 6;
	game->set_bind.buttons = ft_calloc(6, sizeof(t_buttons));
	if (!game->set_bind.buttons)
		return ;
	while (j < 3)
	{
		game->set_bind.buttons[2 * j + i] = (t_buttons){(char *)name[2 * j + i],
			yx[0] * (j + 1), yx[1] * (i + 1), shade[0], shade[1], pipi};
		i++;
		if (i == 2)
			j++;
		if (i == 2)
			i = 0;
	}
	game->set_bind.index_select = 0;
}

void	sett_waiting(int key, t_game *game)
{
	if (check_key_free(key, game) == FALSE)
		return ;
	if (game->set_bind.index_select == 0)
		game->ctrl.sett.l.key = key;
	else if (game->set_bind.index_select == 1)
		game->ctrl.sett.r.key = key;
	else if (game->set_bind.index_select == 2)
		game->ctrl.sett.u.key = key;
	else if (game->set_bind.index_select == 3)
		game->ctrl.sett.d.key = key;
	else if (game->set_bind.index_select == 4)
		game->ctrl.sett.select.key = key;
	else if (game->set_bind.index_select == 5)
		game->ctrl.sett.ret.key = key;
	game->curr_state = KEYBNG_SETT_STATE;
}

void	sett_keybind_draw(t_game *game)
{
	ft_bufcpy(game->mlx_ctx.old_buf, game->mlx_ctx.buf);
	fifty_shade_of_grey(game->mlx_ctx.buf);
	mlx_clear_window(game->mlx_ctx.mlx_ctx, game->mlx_ctx.win,
		(mlx_color){.rgba = 0x000000FF});
	but_display(game, game->set_bind);
	mouse_menu(game, &(game->set_bind));
	mlx_set_image_region(game->mlx_ctx.mlx_ctx, game->mlx_ctx.img,
		0, 0, WIDTH, HEIGHT, game->mlx_ctx.buf);
	mlx_put_image_to_window(game->mlx_ctx.mlx_ctx, game->mlx_ctx.win,
		game->mlx_ctx.img, 0, 0);
	draw_text(game->set_bind.buttons, game->set_bind, game->mlx_ctx);
}
