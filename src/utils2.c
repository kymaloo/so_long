/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trgaspar <trgaspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 11:51:48 by trgaspar          #+#    #+#             */
/*   Updated: 2024/04/19 17:56:48 by trgaspar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	ft_free_all2(t_game *game)
{
	if (game->image)
		free(game->image);
	if (game->texture)
		free(game->texture);
	if (game->map->grid_copy)
		ft_free_all(game->map->grid_copy, game->map->count_line);
	if (game->map->grid)
		ft_free_all(game->map->grid, game->map->count_line);
	if (game->map)
		free(game->map);
}

void	ft_count_move(t_game *game)
{
	game->count_move++;
	ft_printf("The number of steps is %d\n", game->count_move);
}

void	ft_win_condition(t_game *game)
{
	int	x;
	int	y;

	y = (game->map->py + 30) / 70;
	x = (game->map->px + 30) / 70;
	if (game->map->nb_coin == game->map->item && \
	y == game->map->pos_exit_y && x == game->map->pos_exit_x)
		mlx_close_window(game->mlx);
}
