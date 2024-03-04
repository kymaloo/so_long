/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_coin.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trgaspar <trgaspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 19:41:29 by trgaspar          #+#    #+#             */
/*   Updated: 2024/02/29 18:33:06 by trgaspar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

t_coin	*ft_lstnew(int y, int x)
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


void	ft_print_all_lst(t_coin *coin)
{
	t_coin	*cursor;

	cursor = coin;
	while (cursor)
	{
		printf("x : %d | y : %d\n", cursor->x, cursor->y);
		cursor = cursor->next;
	}
}

void	ft_lstdelone(t_coin **coin)
{
	t_coin	*tmp;

	if (!*(coin)->next)
	{
		free(*coin);
		return (*coin);
	}
	tmp = *coin;
	*(coin)->next = *(coin)->next->next;
	 *(coin) =  *(coin)->next;
	free(tmp);
}
