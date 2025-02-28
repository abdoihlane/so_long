/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handling.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahabibi- <ahabibi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 19:20:57 by ahabibi-          #+#    #+#             */
/*   Updated: 2025/02/28 02:34:59 by ahabibi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	coin_collect(t_game *game, int i, int j)
{
	if (game->map[i][j] == 'C')
	{
		game->coins++;
		game->map[i][j] = '0';
	}
}

void	tfi_zmer(t_game *game)
{
	free_all(game);
	exit(0);
}

int	handle_key(int keycode, t_game *game)
{
	if (keycode == 65307)
	{
		tfi_zmer(game);
	}
	else if (keycode == 65364 || keycode == 115)
		move_up_down(65364, game);
	else if (keycode == 65362 || keycode == 119)
		move_up_down(65362, game);
	else if (keycode == 65361 || keycode == 97)
		move_left_right(65361, game);
	else if (keycode == 65363 || keycode == 100)
		move_left_right(65363, game);
	draw_map(game);
	return (0);
}

void	move_up_down(int keycode, t_game *game)
{
	if (keycode == 65364)
	{
		move_down(65364, game);
	}
	else if (keycode == 65362)
	{
		if (game->map[game->player_y - 1][game->player_x] != '1')
		{
			coin_collect(game, game->player_y - 1, game->player_x);
			check_exit(game, game->player_x, game->player_y - 1);
			if (game->map[game->player_y - 1][game->player_x] != 'E')
			{
				game->map[game->player_y - 1][game->player_x] = 'P';
				game->map[game->player_y][game->player_x] = '0';
				game->player_y--;
				ft_printf("move number: %d\n", game->i);
				game->i++;
			}
		}
	}
}

void	move_left_right(int keycode, t_game *game)
{
	if (keycode == 65361 || keycode == 97)
	{
		move_left(65361, game);
	}
	else if (keycode == 65363 || keycode == 100)
	{
		if (game->map[game->player_y][game->player_x + 1] != '1')
		{
			coin_collect(game, game->player_y, game->player_x + 1);
			check_exit(game, game->player_x + 1, game->player_y);
			if (game->map[game->player_y][game->player_x + 1] != 'E')
			{
				game->map[game->player_y][game->player_x + 1] = 'P';
				game->map[game->player_y][game->player_x] = '0';
				game->player_x++;
				ft_printf("move number: %d\n", game->i);
				game->i++;
			}
		}
	}
}
