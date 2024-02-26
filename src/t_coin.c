/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_coin.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trgaspar <trgaspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 19:41:29 by trgaspar          #+#    #+#             */
/*   Updated: 2024/02/26 21:40:22 by trgaspar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

t_coin	*ft_lstnew(int x, int y)
{
	t_coin	*coin;

	coin = malloc(sizeof(t_coin));
	if (!coin)
		return (NULL);
	coin->x = x;
	coin->y = y;
	coin->next = NULL;
	return (coin);
}

int	ft_lstsize(t_coin *coin)
{
	int	i;

	i = 0;
	while (coin)
	{
		coin = coin->next;
		i++;
	}
	return (i);
}

t_coin	*ft_lstlast(t_coin *coin)
{
	size_t	i;

	i = ft_lstsize(coin);
	while (i-- > 1)
		coin = coin->next;
	return (coin);
}

void	ft_lstadd_back(t_coin **coin, t_coin *new)
{
	t_coin	*tmp;

	if (!*coin)
		*coin = new;
	else
	{
		tmp = ft_lstlast(*coin);
		tmp->next = new;
	}
}


void	ft_lst_parse(t_game *game)
{
	while ((*game->coin)->next)
	{
		if (game->map->grid[(*game->coin)->x][(*game->coin)->y] == 'C')
			game->image->item->instances[0].enabled = 0;
		*game->coin = (*game->coin)->next;
	}
}
