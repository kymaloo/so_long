/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trgaspar <trgaspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 14:53:47 by trgaspar          #+#    #+#             */
/*   Updated: 2024/04/19 17:49:29 by trgaspar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong_bonus.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*s1_cast;
	unsigned char	*s2_cast;

	s1_cast = (unsigned char *)s1;
	s2_cast = (unsigned char *)s2;
	i = 0;
	while (s1_cast[i] == s2_cast[i] && s1_cast[i] && s2_cast[i] && i < n - 1)
		i++;
	if (n == i)
		return (-1);
	return (s1_cast[i] - s2_cast[i]);
}

char	*ft_strdup(const char *s)
{
	char	*str;
	int		i;

	i = 0;
	str = malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!str)
		return (NULL);
	while (s[i])
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

void	ft_close_window(t_game *game)
{
	if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(game->mlx);
}

void	ft_delete_texture(t_game *game)
{
	mlx_delete_texture(game->texture->floor);
	game->texture->floor = NULL;
	mlx_delete_texture(game->texture->wall);
	game->texture->wall = NULL;
	mlx_delete_texture(game->texture->spawn);
	game->texture->spawn = NULL;
	mlx_delete_texture(game->texture->exit);
	game->texture->exit = NULL;
	mlx_delete_texture(game->texture->player);
	game->texture->player = NULL;
	mlx_delete_texture(game->texture->player2);
	game->texture->player2 = NULL;
	mlx_delete_texture(game->texture->item);
	game->texture->item = NULL;
	mlx_delete_texture(game->texture->flag);
	game->texture->flag = NULL;
	mlx_delete_texture(game->texture->trap);
	game->texture->trap = NULL;
}
