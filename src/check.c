/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trgaspar <trgaspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 14:51:52 by trgaspar          #+#    #+#             */
/*   Updated: 2024/03/30 19:39:22 by trgaspar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int	ft_check_map_format_ber(char *str)
{
	int		len_str;

	len_str = ft_strlen(str);
	if (len_str < 5)
		return (ft_printf("Error: The len of str is too small!\n"), -1);
	if (ft_strncmp(&str[len_str - 4], ".ber", 4) != 0)
		return (ft_printf("Error: The len is false!\n"), -1);
	return (0);
}

int	ft_check_map_is_rectangle(t_game *game)
{
	int	i;

	i = 0;
	game->map->line_size = ft_strlen(game->map->grid[i]);
	i++;
	while (i != game->map->count_line)
	{
		if (ft_strlen(game->map->grid[i]) != game->map->line_size)
			return (ft_printf("Error: The len size \
			different of line size!\n"), -1);
		i++;
	}
	return (0);
}

int	ft_check_wall(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map->grid[0][i])
		if (game->map->grid[0][i++] != '1')
			return (ft_printf("Error: The first line is not full wall!\n"), -1);
	i = 1;
	j = game->map->line_size - 1;
	while (game->map->grid[i] && i < game->map->count_line)
	{
		if (game->map->grid[i][j] != '1' || game->map->grid[i][0] != '1')
			return (ft_printf("Error: The first and the last char \
			is not wall!\n"), -1);
		i++;
	}
	i = 0;
	while (game->map->grid[game->map->count_line - 1][i])
		if (game->map->grid[game->map->count_line - 1][i++] != '1')
			return (ft_printf("Error: The last line is not full wall!\n"), -1);
	return (0);
}

int	ft_check_map(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map->grid[i])
	{
		j = 0;
		while (game->map->grid[i][j])
		{
			if (game->map->grid[i][j] != '1' && game->map->grid[i][j] != '0' &&
			game->map->grid[i][j] != 'C' && game->map->grid[i][j] != 'P' &&
			game->map->grid[i][j] != 'E')
				return (ft_printf("Error: The map is not ready!\n"), -1);
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_check_exit_item_start(t_game *game, int i)
{
	game->coin = malloc(sizeof(t_coin *) + 1);
	*(game->coin) = NULL;
	ft_check_exit_item_start2(i, game);
	if (game->map->exit != 1 || game->map->item < 1 || game->map->start != 1)
		return (ft_printf("Error: Nope!\n"), -1);
	return (0);
}
