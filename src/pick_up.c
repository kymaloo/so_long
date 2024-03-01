/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pick_up.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trgaspar <trgaspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 15:32:08 by trgaspar          #+#    #+#             */
/*   Updated: 2024/02/29 18:35:53 by trgaspar         ###   ########.fr       */
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
		ft_lst_parse(game, y, x);
	}		
}

void	ft_lst_parse(t_game *game, int i, int j)
{
	t_coin	*cursor;
	
	cursor = *game->coin;
	while (cursor)
	{
		//ft_print_all_lst(cursor);
		if (game->map->grid[cursor->next->y][cursor->next->x] == game->map->grid[i][j])
		{
	 		cursor->item->instances[0].enabled = 0;
			ft_lstdelone(*game->coin);//probleme movais parametre
		}
		cursor = cursor->next;
	}
}
