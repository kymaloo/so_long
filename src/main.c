/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trgaspar <trgaspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 16:48:38 by trgaspar          #+#    #+#             */
/*   Updated: 2024/03/17 10:41:35 by trgaspar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int main(void)
{
	t_game	*game;
	
	game = malloc(sizeof(t_game));
	game->map = malloc(sizeof(t_map));
	game->texture = malloc(sizeof(t_texture));
	game->image = malloc(sizeof(t_image));
	init_value(game);
	ft_open_map(game);
	ft_copy_stock_map(game);
	ft_init_check(game);
	ft_init_window(game);
	ft_setup_texture(game);
	mlx_loop_hook(game->mlx, &ft_hook, game);
	mlx_loop(game->mlx);
	ft_free_img(game);
	mlx_delete_image(game->mlx, game->image->floor);
	mlx_delete_image(game->mlx, game->image->wall);
	mlx_delete_image(game->mlx, game->image->spawn);
	mlx_delete_image(game->mlx, game->image->exit);
	mlx_delete_image(game->mlx, game->image->player);
	free(game->image);
	mlx_delete_texture(game->texture->floor);
	mlx_delete_texture(game->texture->wall);
	mlx_delete_texture(game->texture->spawn);
	mlx_delete_texture(game->texture->exit);
	mlx_delete_texture(game->texture->player);
	free(game->texture);
	ft_free_all(game->map->grid_copy, game->map->count_line + 1);
	ft_free_all(game->map->grid, game->map->count_line + 1);
	free(game->map);
	//mlx_delete_image(game->mlx, img);
	//mlx_delete_texture(texture);
	mlx_terminate(game->mlx);
	free(game);
	//system("leaks solong");
	return (0);
}
