/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_finding.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trgaspar <trgaspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 14:09:55 by trgaspar          #+#    #+#             */
/*   Updated: 2024/04/15 21:27:08 by trgaspar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong_bonus.h"

static void	ft_path_finding2(int *x, int *y, char **cells, t_game *game)
{
	if (cells[*x][*y] == 'D')
	{
		cells[*x][*y] = '1';
		*y = game->map->pos_tp2_x;
		*x = game->map->pos_tp2_y;
	}
	else if (cells[*x][*y] == 'A')
	{
		cells[*x][*y] = '1';
		*y = game->map->pos_tp1_x;
		*x = game->map->pos_tp1_y;
	}
}

int	ft_path_finding(int x, int y, char **cells, t_game *game)
{
	int	end;

	end = 0;
	if (cells[x][y] == 'C' || cells[x][y] == 'E')
		++end;
	ft_path_finding2(&x, &y, cells, game);
	cells[x][y] = '1';
	if (cells[x + 1][y] != '1' && cells[x + 1][y] != 'T')
		end += ft_path_finding(x + 1, y, cells, game);
	if (cells[x - 1][y] != '1' && cells[x - 1][y] != 'T')
		end += ft_path_finding(x - 1, y, cells, game);
	if (cells[x][y + 1] != '1' && cells[x][y + 1] != 'T')
		end += ft_path_finding(x, y + 1, cells, game);
	if (cells[x][y - 1] != '1' && cells[x][y - 1] != 'T')
		end += ft_path_finding(x, y - 1, cells, game);
	return (end);
}
