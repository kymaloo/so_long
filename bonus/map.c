/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trgaspar <trgaspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 14:19:41 by trgaspar          #+#    #+#             */
/*   Updated: 2024/04/15 21:27:02 by trgaspar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong_bonus.h"

void	ft_count_line(t_game *game, int fd)
{
	char	*gnl;

	gnl = get_next_line(fd);
	while (gnl)
	{
		free(gnl);
		game->map->count_line++;
		gnl = get_next_line(fd);
	}
}

int	ft_stock_map(t_game *game, int fd)
{
	int	status;
	int	i;

	status = EXIT_FAILURE;
	i = 0;
	game->map->grid = malloc(sizeof(char *) * (game->map->count_line + 1));
	if (game->map->grid)
	{
		while (i < game->map->count_line)
		{
			game->map->grid[i] = get_next_line(fd);
			if (game->map->grid[i])
				status = EXIT_SUCCESS;
			else
			{
				ft_printf("Error: The copy failed\n");
				ft_free_all(game->map->grid, i);
			}
			i++;
		}
		game->map->grid[i] = NULL;
	}
	else
		ft_printf("Error: The malloc failed\n");
	return (status);
}

int	ft_copy_stock_map(t_game *game)
{
	int	status;
	int	i;

	status = EXIT_FAILURE;
	i = 0;
	game->map->grid_copy = malloc(sizeof(char *) * (game->map->count_line + 1));
	if (game->map->grid_copy)
	{
		while (i < game->map->count_line)
		{
			game->map->grid_copy[i] = ft_strdup(game->map->grid[i]);
			if (game->map->grid_copy[i])
				status = EXIT_SUCCESS;
			else
			{
				ft_printf("Error: The Dup failed\n");
				ft_free_all(game->map->grid_copy, i);
			}
			i++;
		}
		game->map->grid_copy[i] = NULL;
	}
	else
		ft_printf("Error: Copy Failed\n");
	return (status);
}

void	ft_free_all(char **tab, int i)
{
	i = -1;
	while (++i, tab[i])
		free(tab[i]);
	free(tab);
}
