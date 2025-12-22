/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_to_throw.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcausseq <bcausseq@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 00:14:20 by bcausseq          #+#    #+#             */
/*   Updated: 2025/12/22 22:10:53 by bcausseq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	clear_buffers(t_texture texture)
{
	if (texture.no.text_color)
		free(texture.no.text_color);
	if (texture.so.text_color)
		free(texture.so.text_color);
	if (texture.ea.text_color)
		free(texture.ea.text_color);
	if (texture.we.text_color)
		free(texture.we.text_color);
}

t_boolean	get_text_buff(t_game *game)
{
	game->texture.no.text_color = ft_calloc(game->texture.no.height
			* game->texture.no.width, sizeof(mlx_color));
	game->texture.so.text_color = ft_calloc(game->texture.so.height
			* game->texture.so.width, sizeof(mlx_color));
	game->texture.ea.text_color = ft_calloc(game->texture.ea.height
			* game->texture.ea.width, sizeof(mlx_color));
	game->texture.we.text_color = ft_calloc(game->texture.we.height
			* game->texture.we.width, sizeof(mlx_color));
	if (!game->texture.no.text_color || !game->texture.so.text_color
		|| !game->texture.ea.text_color || !game->texture.we.text_color)
	{
		clear_buffers(game->texture);
		return (FALSE);
	}
	mlx_get_image_region(game->mlx_ctx.mlx_ctx, game->texture.no.text,
		0, 0, game->texture.no.width, game->texture.no.height,
		game->texture.no.text_color);
	return (TRUE);
}

void	init_texture(t_game *game)
{
	game->texture.no.text = mlx_new_image_from_file(game->mlx_ctx.mlx_ctx,
			game->texture.no.path, &(game->texture.no.width),
			&(game->texture.no.height));
	game->texture.so.text = mlx_new_image_from_file(game->mlx_ctx.mlx_ctx,
			game->texture.so.path, &(game->texture.so.width),
			&(game->texture.so.height));
	game->texture.ea.text = mlx_new_image_from_file(game->mlx_ctx.mlx_ctx,
			game->texture.ea.path, &(game->texture.ea.width),
			&(game->texture.ea.height));
	game->texture.we.text = mlx_new_image_from_file(game->mlx_ctx.mlx_ctx,
			game->texture.we.path, &(game->texture.we.width),
			&(game->texture.we.height));
	if (!get_text_buff(game))
		return ;
	mlx_get_image_region(game->mlx_ctx.mlx_ctx, game->texture.so.text,
		0, 0, game->texture.so.width, game->texture.so.height,
		game->texture.so.text_color);
	mlx_get_image_region(game->mlx_ctx.mlx_ctx, game->texture.ea.text,
		0, 0, game->texture.ea.width, game->texture.ea.height,
		game->texture.ea.text_color);
	mlx_get_image_region(game->mlx_ctx.mlx_ctx, game->texture.we.text,
		0, 0, game->texture.we.width, game->texture.we.height,
		game->texture.we.text_color);
}
