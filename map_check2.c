/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahabibi- <ahabibi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 18:38:44 by ahabibi-          #+#    #+#             */
/*   Updated: 2025/02/28 02:10:37 by ahabibi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	idk(t_game *game, char **map)
{
	if (!map || !map[0])
	{
		not_valid(game, "Map is empty");
	}
	return (0);
}

int	map_check(char **map, t_game *game)
{
	int (j), (z);
	j = 0;
	z = 0;
	if (!map || !map[0])
		idk(game, map);
	while (map[j])
	{
		z = 0;
		while (map[j][z] && map[j][z] != '\n')
		{
			check3(game, map, j, z);
			z++;
		}
		j++;
	}
	game->map_len = z;
	game->map_wid = j;
	check_add(game, map);
	flood_fill(game, game->player_y, game->player_x);
	if (game->collected_coins_f < game->coin_count)
		not_valid(game, "Not all collectibles can be reached");
	map_copy_check(game);
	return (0);
}

void	ft_map_copy(t_game *game, int y)
{
	int	i;

	game->map_copy = malloc(sizeof(char *) * (y + 1));
	if (!game->map_copy)
		return ;
	i = 0;
	while (game->map[i])
	{
		game->map_copy[i] = ft_strdup(game->map[i]);
		if (!game->map_copy[i])
		{
			while (--i >= 0)
				free(game->map_copy[i]);
			free(game->map_copy);
			game->map_copy = NULL;
			return ;
		}
		i++;
	}
	game->map_copy[i] = NULL;
}

void	flood_fill(t_game *game, int y, int x)
{
	if (y < 0 || x < 0 || y >= game->map_wid || x >= game->map_len
		|| game->map_copy[y][x] == '1' || game->map_copy[y][x] == 'V')
		return ;
	if (game->map_copy[y][x] == 'C')
		game->collected_coins_f++;
	else if (game->map_copy[y][x] == 'E')
		game->exit_found = 1;
	game->map_copy[y][x] = 'V';
	flood_fill(game, y, x - 1);
	flood_fill(game, y + 1, x);
	flood_fill(game, y, x + 1);
	flood_fill(game, y - 1, x);
}

void	map_copy_check(t_game *game)
{
	int	i;
	int	j;
	int	exit_accessible;

	i = 0;
	exit_accessible = 0;
	while (game->map_copy[i])
	{
		j = 0;
		while (game->map_copy[i][j])
		{
			if (game->map_copy[i][j] == 'V' && ((i > 0 && game->map[i
						- 1][j] == 'E') || (i < game->map_wid - 1 && game->map[i
						+ 1][j] == 'E') || (j > 0 && game->map[i][j - 1] == 'E')
					|| (j < game->map_len - 1 && game->map[i][j + 1] == 'E')))
			{
				exit_accessible = 1;
			}
			j++;
		}
		i++;
	}
	if (!exit_accessible && !game->exit_found)
		not_valid(game, "Exit cannot be reached");
}
