/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trgaspar <trgaspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 16:48:38 by trgaspar          #+#    #+#             */
/*   Updated: 2024/02/12 17:25:43 by trgaspar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int main(void)
{
	t_game	*game;
	
	game = malloc(sizeof(t_game));
	game->map = malloc(sizeof(t_map));
	ft_open_map(game);
	ft_copy_stock_map(game);
	ft_init_check(game);
	ft_init_window(game);
	mlx_loop(game->mlx);
	free(game->map->grid_copy);
	free(game->map->grid);
	free(game->map);
	free(game);
	return (0);
}
