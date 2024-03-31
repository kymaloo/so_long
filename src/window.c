/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trgaspar <trgaspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 17:16:23 by trgaspar          #+#    #+#             */
/*   Updated: 2024/03/31 17:36:03 by trgaspar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	ft_setup_texture(t_game *game)
{
	game->texture->floor = mlx_load_png("image/Tiles/grassCenter.png");
	if (!game->texture->floor)
		return (ft_printf("No texture floor"), exit(0));
	game->texture->wall = mlx_load_png("image/Tiles/castleCenter.png");
	if (!game->texture->wall)
		return (ft_printf("No texture wall"), exit(0));
	game->texture->item = mlx_load_png("image/Items/coinGold.png");
	if (!game->texture->item)
		return (ft_printf("No texture coin"), exit(0));
	game->texture->spawn = mlx_load_png("image/Items/star.png");
	if (!game->texture->spawn)
		return (ft_printf("No texture spawn"), exit(0));
	game->texture->exit = mlx_load_png("image/Tiles/lock_blue.png");
	if (!game->texture->exit)
		return (ft_printf("No texture exit"), exit(0));
	game->texture->player = mlx_load_png("image/Player/p3_stand.png");
	if (!game->texture->player)
		return (ft_printf("No texture player"), exit(0));
	ft_setup_image(game);
}

void	ft_setup_image(t_game *game)
{
	game->image->floor = mlx_texture_to_image(game->mlx, game->texture->floor);
	game->image->wall = mlx_texture_to_image(game->mlx, game->texture->wall);
	(*game->coin)->item = mlx_texture_to_image(game->mlx, game->texture->item);
	game->image->spawn = mlx_texture_to_image(game->mlx, game->texture->spawn);
	game->image->exit = mlx_texture_to_image(game->mlx, game->texture->exit);
	game->image->player = \
		mlx_texture_to_image(game->mlx, game->texture->player);
	ft_setup_img_to_window(game, 0);
}

void	ft_setup_img_to_window(t_game *game, int i)
{
	while (game->map->grid[i])
	{
		ft_while_for_img_to_window(i, game);
		i++;
	}
	mlx_image_to_window(game->mlx, game->image->spawn, \
		game->map->pos_start_y_2 * 70, game->map->pos_start_x_2 * 70);
	mlx_image_to_window(game->mlx, game->image->player, \
		game->map->pos_start_y_2 * 70, game->map->pos_start_x_2 * 70);
}

void	ft_while_for_img_to_window(int i, t_game *game)
{
	int	j;

	j = 0;
	while (game->map->grid[i][j])
	{
		mlx_image_to_window(game->mlx, game->image->floor, j * 70, i * 70);
		if (game->map->grid[i][j] == '1')
			mlx_image_to_window(game->mlx, game->image->wall, j * 70, i * 70);
		if (game->map->grid[i][j] == 'C')
			mlx_image_to_window(game->mlx, (*game->coin)->item, j * 70, i * 70);
		if (game->map->grid[i][j] == 'E')
		{
			mlx_image_to_window(game->mlx, game->image->exit, j * 70, i * 70);
			game->map->pos_exit_x = j;
			game->map->pos_exit_y = i;
		}
		if (game->map->grid[i][j] == 'P')
		{
			game->map->pos_start_x_2 = i;
			game->map->pos_start_y_2 = j;
		}
		j++;
	}
}

void	ft_hook(void *gamed)
{
	t_game	*game;

	game = gamed;
	ft_move_perso(game);
	ft_check_coin(game);
	ft_close_window(game);
	ft_win_condition(game);
}
