/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trgaspar <trgaspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 16:45:01 by trgaspar          #+#    #+#             */
/*   Updated: 2024/04/19 17:07:42 by trgaspar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int	ft_open_map2(t_game *game, int status, char *str)
{
	int	fd;

	fd = open(str, O_RDONLY);
	if (fd != -1)
	{
		ft_count_line(game, fd);
		close(fd);
		fd = open(str, O_RDONLY);
		if (fd != -1)
		{
			if (ft_stock_map(game, fd) == 0)
			{
				close(fd);
				status = EXIT_SUCCESS;
			}
			else
				ft_printf("Error: Stock Failed!\n");
		}
		else
			ft_printf("Error: The map is not open!\n");
	}
	else
		ft_printf("Error: The map is not open!\n");
	return (status);
}

int	ft_init_check2(t_game *game, int status)
{
	if (ft_check_map(game) == 0)
	{
		if (ft_check_exit_item_start(game, 0) == 0)
		{
			if (ft_path_finding(game->map->pos_start_y, game->map->pos_start_x, \
			game->map->grid_copy) == (game->map->exit + game->map->item))
				status = EXIT_SUCCESS;
			else
				ft_printf("Error: The map does not have a valid path!\n");
		}
		else
			ft_printf("Error: The map does not have the prerequistes!\n");
	}
	else
		ft_printf("Error: The map is not valid!\n");
	return (status);
}

int	ft_init_game2(t_game *game, char *str, int status)
{
	if (ft_open_map(game, str) == 0)
	{
		ft_copy_stock_map(game);
		if (ft_init_check(game) == 0)
		{
			if (ft_init_window(game) == 0)
			{
				ft_setup_texture(game);
				status = EXIT_SUCCESS;
			}
			else
				ft_printf("Error:  MLX is not init!\n");
		}
		else
			ft_printf("Error: Echec Check!\n");
	}
	else
		ft_printf("Error: The map is not open!\n");
	return (status);
}
