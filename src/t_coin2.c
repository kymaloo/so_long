/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_coin2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trgaspar <trgaspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 15:03:51 by trgaspar          #+#    #+#             */
/*   Updated: 2024/03/26 16:48:07 by trgaspar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	ft_lstdelone(void *mlx, t_coin *coin)
{
	if (coin)
	{
		mlx_delete_image(mlx, coin->item);
		free(coin);
	}
}

void	ft_lstclear(t_coin **coin, void *mlx)
{
	t_coin	*tmp;
	t_coin	*tmp2;

	if (!coin)
		return ;
	tmp = *coin;
	while (tmp)
	{
		tmp2 = tmp->next;
		ft_lstdelone(mlx, tmp);
		tmp = tmp2;
	}
	*coin = NULL;
}
