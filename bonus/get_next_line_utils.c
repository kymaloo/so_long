/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trgaspar <trgaspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 09:23:25 by trgaspar          #+#    #+#             */
/*   Updated: 2024/04/15 21:26:49 by trgaspar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong_bonus.h"

char	*ft_strchr(const char *s, int c)
{
	char	cast_c;
	int		i;

	cast_c = (char)c;
	i = 0;
	while (s[i])
	{
		if (s[i] == cast_c)
			return ((char *)&s[i]);
		i++;
	}
	if (s[i] == cast_c)
		return ((char *)&s[i]);
	return (0);
}

char	*ft_strjoin(char *s1, char const *s2)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	str = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!str)
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		str[i + j] = s2[j];
		j++;
	}
	str[i + j] = '\0';
	free(s1);
	return (str);
}

char	*ft_get_line(char *str)
{
	char	*str_return;
	int		i;

	i = 0;
	if (!str)
		return (str);
	while (str[i] && str[i] != '\n')
		i++;
	str_return = malloc((sizeof(char) * i) + 1);
	if (!str_return)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		str_return[i] = str[i];
		i++;
	}
	str_return[i] = '\0';
	return (str_return);
}

char	*ft_get_new_line(char	*str)
{
	char	*str_return;
	int		i;
	int		j;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	str_return = malloc(((ft_strlen(str) - i) + 1) * sizeof(char));
	if (!str_return)
		return (NULL);
	j = 0;
	while (str[i])
		str_return[j++] = str[i++];
	str_return[j] = '\0';
	free(str);
	return (str_return);
}

int	ft_strlcat(char *dst, const char *src, int size)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (dst[i] && i < size)
		i++;
	while (src[j] && (i + j + 1) < size)
	{
		dst[i + j] = src[j];
		j++;
	}
	if (i < size)
		dst[i + j] = '\0';
	return (i + ft_strlen(src));
}
