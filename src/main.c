/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trgaspar <trgaspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 16:48:38 by trgaspar          #+#    #+#             */
/*   Updated: 2024/03/31 20:27:34 by trgaspar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int	main(int argc, char *argv[])
{
	t_game	*game;

	game = malloc(sizeof(t_game));
	if (!game)
		return (-1);
	if (argc != 2)
		return (ft_printf("Error: No one argument", -1));
	if (init_game(game, argv[1]) != 0)
	{
		free(game->texture);
		free(game->map);
		free(game);
		return (ft_printf("Error: Init failed!\n"), -1);
	}
	game->map->nb_coin = 0;
	mlx_loop_hook(game->mlx, &ft_hook, game);
	mlx_loop(game->mlx);
	ft_free_all2(game);
	mlx_terminate(game->mlx);
	free(game);
	return (0);
}
