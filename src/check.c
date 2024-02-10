/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trgaspar <trgaspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 14:51:52 by trgaspar          #+#    #+#             */
/*   Updated: 2024/02/09 21:10:40 by trgaspar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int	check_map_format_ber(char *str)
{
	int		len_str;
	
	len_str = ft_strlen(str);
	if (len_str < 5)
		return (-1);
	if (ft_strncmp(&str[len_str - 4], ".ber", 4) != 0)
		return (-1);
	return (0);
}

int	check_map_is_rectangle(t_game *game)
{
	int	i;
	
	i = 0;
	game->map->line_size = ft_strlen(game->map->grid[i]);
	i++;
	while (i != game->map->count_line)
	{
		if (ft_strlen(game->map->grid[i]) != game->map->line_size)
			return (-1);
		i++;
	}
	return (0);
}

int	check_wall(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map->grid[0][i])
		if (game->map->grid[0][i++] != '1')
			return (-1);
	i = 1;
	game->map->line_size = ft_strlen(game->map->grid[i]);
	j = game->map->line_size - 1;
	while (game->map->grid[i] && i < game->map->count_line)
	{
		if (game->map->grid[i][j] != '1' || game->map->grid[i][0] != '1')
			return (-1);	
		i++;
	}
	i = 0;
	while (game->map->grid[game->map->count_line - 1][i])
		if (game->map->grid[game->map->count_line - 1][i++] != '1')
			return (-1);
	return (0);
}

int	check_map(t_game *game)
{
	int i;
	int j;

	i = 0;
	while (game->map->grid[i] != NULL)
	{
		j = 0;
		while (game->map->grid[i][j] != '\0')
		{
			if (game->map->grid[i][j] != '1' && game->map->grid[i][j] != '0' &&
			game->map->grid[i][j] != 'C' && game->map->grid[i][j] != 'P' &&
			game->map->grid[i][j] != 'E')
				return (-1);
			j++;
		}
		i++;
	}
	return (0);
}

// int	path_finding(size_t x, size_t y, char **cells)
// {
// 	int	end;

// 	end = 0;
// 	if (cells[x][y] == 'C' || cells[x][y] == 'E')
// 		++end;
// 	cells[x][y] = '#';
// 	if (cells[x + 1][y] != '1' && cells[x + 1][y] != '#')
// 		end += path_finding(x + 1, y, cells);
// 	if (cells[x - 1][y] != '1' && cells[x - 1][y] != '#')
// 		end += path_finding(x - 1, y, cells);
// 	if (cells[x][y + 1] != '1' && cells[x][y + 1] != '#')
// 		end += path_finding(x, y + 1, cells);
// 	if (cells[x][y - 1] != '1' && cells[x][y - 1] != '#')
// 		end += path_finding(x, y - 1, cells);
// 	return (end);
// }
