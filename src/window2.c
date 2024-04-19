/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trgaspar <trgaspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 16:30:06 by trgaspar          #+#    #+#             */
/*   Updated: 2024/04/14 16:36:12 by trgaspar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int	ft_setup_texture2(t_game *game, int status)
{
	game->texture->spawn = mlx_load_png("image/Items/star.png");
	if (game->texture->spawn)
	{
		game->texture->exit = mlx_load_png("image/Tiles/lock_blue.png");
		if (game->texture->exit)
		{
			game->texture->player = mlx_load_png("image/Player/p3_stand.png");
			if (game->texture->player)
			{
				status = EXIT_SUCCESS;
				ft_setup_image(game);
			}
			else
				ft_printf("No texture player\n");
		}
		else
			ft_printf("No texture exit\n");
	}
	else
		ft_printf("No texture spawn\n");
	return (status);
}
