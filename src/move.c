/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trgaspar <trgaspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 17:08:25 by trgaspar          #+#    #+#             */
/*   Updated: 2024/03/25 16:33:33 by trgaspar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	ft_move_perso(t_game *game)
{
	game->map->px = game->image->player->instances[0].x;
	game->map->py = game->image->player->instances[0].y;
	if (mlx_is_key_down(game->mlx, MLX_KEY_W) && !ft_check_collision_top(game))
	{
		game->image->player->instances[0].y -= 5;
		ft_count_move(game);
	}
	if (mlx_is_key_down(game->mlx, MLX_KEY_S) && !ft_check_collision_bot(game))
	{
		game->image->player->instances[0].y += 5;
		ft_count_move(game);
	}
	if (mlx_is_key_down(game->mlx, MLX_KEY_A) && !ft_check_collision_left(game))
	{
		game->image->player->instances[0].x -= 5;
		ft_count_move(game);
	}
	if (mlx_is_key_down(game->mlx, MLX_KEY_D) \
		&& !ft_check_collision_right(game))
	{
		game->image->player->instances[0].x += 5;
		ft_count_move(game);
	}
}

int	ft_check_collision_top(t_game *game)
{
	int	x;
	int	y;

	x = game->map->px;
	y = game->map->py;
	if (game->map->grid[(y - 8) / 70] \
		[x / 70] == '1' || game->map->grid[(y - 8) / 70] \
		[(x + 60) / 70] == '1')
		return (-1);
	return (0);
}

int	ft_check_collision_bot(t_game *game)
{
	int	x;
	int	y;

	x = game->map->px;
	y = game->map->py;
	if (game->map->grid[(y + 68) / 70] \
		[x / 70] == '1' || game->map->grid[(y + 68) / 70] \
		[(x + 60) / 70] == '1')
		return (-1);
	return (0);
}

int	ft_check_collision_left(t_game *game)
{
	int	x;
	int	y;

	x = game->map->px;
	y = game->map->py;
	if (game->map->grid[y / 70] \
		[(x - 8) / 70] == '1' || game->map->grid[(y + 60) / 70] \
		[(x - 8) / 70] == '1')
		return (-1);
	return (0);
}

int	ft_check_collision_right(t_game *game)
{
	int	x;
	int	y;

	x = game->map->px;
	y = game->map->py;
	if (game->map->grid[y / 70] \
		[(x + 68) / 70] == '1' || game->map->grid[(y + 60) / 70] \
		[(x + 68) / 70] == '1')
		return (-1);
	return (0);
}
