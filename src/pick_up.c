/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pick_up.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trgaspar <trgaspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 15:32:08 by trgaspar          #+#    #+#             */
/*   Updated: 2024/03/26 16:49:58 by trgaspar         ###   ########.fr       */
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
		ft_lst_parse(game, y, x);
}

void	ft_lst_parse(t_game *game, int i, int j)
{
	t_coin	*cursor;
	int		k;

	k = 0;
	cursor = *game->coin;
	while (cursor)
	{
		if (cursor->y == i && cursor->x == j \
			&& (*game->coin)->item->instances[k].enabled)
		{
			(*game->coin)->item->instances[k].enabled = 0;
			game->map->grid[i][j] = '0';
			game->map->nb_coin++;
			return ;
		}
		else
			cursor = cursor->next;
		k++;
	}
}
