/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pick_up.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trgaspar <trgaspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 15:32:08 by trgaspar          #+#    #+#             */
/*   Updated: 2024/02/28 16:40:27 by trgaspar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	ft_check_coin(t_game *game)
{
	int	x;
	int	y;

	y = (game->map->py + 30) / 70;
	x = (game->map->px + 30) / 70;
	if (game->map->grid[y][x] == 'C')
	{
		//mlx_delete_image(game->mlx, game->image->item);
		ft_lst_parse(game);
	}		
}

void	ft_lst_parse(t_game *game)
{
	t_coin	*cursor;
	
	cursor = *game->coin;
	while (cursor)
	{
		//printf("test\n");
		//ft_print_all_lst(cursor);
		if (game->map->grid[cursor->y][cursor->x] == 'C')
			(*game->coin)->item->instances[0].enabled = 0;
		cursor = cursor->next;
	}
}
