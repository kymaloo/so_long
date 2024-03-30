/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trgaspar <trgaspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 11:51:48 by trgaspar          #+#    #+#             */
/*   Updated: 2024/03/30 19:25:29 by trgaspar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	ft_free_all2(t_game *game)
{
	ft_free_img(game);
	ft_delete_texture(game);
	free(game->coin);
	free(game->image);
	free(game->texture);
	ft_free_all(game->map->grid_copy, game->map->count_line + 1);
	ft_free_all(game->map->grid, game->map->count_line + 1);
	free(game->map);
	mlx_close_window(game->mlx);
	free(game);
}

void	ft_count_move(t_game *game)
{
	game->count_move++;
	ft_printf("Nombre de mouvement : %d\n", game->count_move);
}

void	ft_win_condition(t_game *game)
{
	int	x;
	int	y;

	y = (game->map->py + 30) / 70;
	x = (game->map->px + 30) / 70;
	if (game->map->nb_coin == game->map->item && \
	y == game->map->pos_exit_y && x == game->map->pos_exit_x)
		ft_free_all2(game);
}
