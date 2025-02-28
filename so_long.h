/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahabibi- <ahabibi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 18:35:30 by ahabibi-          #+#    #+#             */
/*   Updated: 2025/02/28 02:38:47 by ahabibi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "get_next_line.h"
# include "mlx.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
// # include <string.h>
# include <unistd.h>

typedef struct s_game
{
	void	*mlx;
	void	*wind;
	void	*player_img;
	void	*coin_img;
	void	*exit_img;
	void	*wall_img;
	void	*empty_img;
	void	*img;
	char	**map;
	char	**map_copy;
	int		player_x;
	int		player_y;
	int		map_len;
	int		map_wid;
	int		img_width;
	int		img_height;
	int		coins;
	int		coin_count;
	int		exit;
	int		exit_found;
	int		player;
	int		collected_coins_f;
	int		i;
}			t_game;

void		init_game(t_game *game);
void		free_all(t_game *game);
void		free_map(t_game *game);
void		not_valid(t_game *game, char *message);
void		check_name(char *name);
int			check_map_bounds(char **map, int j, int z);
void		check2(t_game *game, char **map);
void		check3(t_game *game, char **map, int j, int z);
void		read_map(char *map_path, t_game *game);
void		*load_allshit(t_game *game);
void		draw_map(t_game *game);
void		*put_to_screen(t_game *game);
void		put2_to_screen(t_game *game, int a, int b);
void		put3_to_screen(t_game *game, int a, int b);
void		while_put_to_screen(t_game *game, int a, int b);
int			handle_key(int keycode, t_game *game);
void		move_up_down(int keycode, t_game *game);
void		move_left_right(int keycode, t_game *game);
void		coin_collect(t_game *game, int i, int j);
void		tfi_zmer(t_game *game);
int			map_check(char **map, t_game *game);
void		ft_map_copy(t_game *game, int y);
void		check_exit(t_game *game, int new_x, int new_y);
void		flood_fill(t_game *game, int y, int x);
void		map_copy_check(t_game *game);
void		move_down(int keycode, t_game *game);
void		move_left(int keycode, t_game *game);
void		to_wind(t_game *game, int i, int j);
void		check_add(t_game *game, char **map);
void		validimagesornot(t_game *game);
int			ft_atoi(const char *str);
int			ft_putchar(char c);
int			ft_printf(const char *sa, ...);
int			ft_putstr(char *s);
int			ft_putnbr(int n);
int			ft_strcmp(char *s1, char *s2);
char		*get_next_line(int fd);
char		*ft_substr(const char *s, unsigned int start, size_t len);
size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize);
char		*ft_strchr(const char *s, int c);
char		*ft_strjoin(char *s1, const char *s2);
char		*ft_strdup(const char *s1);
size_t		ft_strlen(const char *s);
int			close_bsh(t_game *game);

#endif
