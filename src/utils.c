/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trgaspar <trgaspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 14:53:47 by trgaspar          #+#    #+#             */
/*   Updated: 2024/02/09 15:15:01 by trgaspar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*s1_cast;
	unsigned char	*s2_cast;

	s1_cast = (unsigned char *)s1;
	s2_cast = (unsigned char *)s2;
	i = 0;
	while (s1_cast[i] == s2_cast[i] && s1_cast[i] && s2_cast[i] && i < n)
		i++;
	if (n == i)
		return (0);
	return (s1_cast[i] - s2_cast[i]);
}