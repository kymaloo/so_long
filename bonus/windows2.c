/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   windows2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trgaspar <trgaspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 17:59:53 by trgaspar          #+#    #+#             */
/*   Updated: 2024/04/15 21:27:34 by trgaspar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong_bonus.h"

int	ft_setup_texture2(t_game *game, int status)
{
	game->texture->spawn = mlx_load_png("image/Items/star.png");
	if (game->texture->spawn)
	{
		game->texture->exit = mlx_load_png("image/Tiles/lock_blue.png");
		if (game->texture->exit)
			status = ft_setup_texture3(game, status);
		else
			ft_printf("No texture exit\n");
	}
	else
		ft_printf("No texture spawn\n");
	return (status);
}

int	ft_setup_texture3(t_game *game, int status)
{
	game->texture->player = mlx_load_png("image/Player/top.png");
	if (game->texture->player)
	{
		game->texture->flag = mlx_load_png("image/Items/flagBlue.png");
		if (game->texture->flag)
			status = ft_setup_texture4(game, status);
		else
			ft_printf("No texture flag\n");
	}
	else
		ft_printf("No texture player\n");
	return (status);
}

int	ft_setup_texture4(t_game *game, int status)
{
	game->texture->player2 = mlx_load_png("image/Player/top2.png");
	if (game->texture->player2)
	{
		game->texture->trap = mlx_load_png("image/Tiles/liquidLava.png");
		if (game->texture->trap)
		{
			status = EXIT_SUCCESS;
			ft_setup_image(game);
		}
		else
			ft_printf("No texture trap\n");
	}
	else
		ft_printf("No texture player2\n");
	return (status);
}

void	ft_while_for_img_to_window2(int i, int j, t_game *game)
{
	if (game->map->grid[i][j] == 'A' || game->map->grid[i][j] == 'D')
		mlx_image_to_window(game->mlx, game->image->flag, j * 70, i * 70);
	if (game->map->grid[i][j] == 'T')
		mlx_image_to_window(game->mlx, game->image->trap, j * 70, i * 70);
}
