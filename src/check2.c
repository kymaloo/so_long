/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trgaspar <trgaspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 14:26:58 by trgaspar          #+#    #+#             */
/*   Updated: 2024/03/25 14:27:24 by trgaspar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	ft_check_exit_item_start2(int i, t_game *game)
{
	int	j;

	while (game->map->grid[i])
	{
		j = 0;
		while (game->map->grid[i][j])
		{
			if (game->map->grid[i][j] == 'E')
				game->map->exit++;
			if (game->map->grid[i][j] == 'C')
			{
				game->map->item++;
				ft_lstadd_back(game->coin, ft_lstnew(i, j));
			}
			if (game->map->grid[i][j] == 'P')
			{
				game->map->start++;
				game->map->pos_start_x = j;
				game->map->pos_start_y = i;
			}
			j++;
		}
		i++;
	}
}
