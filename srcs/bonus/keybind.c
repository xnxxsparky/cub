/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keybind.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcausseq <bcausseq@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 22:09:57 by bcausseq          #+#    #+#             */
/*   Updated: 2026/02/17 17:52:31 by bcausseq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "cub3d_bonus.h"

#include "bonus.h"

void	key_bind(t_game *game)
{
	game->curr_state = KEYBNG_GAME_STATE;
}

void	caca(t_game *game)
{
	game->curr_state = WAITING_GAME_STATE;
}

void	init_p2(t_game *game, const char *name[11],
		const int yx[2], const mlx_color shade[2])
{
	game->key_bind.buttons[9] = (t_buttons){(char *)name[9],
		yx[0] * 4, yx[1] * 2, shade[0], shade[1], caca};
	game->key_bind.index_select = 0;
}

void	init_keybinds(t_game *game)
{
	const mlx_color	shade[2] = {(mlx_color){.rgba = 0x333333FF},
		(mlx_color){.rgba = 0x666666FF}};
	const char		*name[11] = {"UP", "LEFT", "DOWN", "RIGHT", "L", "R",
		"FREE CAM", "PAUSE", "MENU", "ESCAPE", NULL};
	const int		yx[2] = {HEIGHT / 5, WIDTH / 4};
	int				i;
	int				j;

	i = 0;
	j = 0;
	game->key_bind.nb_buttons = 10;
	game->key_bind.buttons = ft_calloc(10, sizeof(t_buttons));
	if (!game->key_bind.buttons)
		return ;
	while (j < 3)
	{
		game->key_bind.buttons[3 * j + i] = (t_buttons){(char *)name[3 * j + i],
			yx[0] * (j + 1), yx[1] * (i + 1), shade[0], shade[1], caca};
		i++;
		if (i == 3)
			j++;
		if (i == 3)
			i = 0;
	}
	init_p2(game, name, yx, shade);
}

void	keybind_draw(t_game *game)
{
	ft_bufcpy(game->mlx_ctx.old_buf, game->mlx_ctx.buf);
	fifty_shade_of_grey(game->mlx_ctx.buf);
	mlx_clear_window(game->mlx_ctx.mlx_ctx, game->mlx_ctx.win,
		(mlx_color){.rgba = 0x000000FF});
	but_display(game, game->key_bind);
	mouse_menu(game, &(game->key_bind));
	mlx_set_image_region(game->mlx_ctx.mlx_ctx, game->mlx_ctx.img,
		0, 0, WIDTH, HEIGHT, game->mlx_ctx.buf);
	mlx_put_image_to_window(game->mlx_ctx.mlx_ctx, game->mlx_ctx.win,
		game->mlx_ctx.img, 0, 0);
	draw_text(game->key_bind.buttons, game->key_bind, game->mlx_ctx);
}
