/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trgaspar <trgaspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 16:48:38 by trgaspar          #+#    #+#             */
/*   Updated: 2024/02/08 19:54:36 by trgaspar         ###   ########.fr       */
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
	ft_count_line(fd, game);
	printf("%d\n", game->map->count_line);
	close(fd);
	free(game->map);
	free(game);
	//printf("Zalope");
	return (0);
}

void ft_count_line(int fd, t_game *game)
{
	char *gnl;

	game->map->count_line = 0;
	gnl = get_next_line(fd);
	while (gnl)
	{
		free(gnl);
		game->map->count_line++;
		gnl = get_next_line(fd);
	}
}