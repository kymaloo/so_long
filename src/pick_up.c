/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pick_up.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trgaspar <trgaspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 15:32:08 by trgaspar          #+#    #+#             */
/*   Updated: 2024/02/26 18:43:03 by trgaspar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	ft_check_coin(t_game *game)
{
	if (game->map->grid[(game->map->py + 30) / 70][(game->map->px + 30) / 70] == 'C')
		mlx_delete_image(game->mlx, game->image->item);
}

