/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trgaspar <trgaspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 17:16:23 by trgaspar          #+#    #+#             */
/*   Updated: 2024/02/12 23:36:01 by trgaspar         ###   ########.fr       */
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
	ft_setup_img_to_window(game);
}


void	ft_setup_img_to_window(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map->grid[i])
	{
		j = 0;
		while (game->map->grid[i][j])
		{
			mlx_image_to_window(game->mlx, game->image->floor, j * 70, i * 70);
			if (game->map->grid[i][j] == 'E')
				mlx_image_to_window(game->mlx, game->image->exit, j * 70, i * 70);
			if (game->map->grid[i][j] == 'C')
				mlx_image_to_window(game->mlx, game->image->item, j * 70, i * 70);
			if (game->map->grid[i][j] == '1')
				mlx_image_to_window(game->mlx, game->image->wall, j * 70, i * 70);
			if (game->map->grid[i][j] == 'P')
			{
				mlx_image_to_window(game->mlx, game->image->spawn, j * 70, i * 70);
				mlx_image_to_window(game->mlx, game->image->player, j * 70, i * 70);
			}
			j++;
		}
		i++;
	}
}


// void ft_hook(void* param)
// {
// 	game->mlx = param;

// 	if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
// 		mlx_close_window(game->mlx);
	
// }

// void	ft_move_perso(t_game *game)
// {
// 	if (mlx_is_key_down(game->mlx MLX_KEY_UP))
// 		game->image->instances[0].y -= 5;
// 	if (mlx_is_key_down(game->mlx MLX_KEY_DOWN))
// 		game->image->instances[0].y += 5;
// 	if (mlx_is_key_down(game->mlx MLX_KEY_LEFT))
// 		game->image->instances[0].x -= 5;
// 	if (mlx_is_key_down(game->mlx MLX_KEY_RIGHT))
// 		game->image->instances[0].x += 5;
// }