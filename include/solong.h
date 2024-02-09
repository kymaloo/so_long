/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trgaspar <trgaspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 18:45:07 by trgaspar          #+#    #+#             */
/*   Updated: 2024/02/09 20:02:12 by trgaspar         ###   ########.fr       */
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

typedef struct s_map
{
	char    **grid;
	//char    **grid_copy;
	int     line_size;
	int     count_line;
}	t_map;

typedef struct s_game
{
    t_map   *map;
    //mlx_t   *mlx;
}	t_game;

void	ft_count_line(t_game *game, int fd);
void	*ft_stock_map(t_game *game, int fd);
void	*ft_free_all_and_exit(char **tab, int i);

int	check_map_format_ber(char *str);
int	check_map_is_rectangle(t_game *game);

int	ft_strncmp(const char *s1, const char *s2, size_t n);
int	check_wall(t_game *game);
int	check_map(t_game *game);

#endif