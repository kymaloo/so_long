/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trgaspar <trgaspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 15:24:41 by trgaspar          #+#    #+#             */
/*   Updated: 2024/03/30 19:20:49 by trgaspar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int	ft_open_map(t_game *game)
{
	char	*str;
	int		fd;

	str = "maps/map.ber";
	if (ft_check_map_format_ber(str) != 0)
		return (ft_printf("Error: The map is not a good format!\n"), -1);
	fd = open(str, O_RDONLY);
	if (fd == -1)
		return (ft_printf("Error: The map is not open!\n"), -1);
	ft_count_line(game, fd);
	close(fd);
	fd = open(str, O_RDONLY);
	if (fd == -1)
		return (ft_printf("Error: The map is not open!\n"), -1);
	ft_stock_map(game, fd);
	close(fd);
	return (0);
}

int	ft_init_check(t_game *game)
{
	if (ft_check_map_is_rectangle(game) != 0)
		return (ft_printf("Error: The map is not a rectangle!\n"), -1);
	if (ft_check_wall(game) != 0)
		return (ft_printf("Error: No wall around the map!\n"), -1);
	if (ft_check_map(game) != 0)
		return (ft_printf("Error: The map is not valid!\n"), -1);
	if (ft_check_exit_item_start(game, 0) != 0)
		return (ft_printf("Error: The map does not have the prerequistes!\n"), -1);
	if (ft_path_finding(game->map->pos_start_y, \
		game->map->pos_start_x, game->map->grid_copy) \
		!= (game->map->exit + game->map->item))
		return (ft_printf("Error: The map does not have a valid path!\n"), -1);
	return (0);
}

int	ft_init_window(t_game *game)
{
	int	i;
	int	j;

	i = game->map->line_size;
	j = game->map->count_line;
	game->mlx = mlx_init(i * 70, j * 70, "MLX42", true);
	if (!game->mlx)
		return (ft_printf("Error: MLX is not init!\n"), -1);
	return (0);
}

int	init_value(t_game *game)
{	
	game->map = malloc(sizeof(t_map));
	if (!game->map)
	{
		free(game);
		return (ft_printf("Error: Malloc crash!\n"), -1);
	}
	game->texture = malloc(sizeof(t_texture));
	if (!game->texture)
	{
		free(game);
		return (ft_printf("Error: Malloc crash!\n"), -1);
	}
	game->image = malloc(sizeof(t_image));
	if (!game->image)
	{
		free(game);
		return (ft_printf("Error: Malloc crash!\n"), -1);
	}
	game->count_move = 0;
	game->map->count_line = 0;
	game->map->exit = 0;
	game->map->item = 0;
	game->map->start = 0;
	return (0);
}

int	init_game(t_game *game)
{
	if (init_value(game) != 0)
		return (ft_printf("Error: The value is not init!\n"), -1);
	if (ft_open_map(game) != 0)
		return (ft_printf("Error: The map is not open!\n"), -1);
	ft_copy_stock_map(game);
	if (ft_init_check(game) != 0)
		return (ft_printf("Error: Echec Check!\n"), -1);
	if (ft_init_window(game) != 0)
		return (ft_printf("Error:  MLX is not init!\n"), -1);
	ft_setup_texture(game);
	return (0);
}
