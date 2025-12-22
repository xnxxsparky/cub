/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcausseq <bcausseq@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 00:09:37 by bcausseq          #+#    #+#             */
/*   Updated: 2025/12/18 22:23:17 by bcausseq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_data_text	*get_cur_text(t_game *game, t_ray *ray)
{
	if (ray->side_hit == 0)
	{
		if (ray->step_x > 0)
			return (&game->texture.ea);
		else
			return (&game->texture.we);
	}
	else
	{
		if (ray->step_y > 0)
			return (&game->texture.so);
		else
			return (&game->texture.no);
	}
}

t_boolean	check_value(t_game *game, t_ray *ray, int mod)
{
	if (mod == 0)
	{
		if (game->cur_text.draw_start < 0)
			game->cur_text.draw_start = 0;
		if (game->cur_text.draw_end >= HEIGHT)
			game->cur_text.draw_end = HEIGHT - 1;
		if (game->cur_text.draw_start >= game->cur_text.draw_end)
			return (FALSE);
	}
	else if (mod == 1)
	{
		if ((ray->side_hit == 0 && ray->dir_x > 0)
			|| (ray->side_hit == 1 && ray->dir_y < 0))
			game->cur_text.tex_x = game->cur_text.texture->width
				- game->cur_text.tex_x - 1;
		if (game->cur_text.tex_x < 0)
			game->cur_text.tex_x = 0;
		if (game->cur_text.tex_x >= game->cur_text.texture->width)
			game->cur_text.tex_x = game->cur_text.texture->width - 1;
	}
	return (TRUE);
}
