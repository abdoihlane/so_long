/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahabibi- <ahabibi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 18:37:24 by ahabibi-          #+#    #+#             */
/*   Updated: 2025/02/27 23:41:28 by ahabibi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_game(t_game *game)
{
	game->mlx = NULL;
	game->player_img = NULL;
	game->coin_img = NULL;
	game->exit_img = NULL;
	game->empty_img = NULL;
	game->map = NULL;
	game->map_copy = NULL;
	game->img = NULL;
	game->wind = NULL;
	game->wall_img = NULL;
	game->player_x = 0;
	game->player_y = 0;
	game->map_len = 0;
	game->map_wid = 0;
	game->img_width = 0;
	game->img_height = 0;
	game->coins = 0;
	game->coin_count = 0;
	game->exit = 0;
	game->player = 0;
	game->collected_coins_f = 0;
	game->exit_found = 0;
	game->i = 0;
}

void	kmala_free(t_game *game, int i)
{
	if (game->map && game->map[i])
	{
		while (game->map[i])
		{
			free(game->map[i]);
			i++;
		}
		if (game->map)
		{
			free(game->map);
			game->map = NULL;
		}
	}
}

void	free_map(t_game *game)
{
	int	i;

	i = 0;
	if (game->map_copy && game->map_copy[i])
	{
		while (game->map_copy[i])
		{
			free(game->map_copy[i]);
			i++;
		}
		if (game->map_copy)
		{
			free(game->map_copy);
			game->map_copy = NULL;
		}
	}
	i = 0;
	kmala_free(game, i);
}

void	free_all(t_game *game)
{
	free_map(game);
	if (game->mlx)
	{
		if (game->player_img)
			mlx_destroy_image(game->mlx, game->player_img);
		if (game->coin_img)
			mlx_destroy_image(game->mlx, game->coin_img);
		if (game->exit_img)
			mlx_destroy_image(game->mlx, game->exit_img);
		if (game->empty_img)
			mlx_destroy_image(game->mlx, game->empty_img);
		if (game->wall_img)
			mlx_destroy_image(game->mlx, game->wall_img);
		if (game->wind)
		{
			mlx_destroy_window(game->mlx, game->wind);
			game->wind = NULL;
		}
		mlx_destroy_display(game->mlx);
		free(game->mlx);
		game->mlx = NULL;
	}
}

int	main(int ac, char **av)
{
	t_game	game;

	init_game(&game);
	if (ac != 2)
	{
		ft_printf("Usage: %s <map_file.ber>\n", av[0]);
		exit(1);
	}
	check_name(av[1]);
	read_map(av[1], &game);
	load_allshit(&game);
	return (0);
}
