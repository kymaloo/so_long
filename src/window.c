/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trgaspar <trgaspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 17:16:23 by trgaspar          #+#    #+#             */
/*   Updated: 2024/03/13 13:58:56 by trgaspar         ###   ########.fr       */
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
	game->texture->player = mlx_load_png("image/Player/p3_stand.png");
	ft_setup_image(game);
}

void	ft_setup_image(t_game *game)
{
	game->image->floor = mlx_texture_to_image(game->mlx, game->texture->floor);
	game->image->wall = mlx_texture_to_image(game->mlx, game->texture->wall);
	(*game->coin)->item = mlx_texture_to_image(game->mlx, game->texture->item);
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
				mlx_image_to_window(game->mlx, (*game->coin)->item, j * 70, i * 70);
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
	ft_move_perso(game);
	ft_check_coin(game);
	ft_close_window(game);
}
