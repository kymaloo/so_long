/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trgaspar <trgaspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 15:24:41 by trgaspar          #+#    #+#             */
/*   Updated: 2024/02/12 16:00:58 by trgaspar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int	ft_open_map(t_game *game)
{
	char 	*str;
	int		fd;

	str = "maps/map.ber";
	if (ft_check_map_format_ber(str) != 0)
		return (-1);
	fd = open(str, O_RDONLY);
	if (fd == -1)
		return (-1);
	ft_count_line(game, fd);
	close(fd);
	fd = open(str, O_RDONLY);
	if (fd == -1)
		return (-1);
	ft_stock_map(game, fd);
	close(fd);
	return (0);
}

int	ft_init_check(t_game *game)
{
	if (ft_check_map_is_rectangle(game) != 0)
		return (-1);
	if (ft_check_wall(game) != 0)
		return (-1);
	if (ft_check_map(game) != 0)
		return (-1);
	if (ft_check_exit_item_start(game, 0) != 0)
		return (-1);
	if (ft_path_finding(game->map->pos_start_y, game->map->pos_start_x, game->map->grid_copy) != (game->map->exit + game->map->item))
		return (-1);
	return (0);
}
