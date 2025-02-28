/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahabibi- <ahabibi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 18:34:09 by ahabibi-          #+#    #+#             */
/*   Updated: 2025/02/28 02:40:30 by ahabibi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_map(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j]
			&& game->map[game->player_y][game->player_x] != 'E')
		{
			to_wind(game, i, j);
			j++;
		}
		i++;
	}
	return ;
}

void	*load_allshit(t_game *game)
{
	int (width), (height);
	game->mlx = mlx_init();
	if (!game->mlx)
	{
		ft_printf("Failed to initialize MLX\n");
		exit(1);
	}
	game->player_img = mlx_xpm_file_to_image(game->mlx, "textures/batman.xpm",
			&width, &height);
	game->coin_img = mlx_xpm_file_to_image(game->mlx, "textures/coin2.xpm",
			&width, &height);
	game->exit_img = mlx_xpm_file_to_image(game->mlx, "textures/exit.xpm",
			&width, &height);
	game->wall_img = mlx_xpm_file_to_image(game->mlx, "textures/wall.xpm",
			&width, &height);
	game->empty_img = mlx_xpm_file_to_image(game->mlx, "textures/empty.xpm",
			&width, &height);
	validimagesornot(game);
	put_to_screen(game);
	return (NULL);
}

void	validimagesornot(t_game *game)
{
	if (!game->player_img)
		tfi_zmer(game);
	if (!game->coin_img)
		tfi_zmer(game);
	if (!game->exit_img)
		tfi_zmer(game);
	if (!game->exit_img)
		tfi_zmer(game);
	if (!game->empty_img)
		tfi_zmer(game);
}

void	move_down(int keycode, t_game *game)
{
	if (keycode == 65364)
	{
		if (game->map[game->player_y + 1][game->player_x] != '1')
		{
			coin_collect(game, game->player_y + 1, game->player_x);
			check_exit(game, game->player_x, game->player_y + 1);
			if (game->map[game->player_y + 1][game->player_x] != 'E')
			{
				game->map[game->player_y + 1][game->player_x] = 'P';
				game->map[game->player_y][game->player_x] = '0';
				game->player_y++;
				ft_printf("move number: %d\n", game->i);
				game->i++;
			}
		}
	}
}

void	to_wind(t_game *game, int i, int j)
{
	if (game->map[i][j] == '1')
		mlx_put_image_to_window(game->mlx, game->wind, game->wall_img, j * 64, i
			* 64);
	else if (game->map[i][j] == 'P')
		mlx_put_image_to_window(game->mlx, game->wind, game->player_img, j * 64,
			i * 64);
	else if (game->map[i][j] == 'C')
		mlx_put_image_to_window(game->mlx, game->wind, game->coin_img, j * 64, i
			* 64);
	else if (game->map[i][j] == 'E')
		mlx_put_image_to_window(game->mlx, game->wind, game->exit_img, j * 64, i
			* 64);
	else if (game->map[i][j] == '0')
		mlx_put_image_to_window(game->mlx, game->wind, game->empty_img, j * 64,
			i * 64);
	j++;
}
