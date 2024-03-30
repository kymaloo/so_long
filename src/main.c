/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trgaspar <trgaspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 16:48:38 by trgaspar          #+#    #+#             */
/*   Updated: 2024/03/30 19:20:56 by trgaspar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int	main(void)
{
	t_game	*game;

	game = malloc(sizeof(t_game));
	if (!game)
		return (-1);
	if (init_game(game) != 0)
		return (ft_printf("Error: Init failed!\n"), -1);
	game->map->nb_coin = 0;
	mlx_loop_hook(game->mlx, &ft_hook, game);
	mlx_loop(game->mlx);
	return (0);
}
