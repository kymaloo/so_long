/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trgaspar <trgaspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 19:13:02 by trgaspar          #+#    #+#             */
/*   Updated: 2024/03/30 19:17:04 by trgaspar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int	ft_parse_percent(char *str, va_list params)
{
	size_t	i;
	int		j;
	int		size;

	i = 0;
	size = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			j = ft_format(str[++i], params);
			if (j == -1)
				return (-1);
			size += j;
		}
		else if (ft_putchar_fd(str[i], 1) == -1)
			return (-1);
		else
			size ++;
		if (str[i])
			i++;
	}
	return (size);
}

int	ft_format(char format, va_list	params)
{
	char	*base;
	char	*base1;

	base = "0123456789abcdef";
	base1 = "0123456789ABCDEF";
	if (format == 'c')
		return (ft_putchar_fd(va_arg(params, int), 1));
	if (format == 's')
		return (ft_putstr_fd(va_arg(params, char *), 1));
	if (format == 'd' || format == 'i')
		return (ft_putnbr_fd(va_arg(params, int), 1));
	if (format == 'u')
		return (ft_putnbr_unsigned(va_arg(params, unsigned int)));
	if (format == 'x')
		return (ft_hexadecimal(va_arg(params, unsigned int), base, 0));
	if (format == 'X')
		return (ft_hexadecimal(va_arg(params, unsigned int), base1, 0));
	if (format == 'p')
		return (ft_hexadecimal(va_arg(params, unsigned long), base, 1));
	if (format == '%')
		return (ft_putchar_fd('%', 1));
	return (-1);
}

int	ft_printf(const char *format, ...)
{
	va_list	params;
	char	*c_format;
	int		size;

	c_format = (char *)format;
	va_start(params, format);
	size = ft_parse_percent(c_format, params);
	va_end(params);
	return (size);
}
