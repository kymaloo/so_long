/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trgaspar <trgaspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 15:24:41 by trgaspar          #+#    #+#             */
/*   Updated: 2024/04/19 17:46:27 by trgaspar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong_bonus.h"

int	ft_open_map(t_game *game, char *str)
{
	int	status;

	status = EXIT_FAILURE;
	if (ft_check_map_format_ber(str) == 0)
		status = ft_open_map2(game, status, str);
	else
		ft_printf("Error: The map is not a good format!\n");
	return (status);
}

int	ft_init_check(t_game *game)
{
	int	status;

	status = EXIT_FAILURE;
	if (ft_check_map_is_rectangle(game) == 0)
	{
		if (ft_check_wall(game) == 0)
		{
			status = ft_init_check2(game, status);
		}
		else
			ft_printf("Error: No wall around the map!\n");
	}
	else
		ft_printf("Error: The map is not a rectangle!\n");
	return (status);
}

int	ft_init_window(t_game *game)
{
	int	i;
	int	j;

	i = game->map->line_size;
	j = game->map->count_line;
	if (i > 54 || j > 27)
		return (ft_printf("Error: MAP too long!\n"), -1);
	game->mlx = mlx_init(i * 70, j * 70, "MLX42", true);
	if (!game->mlx)
		return (ft_printf("Error: MLX is not init!\n"), -1);
	return (0);
}

int	init_value(t_game *game)
{
	int	status;

	status = EXIT_FAILURE;
	game->map = ft_calloc(1, sizeof(t_map));
	if (game->map)
	{
		game->texture = ft_calloc(1, sizeof(t_texture));
		if (game->texture)
		{
			game->image = ft_calloc(1, sizeof(t_image));
			if (game->image)
			{
				status = EXIT_SUCCESS;
			}
			else
				ft_printf("Error: Calloc crash!\n");
		}
		else
			ft_printf("Error: Calloc crash!\n");
	}
	else
		ft_printf("Error: Calloc crash!\n");
	return (status);
}

int	init_game(t_game *game, char *str)
{
	int	status;

	status = EXIT_FAILURE;
	if (init_value(game) == 0)
		status = ft_init_game2(game, str, status);
	else
		ft_printf("Error: The value is not init!\n");
	return (status);
}
