/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trgaspar <trgaspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 11:51:48 by trgaspar          #+#    #+#             */
/*   Updated: 2024/04/19 17:58:07 by trgaspar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong_bonus.h"

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

void	ft_trap(t_game *game)
{
	int		x;
	int		y;
	char	*str;

	str = "xdg-open https://www.youtube.com/watch?v=dQw4w9WgXcQ&themeRefresh=1";
	y = (game->map->py + 30) / 70;
	x = (game->map->px + 30) / 70;
	if (game->map->grid[y][x] == 'T')
	{
		mlx_close_window(game->mlx);
		system(str);
		sleep(10);
		system("pkill firefox ");
	}
}

void	ft_move_perso2(t_game *game)
{
	if (mlx_is_key_down(game->mlx, MLX_KEY_A)
		&& !ft_check_collision_left(game))
	{
		game->image->player->instances[0].enabled = 0;
		game->image->player2->instances[0].enabled = 1;
		game->image->player->instances[0].x -= 5;
		ft_count_move(game);
	}
	if (mlx_is_key_down(game->mlx, MLX_KEY_D)
		&& !ft_check_collision_right(game))
	{
		game->image->player2->instances[0].enabled = 0;
		game->image->player->instances[0].enabled = 1;
		game->image->player->instances[0].x += 5;
		ft_count_move(game);
	}
}
