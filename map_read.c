/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahabibi- <ahabibi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 18:50:25 by ahabibi-          #+#    #+#             */
/*   Updated: 2025/02/27 23:41:37 by ahabibi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_exit(char **buff, char *message)
{
	if (buff)
	{
		free(buff);
	}
	ft_printf("%s", message);
	exit(1);
}

int	read_2(char *map_path, t_game *game)
{
	char	*line;
	int		i;
	int		fd;

	i = 0;
	fd = open(map_path, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("Cannot open map file: %s\n", map_path);
		exit(1);
	}
	line = get_next_line(fd);
	while (line != NULL)
	{
		i++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	game->map_wid = i;
	return (i);
}

void	read_3(char *map_path, t_game *game, int i)
{
	int		fd;
	int		j;
	char	**map;

	j = 0;
	map = malloc(sizeof(char *) * (i + 1));
	fd = open(map_path, O_RDONLY);
	if (fd == -1)
		free_exit(map, "Cannot open map file\n");
	map[j] = get_next_line(fd);
	while (map[j])
	{
		j++;
		map[j] = get_next_line(fd);
		if (!map[j] && j < i)
		{
			while (--j >= 0)
				free(map[j]);
			close(fd);
			free_exit(map, "Failed to read map line\n");
		}
	}
	game->map = map;
	close(fd);
}

void	read_map(char *map_path, t_game *game)
{
	int	i;

	i = 0;
	i = read_2(map_path, game);
	if (i == 0)
	{
		ft_printf("Empty file\n");
		exit(1);
	}
	read_3(map_path, game, i);
	ft_map_copy(game, game->map_wid);
	map_check(game->map, game);
}

void	check_add(t_game *game, char **map)
{
	if (game->map_wid == 0 || game->map_len == 0)
		not_valid(game, "Invalid map dimensions");
	if (game->player != 1)
		not_valid(game, "Must have exactly one player");
	if (game->coin_count == 0)
		not_valid(game, "Must have at least one collectible");
	if (game->exit != 1)
		not_valid(game, "Must have exactly one exit");
	check2(game, map);
}
