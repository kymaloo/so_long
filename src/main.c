/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trgaspar <trgaspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 16:48:38 by trgaspar          #+#    #+#             */
/*   Updated: 2024/02/09 21:04:33 by trgaspar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int main(void)
{
	t_game	*game;
	game = malloc(sizeof(t_game));
	game->map = malloc(sizeof(t_map));
	char 	*str;
	int		fd;

	str = "maps/map.ber";
	fd = open(str, O_RDONLY);
	ft_count_line(game, fd);
	close(fd);
	fd = open(str, O_RDONLY);
	ft_stock_map(game, fd);
	close(fd);
	printf("%d\n", check_map(game));
	free(game->map->grid);
	free(game->map);
	free(game);
	return (0);
}
