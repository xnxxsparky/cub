/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commentoncommence.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcausseq <bcausseq@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 20:48:46 by bcausseq          #+#    #+#             */
/*   Updated: 2025/12/13 21:37:17 by bcausseq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// int	main(void)
// {
// 	t_game		game;
// 
// 	ft_bzero(&game, sizeof(t_game));
// 	if (!init_mlx(&game))
// 	{
// 		free_game(&game);
// 		return (1);
// 	}
// 	game.map.map = dup_map();
// 	game.map.height = 8;
// 	game.map.weight = 8;
// 	for (int i = 0; i < 8; ++i)
// 	{
// 		for (int j = 0; j < 8; ++j)
// 		{
// 			if (game.map.map[i][j] && !(game.map.map[i][j] == '0' || game.map.map[i][j] == '1'))
// 			{
// 				game.player.pos_x = j + 0.5;
// 				game.player.pos_y = i + 0.5;
// 				game.player.dir_x = 0.0;
// 				game.player.dir_y = -1.0;
// 				game.player.cam_x = 0.66;
// 				game.player.cam_y = 0.0;
// 				game.map.map[i][j] = '0';
// 				game.colors.floor = (mlx_color){.rgba = 0x808080FF};
// 				game.colors.ceiling = (mlx_color){.rgba = 0x87CEEBFF};
// 			}
// 		}
// 	}
// 	init_texture(&game);
// 	mlx_on_event(game.mlx_ctx.mlx_ctx, game.mlx_ctx.win, MLX_WINDOW_EVENT, win_hooks, &game);
// 	mlx_on_event(game.mlx_ctx.mlx_ctx, game.mlx_ctx.win, MLX_KEYDOWN, key_hooks_dwn, &game);
// 	mlx_on_event(game.mlx_ctx.mlx_ctx, game.mlx_ctx.win, MLX_KEYUP, key_hooks_up, &game);
// 	mlx_add_loop_hook(game.mlx_ctx.mlx_ctx, cast_rays, &game);
// 	mlx_loop(game.mlx_ctx.mlx_ctx);
// 	free_game(&game);
// 	return (0);
// }
