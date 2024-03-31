/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trgaspar <trgaspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 18:45:07 by trgaspar          #+#    #+#             */
/*   Updated: 2024/03/31 20:34:17 by trgaspar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLONG_H
# define SOLONG_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include "get_next_line.h"
# include "MLX42/MLX42.h"
# include "MLX42/MLX42_Int.h"

typedef struct s_texture
{
	mlx_texture_t	*wall;
	mlx_texture_t	*item;
	mlx_texture_t	*spawn;
	mlx_texture_t	*floor;
	mlx_texture_t	*exit;
	mlx_texture_t	*player;
}			t_texture;

typedef struct s_image
{
	mlx_image_t	*wall;
	mlx_image_t	*spawn;
	mlx_image_t	*floor;
	mlx_image_t	*exit;
	mlx_image_t	*player;
}			t_image;

typedef struct s_coin
{
	int				x;
	int				y;
	mlx_image_t		*item;
	struct s_coin	*next;
}			t_coin;

typedef struct s_map
{
	char	**grid;
	char	**grid_copy;
	int		line_size;
	int		count_line;
	int		exit;
	int		start;
	int		item;
	int		pos_start_x;
	int		pos_start_y;
	int		pos_start_x_2;
	int		pos_start_y_2;
	int		pos_exit_x;
	int		pos_exit_y;
	int		px;
	int		py;
	int		nb_coin;
}	t_map;

typedef struct s_game
{
	int			count_move;
	t_map		*map;
	t_texture	*texture;
	t_image		*image;
	t_coin		**coin;
	mlx_t		*mlx;
}			t_game;

// File : check.c
int		ft_check_map_format_ber(char *str);
int		ft_check_map_is_rectangle(t_game *game);
int		ft_check_wall(t_game *game);
int		ft_check_map(t_game *game);
int		ft_check_exit_item_start(t_game *game, int i);

// File : check2.c
void	ft_check_exit_item_start2(int i, t_game *game);

// File : init.c
int		ft_open_map(t_game *game, char *str);
int		ft_init_check(t_game *game);
int		ft_init_window(t_game *game);
int		init_value(t_game *game);
int		init_game(t_game *game, char *str);

// File : map.c
void	ft_count_line(t_game *game, int fd);
void	*ft_stock_map(t_game *game, int fd);
void	*ft_free_all_and_exit(char **tab, int i);
void	*ft_copy_stock_map(t_game *game);
void	ft_free_all(char **tab, int i);

// File : move.c
void	ft_move_perso(t_game *game);
int		ft_check_collision_top(t_game *game);
int		ft_check_collision_bot(t_game *game);
int		ft_check_collision_left(t_game *game);
int		ft_check_collision_right(t_game *game);

// File : path_finding.c
int		ft_path_finding(int x, int y, char **cells);

// File : pick_up.c
void	ft_check_coin(t_game *game);
void	ft_lst_parse(t_game *game, int i, int j);

// File : printf.c

int		ft_putstr_fd(char *s, int fd);
int		ft_putnbr_fd(int n, int fd);
int		ft_putnbr_unsigned(unsigned int u);
int		ft_putchar_fd(char c, int fd);
int		ft_hexadecimal(unsigned long n, char *base, int ptr);

// File : printf2.c

int		ft_parse_percent(char *str, va_list params);
int		ft_format(char format, va_list params);
int		ft_printf(const char *format, ...);

// File : t_coin.c
t_coin	*ft_lstnew(int y, int x);
int		ft_lstsize(t_coin *coin);
t_coin	*ft_lstlast(t_coin *coin);
void	ft_lstadd_back(t_coin **coin, t_coin *new);
void	ft_print_all_lst(t_coin *coin);

// File : t_coin2.c
void	ft_lstclear(t_coin **coin);

// File : utils.c
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strdup(const char *s);
void	ft_close_window(t_game *game);
void	ft_delete_texture(t_game *game);

// File : utils2.c
void	ft_free_all2(t_game *game);
void	ft_count_move(t_game *game);
void	ft_win_condition(t_game *game);

// File : window.c
void	ft_setup_texture(t_game *game);
void	ft_setup_image(t_game *game);
void	ft_setup_img_to_window(t_game *game, int i);
void	ft_while_for_img_to_window(int i, t_game *game);
void	ft_hook(void *gamed);

#endif