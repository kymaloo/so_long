/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trgaspar <trgaspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 17:16:23 by trgaspar          #+#    #+#             */
/*   Updated: 2024/04/15 21:27:31 by trgaspar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong_bonus.h"

int	ft_setup_texture(t_game *game)
{
	int		status;

	status = EXIT_FAILURE;
	game->texture->floor = mlx_load_png("image/Tiles/grassCenter.png");
	if (game->texture->floor)
	{
		game->texture->wall = mlx_load_png("image/Tiles/castleCenter.png");
		if (game->texture->wall)
		{
			game->texture->item = mlx_load_png("image/Items/coinGold.png");
			if (game->texture->item)
			{
				status = ft_setup_texture2(game, status);
			}
			else
				ft_printf("No texture coin\n");
		}
		else
			ft_printf("No texture wall\n");
	}
	else
		ft_printf("No texture floor\n");
	return (status);
}

void	ft_setup_image(t_game *game)
{
	game->image->floor = mlx_texture_to_image(game->mlx, game->texture->floor);
	game->image->wall = mlx_texture_to_image(game->mlx, game->texture->wall);
	(*game->coin)->item = mlx_texture_to_image(game->mlx, game->texture->item);
	game->image->spawn = mlx_texture_to_image(game->mlx, game->texture->spawn);
	game->image->exit = mlx_texture_to_image(game->mlx, game->texture->exit);
	game->image->flag = mlx_texture_to_image(game->mlx, game->texture->flag);
	game->image->player2 = \
		mlx_texture_to_image(game->mlx, game->texture->player2);
	game->image->trap = mlx_texture_to_image(game->mlx, game->texture->trap);
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
	mlx_image_to_window(game->mlx, game->image->player2, \
		game->map->pos_start_y_2 * 70, game->map->pos_start_x_2 * 70);
	game->image->player2->instances[0].enabled = 0;
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
		ft_while_for_img_to_window2(i, j, game);
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
	ft_all_tp(game);
	ft_trap(game);
}
