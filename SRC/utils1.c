/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hverdugo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 21:33:56 by hverdugo          #+#    #+#             */
/*   Updated: 2025/01/22 12:23:28 by hverdugo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INC/so_long.h"

void	free_error_map(t_game *map, char **copy)
{
	free(map->map_str);
	free_mat(map->map);
	free_mat(copy);
	free(map);
	exit(1);
}

void	handle_error(char **copy, char *str, t_game *map, int m)
{
	if (ft_strncmp(&str[ft_strlen(str) - 4], ".ber", 4) != 0)
	{
		perror("Error\nMap most be .ber");
		free_error_map(map, copy);
	}
	if (size_map(&map) != 0
		|| ((map->x + 1) * map->y) < (int)ft_strlen(map->map_str)
		|| ((map->x + 1) * map->y) > (int)ft_strlen(map->map_str) + 1)
	{
		perror("Error\nMap size is wrong");
		free_error_map(map, copy);
	}
	if (find_path(copy, &m, map->px, map->py) != 0)
	{
		perror("Error\nInvalid path");
		free_error_map(map, copy);
	}
	if (map->p != 1 || map->e != 1)
	{
		perror("Error\nMore than 1 player or more than 1 exit");
		free_error_map(map, copy);
	}
	free(map->map_str);
}

char	**copy_mat(char **str)
{
	char	**copy;
	int		i;

	i = 0;
	copy = (char **)ft_calloc(sizeof(char *), (mat_len(str) + 1));
	if (!copy)
		return (NULL);
	while (str[i])
	{
		copy[i] = ft_strdup(str[i]);
		i++;
	}
	return (copy);
}
