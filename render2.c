/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahabibi- <ahabibi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 18:34:46 by ahabibi-          #+#    #+#             */
/*   Updated: 2025/02/28 02:41:24 by ahabibi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put2_to_screen(t_game *game, int a, int b)
{
	if (game->map[a][b] == '0')
	{
		mlx_put_image_to_window(game->mlx, game->wind, game->empty_img, b * 64,
			a * 64);
	}
	else if (game->map[a][b] == '1')
	{
		mlx_put_image_to_window(game->mlx, game->wind, game->wall_img, b * 64, a
			* 64);
	}
	else if (game->map[a][b] == 'P')
	{
		mlx_put_image_to_window(game->mlx, game->wind, game->player_img, b * 64,
			a * 64);
		game->player_x = b;
		game->player_y = a;
	}
	else if (game->map[a][b] == 'C')
	{
		mlx_put_image_to_window(game->mlx, game->wind, game->coin_img, b * 64, a
			* 64);
	}
}

void	put3_to_screen(t_game *game, int a, int b)
{
	if (game->map[a][b] == 'E')
	{
		mlx_put_image_to_window(game->mlx, game->wind, game->exit_img, b * 64, a
			* 64);
	}
}

void	while_put_to_screen(t_game *game, int a, int b)
{
	while (game->map[a][b])
	{
		if (game->map[a][b] == '0')
			put2_to_screen(game, a, b);
		else if (game->map[a][b] == '1')
			put2_to_screen(game, a, b);
		else if (game->map[a][b] == 'P')
			put2_to_screen(game, a, b);
		else if (game->map[a][b] == 'C')
			put2_to_screen(game, a, b);
		else if (game->map[a][b] == 'U')
			put3_to_screen(game, a, b);
		else if (game->map[a][b] == 'E')
			put3_to_screen(game, a, b);
		b++;
	}
}

void	*put_to_screen(t_game *game)
{
	int	a;
	int	b;

	a = 0;
	game->wind = mlx_new_window(game->mlx, game->map_len * 64, game->map_wid
			* 64, "so_long");
	if (!game->wind)
	{
		ft_printf("Failed to create window\n");
		exit(1);
	}
	while (game->map[a])
	{
		b = 0;
		while_put_to_screen(game, a, b);
		a++;
	}
	mlx_key_hook(game->wind, handle_key, game);
	mlx_hook(game->wind, 17, 0, close_bsh, game);
	mlx_loop(game->mlx);
	return (NULL);
}

void	move_left(int keycode, t_game *game)
{
	if (keycode == 65361 || keycode == 97)
	{
		if (game->map[game->player_y][game->player_x - 1] != '1')
		{
			coin_collect(game, game->player_y, game->player_x - 1);
			check_exit(game, game->player_x - 1, game->player_y);
			if (game->map[game->player_y][game->player_x - 1] != 'E')
			{
				game->map[game->player_y][game->player_x - 1] = 'P';
				game->map[game->player_y][game->player_x] = '0';
				game->player_x--;
				ft_printf("move number: %d\n", game->i);
				game->i++;
			}
		}
	}
}
