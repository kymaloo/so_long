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
	int	popo;

	popo = 0;
	
	cursor = *game->coin;
	while (cursor)
	{
		//ft_print_all_lst(cursor);
		printf("%d,%d\n%d,%d\n\n", cursor->y, cursor->x, i, j);
		if (cursor->y == i && cursor->x == j && (*game->coin)->item->instances[popo].enabled)
		{
	 		(*game->coin)->item->instances[popo].enabled = 0;
			game->map->grid[i][j] == '0';
			//ft_lstdelone(&cursor);
			return ;
		}
		else
			cursor = cursor->next;
		popo++;
	}
}
