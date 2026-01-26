/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcausseq <bcausseq@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 00:14:20 by bcausseq          #+#    #+#             */
/*   Updated: 2026/01/22 20:59:46 by bcausseq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"
#include "mlx.h"

void	clear_buffers(t_texture *text)
{
	if (text->no.text_color)
		free(text->no.text_color);
	if (text->so.text_color)
		free(text->so.text_color);
	if (text->ea.text_color)
		free(text->ea.text_color);
	if (text->we.text_color)
		free(text->we.text_color);
	if (text->door.text_color)
		free(text->door.text_color);
}

t_boolean	get_text_buff(mlx_context mlx, t_texture *text)
{
	text->no.text_color = ft_calloc(text->no.height * text->no.width,
			sizeof(mlx_color));
	text->so.text_color = ft_calloc(text->so.height * text->so.width,
			sizeof(mlx_color));
	text->ea.text_color = ft_calloc(text->ea.height * text->ea.width,
			sizeof(mlx_color));
	text->we.text_color = ft_calloc(text->we.height * text->we.width,
			sizeof(mlx_color));
	text->door.text_color = ft_calloc(text->door.height * text->door.width,
			sizeof(mlx_color));
	if (!text->no.text_color || !text->so.text_color || !text->ea.text_color
		|| !text->we.text_color || !text->door.text_color)
	{
		clear_buffers(text);
		return (FALSE);
	}
	mlx_get_image_region(mlx, text->no.text, 0, 0, text->no.width,
		text->no.height, text->no.text_color);
	mlx_get_image_region(mlx, text->door.text, 0, 0, text->door.width,
		text->door.height, text->door.text_color);
	return (TRUE);
}

void	image_load(mlx_context mlx, t_texture *text)
{
	text->no.text = mlx_new_image_from_file(mlx, text->no.path,
			&(text->no.width), &(text->no.height));
	text->so.text = mlx_new_image_from_file(mlx, text->so.path,
			&(text->so.width), &(text->so.height));
	text->ea.text = mlx_new_image_from_file(mlx, text->ea.path,
			&(text->ea.width), &(text->ea.height));
	text->we.text = mlx_new_image_from_file(mlx, text->we.path,
			&(text->we.width), &(text->we.height));
	text->door.text = mlx_new_image_from_file(mlx, text->door.path,
			&(text->door.width), &(text->door.height));
}

void	init_texture(t_game *game)
{
	image_load(game->mlx_ctx.mlx_ctx, &(game->texture));
	if (!get_text_buff(game->mlx_ctx.mlx_ctx, &(game->texture)))
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
