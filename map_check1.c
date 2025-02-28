/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahabibi- <ahabibi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 20:21:19 by ahabibi-          #+#    #+#             */
/*   Updated: 2025/02/28 02:16:16 by ahabibi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	not_valid(t_game *game, char *message)
{
	ft_printf("%s\n", message);
	free_all(game);
	exit(1);
}

void	check_name(char *name)
{
	int	i;

	i = ft_strlen(name);
	if (i <= 4)
	{
		ft_printf("Name must be like <name.ber>\n");
		exit(1);
	}
	i -= 4;
	if ((ft_strcmp(&name[i], ".ber") != 0))
	{
		ft_printf("The name of this map is invalid\n");
		exit(1);
	}
}

int	check_map_bounds(char **map, int j, int z)
{
	if (!map || !map[j] || !map[j][z])
		return (0);
	return (1);
}

void	check2(t_game *game, char **map)
{
	int	row;

	row = 0;
	while (row < game->map_wid)
	{
		if ((int)ft_strlen(map[row]) != (game->map_len))
			not_valid(game, "Map is not a rectangle");
		row++;
	}
	row = 0;
	while (row < game->map_len)
	{
		if (map[0][row] != '1' || map[game->map_wid - 1][row] != '1')
			not_valid(game, "Map not enclosed by walls (top/bottom)");
		row++;
	}
	row = 0;
	while (row < game->map_wid)
	{
		if (map[row][0] != '1' || map[row][game->map_len - 1] != '1')
			not_valid(game, "Map not enclosed by walls (left/right)");
		row++;
	}
}

void	check3(t_game *game, char **map, int j, int z)
{
	if (!check_map_bounds(map, j, z))
		not_valid(game, "Invalid map bounds");
	if (!ft_strchr("PCE01", map[j][z]))
		not_valid(game, "Invalid character in map");
	if (map[j][z] == 'P')
	{
		game->player += 1;
		game->player_x = z;
		game->player_y = j;
	}
	else if (map[j][z] == 'C')
		game->coin_count += 1;
	else if (map[j][z] == 'E')
		game->exit += 1;
}
