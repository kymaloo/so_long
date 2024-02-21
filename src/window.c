/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trgaspar <trgaspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 17:16:23 by trgaspar          #+#    #+#             */
/*   Updated: 2024/02/21 17:49:21 by trgaspar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	ft_setup_texture(t_game *game)
{
	game->texture->floor = mlx_load_png("image/Tiles/grassCenter.png");
	game->texture->wall = mlx_load_png("image/Tiles/castleCenter.png");
	game->texture->item = mlx_load_png("image/Items/coinGold.png");
	game->texture->spawn = mlx_load_png("image/Items/star.png");
	game->texture->exit = mlx_load_png("image/Tiles/lock_blue.png");
	game->texture->player = mlx_load_png("image/Player/p3_stand1.png");
	ft_setup_image(game);
}

void	ft_setup_image(t_game *game)
{
	game->image->floor = mlx_texture_to_image(game->mlx, game->texture->floor);
	game->image->wall = mlx_texture_to_image(game->mlx, game->texture->wall);
	game->image->item = mlx_texture_to_image(game->mlx, game->texture->item);
	game->image->spawn = mlx_texture_to_image(game->mlx, game->texture->spawn);
	game->image->exit = mlx_texture_to_image(game->mlx, game->texture->exit);
	game->image->player = mlx_texture_to_image(game->mlx, game->texture->player);
	ft_setup_img_to_window(game, 0);
}

void	ft_setup_img_to_window(t_game *game, int i)
{
	int	j;

	while (game->map->grid[i])
	{
		j = 0;
		while (game->map->grid[i][j])
		{
			mlx_image_to_window(game->mlx, game->image->floor, j * 70, i * 70);
			if (game->map->grid[i][j] == '1')
				mlx_image_to_window(game->mlx, game->image->wall, j * 70, i * 70);
			if (game->map->grid[i][j] == 'C')
				mlx_image_to_window(game->mlx, game->image->item, j * 70, i * 70);
			if (game->map->grid[i][j] == 'E')
				mlx_image_to_window(game->mlx, game->image->exit, j * 70, i * 70);
			if (game->map->grid[i][j] == 'P')
			{
				game->map->pos_start_x_2 = i;
				game->map->pos_start_y_2 = j;
			}
			j++;
		}
		i++;
	}
	mlx_image_to_window(game->mlx, game->image->spawn, game->map->pos_start_y_2 * 70, game->map->pos_start_x_2 * 70);
	mlx_image_to_window(game->mlx, game->image->player, game->map->pos_start_y_2 * 70, game->map->pos_start_x_2 * 70);
}


void ft_hook(void *gamed)
{
	t_game *game;

	game = gamed;
	// if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
	// 	mlx_close_window(game->mlx);
	ft_move_perso(game);
}

void	ft_move_perso(t_game *game)
{
	
	game->map->px = game->image->player->instances[0].x;
	game->map->py = game->image->player->instances[0].y;
	if (mlx_is_key_down(game->mlx, MLX_KEY_W) && check_collision_top(game) != '0')
		game->image->player->instances[0].y -= 5;
	if (mlx_is_key_down(game->mlx, MLX_KEY_S))
		game->image->player->instances[0].y += 5;
	if (mlx_is_key_down(game->mlx, MLX_KEY_A))
		game->image->player->instances[0].x -= 5;
	if (mlx_is_key_down(game->mlx, MLX_KEY_D))
		game->image->player->instances[0].x += 5;
}

int	check_collision_top(t_game *game)
{
	if (game->map->grid[(game->map->py - 8) / 70][game->map->px / 70] && game->map->grid[(game->map->py - 8) / 70][(game->map->px + 60) / 70])
		return (-1);
	return (0);
}