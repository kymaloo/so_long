/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trgaspar <trgaspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 18:45:07 by trgaspar          #+#    #+#             */
/*   Updated: 2024/02/08 19:47:14 by trgaspar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLONG_H
# define SOLONG_H

# include <fcntl.h>
# include <stdio.h>
# include "get_next_line.h"
# include "MLX42/MLX42.h"
# include "MLX42/MLX42_Int.h"

typedef struct s_map
{
   //char    **grid;
    //char    **grid_copy;
    //int     line_size;
    int     count_line;
}	t_map;

typedef struct s_game
{
    t_map   *map;
    //mlx_t   *mlx;
}	t_game;

void ft_count_line(int fd, t_game *game);

#endif