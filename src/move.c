/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trgaspar <trgaspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 17:08:25 by trgaspar          #+#    #+#             */
/*   Updated: 2024/03/13 13:58:50 by trgaspar         ###   ########.fr       */
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
		game->count_move++;
		printf("Nombre de mouvement : %d\n", game->count_move);
	}
	if (mlx_is_key_down(game->mlx, MLX_KEY_S) && !ft_check_collision_bot(game))
	{
		game->image->player->instances[0].y += 5;
		game->count_move++;
		printf("Nombre de mouvement : %d\n", game->count_move);
	}
	if (mlx_is_key_down(game->mlx, MLX_KEY_A) && !ft_check_collision_left(game))
	{
		game->image->player->instances[0].x -= 5;
		game->count_move++;
		printf("Nombre de mouvement : %d\n", game->count_move);
	}
	if (mlx_is_key_down(game->mlx, MLX_KEY_D) && !ft_check_collision_right(game))
	{
		game->image->player->instances[0].x += 5;
		game->count_move++;
		printf("Nombre de mouvement : %d\n", game->count_move);
	}
}

int	ft_check_collision_top(t_game *game)
{
	if (game->map->grid[(game->map->py - 8) / 70][game->map->px / 70] == '1' || game->map->grid[(game->map->py - 8) / 70][(game->map->px + 60) / 70] == '1')
		return (1);
	return (0);
}

int	ft_check_collision_bot(t_game *game)
{
	if (game->map->grid[(game->map->py + 68) / 70][game->map->px / 70] == '1' || game->map->grid[(game->map->py + 68) / 70][(game->map->px + 60) / 70] == '1')
		return (-1);
	return (0);
}
int	ft_check_collision_left(t_game *game)
{
	if (game->map->grid[game->map->py / 70][(game->map->px - 8) / 70] == '1' || game->map->grid[(game->map->py + 60) / 70][(game->map->px - 8) / 70] == '1')
		return (-1);
	return (0);
}
int	ft_check_collision_right(t_game *game)
{
	if (game->map->grid[game->map->py / 70][(game->map->px + 68) / 70] == '1' || game->map->grid[(game->map->py + 60) / 70][(game->map->px + 68) / 70] == '1')
		return (-1);
	return (0);
}