/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trgaspar <trgaspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 14:26:58 by trgaspar          #+#    #+#             */
/*   Updated: 2024/04/15 21:26:46 by trgaspar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong_bonus.h"

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
			ft_check_exit_item_start3(i, j, game);
			j++;
		}
		i++;
	}
}

void	ft_check_exit_item_start3(int i, int j, t_game *game)
{
	if (game->map->grid[i][j] == 'D')
	{
		game->map->tp1++;
		game->map->pos_tp1_x = j;
		game->map->pos_tp1_y = i;
	}
	if (game->map->grid[i][j] == 'A')
	{
		game->map->tp2++;
		game->map->pos_tp2_x = j;
		game->map->pos_tp2_y = i;
	}
	if (game->map->grid[i][j] == 'T')
		game->map->trap++;
}
