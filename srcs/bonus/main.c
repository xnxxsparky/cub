/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcausseq <bcausseq@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 21:05:44 by salabbe           #+#    #+#             */
/*   Updated: 2026/02/17 19:33:26 by bcausseq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "cub3d_bonus.h"

#include "bonus.h"

static int	init_all(t_game *game)
{
	init_colors(game);
	init_textures(game);
	if (init_data(game) == 1)
		return (1);
	return (0);
}

static int	check_args(int ac, char **av, t_game *game)
{
	if (ac != 2)
		error(ARGS, NULL, game);
	else if (check_name_file(av[1]) == 1)
		error(EXTENSION, av[1], game);
	else
		return (0);
	return (1);
}

int	main(int ac, char **av)
{
	t_game	game;

	ft_bzero(&game, sizeof(t_game));
	if (check_args(ac, av, &game) == 1)
		return (1);
	game.fd = get_fd(av[1], &game);
	if (game.fd == -1)
		return (1);
	if (init_all(&game) == 1)
		return (1);
	if (!init_mlx(&game))
		return (free_game(&game));
	init_texture(&game);
	mlx_on_event(game.mlx_ctx.mlx_ctx, game.mlx_ctx.win,
		MLX_WINDOW_EVENT, win_hooks, &game);
	mlx_on_event(game.mlx_ctx.mlx_ctx, game.mlx_ctx.win,
		MLX_KEYDOWN, state_key_hooks_dwn, &game);
	mlx_on_event(game.mlx_ctx.mlx_ctx, game.mlx_ctx.win,
		MLX_KEYUP, state_key_hooks_up, &game);
	mlx_on_event(game.mlx_ctx.mlx_ctx, game.mlx_ctx.win, MLX_MOUSEDOWN,
		mouse_click_handle, &game);
	mlx_add_loop_hook(game.mlx_ctx.mlx_ctx, update_state, &game);
	mlx_loop(game.mlx_ctx.mlx_ctx);
	free_game(&game);
	return (0);
}
