/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_coin2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trgaspar <trgaspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 15:03:51 by trgaspar          #+#    #+#             */
/*   Updated: 2024/04/15 21:27:20 by trgaspar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong_bonus.h"

void	ft_lstclear(t_coin **coin)
{
	t_coin	*tmp;
	t_coin	*tmp2;

	if (!coin)
		return ;
	tmp = *coin;
	while (tmp)
	{
		tmp2 = tmp->next;
		if (coin)
			free(tmp);
		tmp = tmp2;
	}
	*coin = NULL;
}
