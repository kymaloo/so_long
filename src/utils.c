/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trgaspar <trgaspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 14:53:47 by trgaspar          #+#    #+#             */
/*   Updated: 2024/03/26 16:48:12 by trgaspar         ###   ########.fr       */
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
	{
		ft_free_img(game);
		mlx_close_window(game->mlx);
	}
}

void	ft_free_img(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map->grid[i])
	{
		j = 0;
		while (game->map->grid[i][j])
		{
			mlx_delete_image(game->mlx, game->image->floor);
			if (game->map->grid[i][j] == '1')
				mlx_delete_image(game->mlx, game->image->wall);
			if (game->map->grid[i][j] == 'C')
				mlx_delete_image(game->mlx, (*game->coin)->item);
			if (game->map->grid[i][j] == 'E')
				mlx_delete_image(game->mlx, game->image->exit);
			if (game->map->grid[i][j] == 'P')
			{
				mlx_delete_image(game->mlx, game->image->spawn);
				mlx_delete_image(game->mlx, game->image->player);
			}
			j++;
		}
		i++;
	}
}

void	ft_delete_texture(t_game *game)
{
	mlx_delete_image(game->mlx, (*game->coin)->item);
	mlx_delete_texture(game->texture->floor);
	mlx_delete_texture(game->texture->wall);
	mlx_delete_texture(game->texture->spawn);
	mlx_delete_texture(game->texture->exit);
	mlx_delete_texture(game->texture->player);
	ft_lstclear(game->coin, game->mlx);
	mlx_delete_texture(game->texture->item);
}
