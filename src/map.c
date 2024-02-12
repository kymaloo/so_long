/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trgaspar <trgaspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 14:19:41 by trgaspar          #+#    #+#             */
/*   Updated: 2024/02/12 16:01:39 by trgaspar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	ft_count_line(t_game *game, int fd)
{
	char	*gnl;

	game->map->count_line = 0;
	gnl = get_next_line(fd);
	while (gnl)
	{
		free(gnl);
		game->map->count_line++;
		gnl = get_next_line(fd);
	}
}

void	*ft_stock_map(t_game *game, int fd)
{
	int	i;

	i = 0;
	game->map->grid = malloc(sizeof(char *) * (game->map->count_line + 1));
	if (!game->map->grid)
	{
		ft_free_all_and_exit(game->map->grid, i);
		return (NULL);
	}
	while (i < game->map->count_line)
	{
		game->map->grid[i] = get_next_line(fd);
		i++;
	}
	game->map->grid[i] = NULL;
	return (0);
}

void	*ft_free_all_and_exit(char **tab, int i)
{
	while (tab[--i] && i >= 0)
		free(tab[i]);
	free(tab);
	exit(0);
}

void	*ft_copy_stock_map(t_game *game)
{
	int	i;

	i = 0;
	game->map->grid_copy = malloc(sizeof(char *) * (game->map->count_line + 1));
	if (!game->map->grid_copy)
	{
		ft_free_all_and_exit(game->map->grid_copy, i);
		return (NULL);
	}
	while (i < game->map->count_line)
	{
		game->map->grid_copy[i] = game->map->grid[i];
		i++;
	}
	game->map->grid_copy[i] = NULL;
	return (0);
}
