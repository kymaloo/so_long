/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pick_up.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trgaspar <trgaspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 15:32:08 by trgaspar          #+#    #+#             */
/*   Updated: 2024/02/27 17:35:36 by trgaspar         ###   ########.fr       */
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

void	ft_lst_parse(t_game *game, int x, int y)
{
	//printf("%p" ,(*game->coin)->next);
	t_coin **lst = game->coin;
	// printf("lst : %p | first : %p\n", lst, *lst);
	// printf("\tx : %d | y : %d\n", (*lst)->x, (*lst)->y);
	// printf("\tnext : %p\n", (*lst)->next);
	while ((*game->coin)->next != NULL)
	{
		//printf("test1");
		if (game->map->grid[y][x] == game->map->grid[(*game->coin)->x][(*game->coin)->y])
		{
			//printf("test2");
			game->image->item->instances[0].enabled = 0;
		}
		*game->coin = (*game->coin)->next;
	}
}
