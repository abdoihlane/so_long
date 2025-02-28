/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahabibi- <ahabibi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 14:33:06 by ahabibi-          #+#    #+#             */
/*   Updated: 2025/02/28 02:40:44 by ahabibi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	close_bsh(t_game *game)
{
	tfi_zmer(game);
	return (0);
}

void	check_exit(t_game *game, int new_x, int new_y)
{
	if (game->map[new_y][new_x] == 'E' && game->coin_count == game->coins)
	{
		ft_printf("last move is : %d\n cuz :  ", game->i);
		ft_printf("You reached the exit! 🎉\n");
		tfi_zmer(game);
	}
}
