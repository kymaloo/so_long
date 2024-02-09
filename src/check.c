/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trgaspar <trgaspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 14:51:52 by trgaspar          #+#    #+#             */
/*   Updated: 2024/02/09 17:32:55 by trgaspar         ###   ########.fr       */
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
	j = game->map->line_size;
	while (game->map->grid[i])
	{
		if (game->map->grid[i][0] != '1' || game->map->grid[i][j] != '1')
			return (-1);
		i++;
	}
	i = 0;
	while (game->map->grid[i])
	{
		while (game->map->grid[i][j])
		{
			if (game->map->grid[][j] != '1')
				return (-1);
			j++;
		}
		i++;
	}
	return (0);
}
