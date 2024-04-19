/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tp.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trgaspar <trgaspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 19:09:31 by trgaspar          #+#    #+#             */
/*   Updated: 2024/04/15 21:27:23 by trgaspar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong_bonus.h"

int	ft_tp1(t_game *game)
{
	int	x;
	int	y;

	x = (game->map->px + 30) / 70;
	y = (game->map->py + 30) / 70;
	if (game->map->grid[y][x] == 'D' && !game->tp1_used)
	{
		game->tp2_used = true;
		return (1);
	}
	if (game->map->grid[y][x] == '0' || game->map->grid[y][x] == 'E'
	|| game->map->grid[y][x] == 'C' || game->map->grid[y][x] == 'P')
	{
		game->tp1_used = false;
		game->tp2_used = false;
	}
	return (0);
}

int	ft_tp2(t_game *game)
{
	int	x;
	int	y;

	x = (game->map->px + 30) / 70;
	y = (game->map->py + 30) / 70;
	if (game->map->grid[y][x] == 'A' && !game->tp2_used)
	{
		game->tp1_used = true;
		return (2);
	}
	if (game->map->grid[y][x] == '0' || game->map->grid[y][x] == 'E'
	|| game->map->grid[y][x] == 'C' || game->map->grid[y][x] == 'P')
	{
		game->tp1_used = false;
		game->tp2_used = false;
	}
	return (0);
}

void	ft_all_tp(t_game *game)
{
	int	tp_result;

	tp_result = ft_tp1(game);
	if (tp_result == 1)
	{
		game->image->player->instances[0].x = game->map->pos_tp2_x * 70;
		game->image->player->instances[0].y = game->map->pos_tp2_y * 70;
	}
	else if (tp_result == 0)
	{
		tp_result = ft_tp2(game);
		if (tp_result == 2)
		{
			game->image->player->instances[0].x = game->map->pos_tp1_x * 70;
			game->image->player->instances[0].y = game->map->pos_tp1_y * 70;
		}
	}
}
