/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trgaspar <trgaspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 19:11:12 by trgaspar          #+#    #+#             */
/*   Updated: 2024/03/30 19:12:28 by trgaspar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int	ft_putstr_fd(char *s, int fd)
{
	if (s == NULL)
		return (ft_putstr_fd("(null)", 1));
	return (write(fd, s, ft_strlen(s)));
}

int	ft_putnbr_fd(int n, int fd)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (n == -2147483648)
		return (ft_putstr_fd("-2147483648", fd));
	else if (n < 0)
	{
		if (ft_putchar_fd('-', fd) == -1)
			return (-1);
		n = -n;
		i++;
	}
	if (n >= 10)
	{
		j = ft_putnbr_fd(n / 10, fd);
		if (j == -1)
			return (-1);
		i += j;
	}
	if (ft_putchar_fd(n % 10 + '0', fd) == -1)
		return (-1);
	i++;
	return (i);
}

int	ft_putnbr_unsigned(unsigned int u)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (u >= 10)
	{
		j = ft_putnbr_fd(u / 10, 1);
		if (j == -1)
			return (-1);
		i += j;
	}
	if (ft_putchar_fd(u % 10 + '0', 1) == -1)
		return (-1);
	i++;
	return (i);
}

int	ft_putchar_fd(char c, int fd)
{
	return (write (fd, &c, 1));
}

int	ft_hexadecimal(unsigned long n, char *base, int ptr)
{
	int	i;

	i = 0;
	if (ptr)
	{
		if (ft_putstr_fd("0x", 1) == -1)
			return (-1);
		i += 2;
	}
	if (n >= 16)
		i += ft_hexadecimal(n / 16, base, 0);
	if (ft_putchar_fd(base[n % 16], 1) == -1)
		return (-1);
	i++;
	return (i);
}
