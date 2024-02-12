/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_finding.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trgaspar <trgaspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 14:09:55 by trgaspar          #+#    #+#             */
/*   Updated: 2024/02/12 15:22:57 by trgaspar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int	ft_path_finding(int x, int y, char **cells)
{
	int	end;

	end = 0;
	if (cells[x][y] == 'C' || cells[x][y] == 'E')
		++end;
	cells[x][y] = '1';
	if (cells[x + 1][y] != '1')
		end += ft_path_finding(x + 1, y, cells);
	if (cells[x - 1][y] != '1')
		end += ft_path_finding(x - 1, y, cells);
	if (cells[x][y + 1] != '1')
		end += ft_path_finding(x, y + 1, cells);
	if (cells[x][y - 1] != '1')
		end += ft_path_finding(x, y - 1, cells);
	return (end);
}
