/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trgaspar <trgaspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 16:48:38 by trgaspar          #+#    #+#             */
/*   Updated: 2024/04/19 17:57:49 by trgaspar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong_bonus.h"

int	main(int argc, char *argv[])
{
	int		status;
	t_game	*game;

	status = EXIT_FAILURE;
	if (argc != 2)
		ft_printf("Error: No one argument\n");
	game = ft_calloc(1, sizeof(t_game));
	if (!game)
		ft_printf("Error: Calloc Failed\n");
	if (init_game(game, argv[1]))
		ft_printf("Error: Init failed!\n");
	else
	{
		if (mlx_loop_hook(game->mlx, &ft_hook, game))
			mlx_loop(game->mlx);
		ft_delete_texture(game);
		mlx_terminate(game->mlx);
		ft_lstclear(game->coin);
		free(game->coin);
		status = EXIT_SUCCESS;
	}
	ft_free_all2(game);
	free(game);
	return (status);
}
