/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_menu.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcausseq <bcausseq@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 23:58:52 by bcausseq          #+#    #+#             */
/*   Updated: 2026/02/17 17:59:46 by bcausseq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "cub3d_bonus.h"
#include "bonus.h"

t_menu	*get_menu_addr(t_game *game)
{
	const t_state_game	state = game->curr_state;

	if (state == MENU_STATE)
		return (&(game->menu));
	else if (state == KEYBNG_GAME_STATE)
		return (&(game->key_bind));
	else if (state == KEYBNG_SETT_STATE)
		return (&(game->set_bind));
	return (NULL);
}

void	mouse_click_handle(int key, void *param)
{
	t_game	*game;
	t_menu	*men;
	int		c_x;
	int		c_y;
	int		i;

	(void)key;
	game = (t_game *)param;
	men = get_menu_addr(game);
	if (men == NULL)
		return ;
	mlx_mouse_get_pos(game->mlx_ctx.mlx_ctx, &c_x, &c_y);
	i = -1;
	while (++i < men->nb_buttons)
	{
		if (c_x < men->buttons[i].x + BUTT_X
			&& c_x > men->buttons[i].x - BUTT_X
			&& c_y < men->buttons[i].y + BUTT_Y
			&& c_y > men->buttons[i].y - BUTT_Y
			&& men->index_select == i)
			men->buttons[i].action(game);
	}
}

void	mouse_menu(t_game *game, t_menu *menu)
{
	int	c_x;
	int	c_y;
	int	i;

	mlx_mouse_get_pos(game->mlx_ctx.mlx_ctx, &c_x, &c_y);
	i = -1;
	while (++i < menu->nb_buttons)
	{
		if (c_x < menu->buttons[i].x + BUTT_X
			&& c_x > menu->buttons[i].x - BUTT_X
			&& c_y < menu->buttons[i].y + BUTT_Y
			&& c_y > menu->buttons[i].y - BUTT_Y)
			menu->index_select = i;
	}
}

void	menu_draw(t_game *game)
{
	if (game->curr_state != MENU_STATE)
		return ;
	mlx_clear_window(game->mlx_ctx.mlx_ctx, game->mlx_ctx.win,
		(mlx_color){.rgba = 0x000000FF});
	ft_bufcpy(game->mlx_ctx.old_buf, game->mlx_ctx.buf);
	fifty_shade_of_grey(game->mlx_ctx.buf);
	but_display(game, game->menu);
	mouse_menu(game, &(game->menu));
	mlx_set_image_region(game->mlx_ctx.mlx_ctx, game->mlx_ctx.img,
		0, 0, WIDTH, HEIGHT, game->mlx_ctx.buf);
	mlx_put_image_to_window(game->mlx_ctx.mlx_ctx, game->mlx_ctx.win,
		game->mlx_ctx.img, 0, 0);
	draw_text(game->menu.buttons, game->menu, game->mlx_ctx);
}
