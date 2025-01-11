/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hverdugo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 21:33:56 by hverdugo          #+#    #+#             */
/*   Updated: 2025/01/11 14:18:03 by hverdugo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INC/so_long.h"

void	free_error_map(t_game *map, char **copy)
{
	free_mat(map->map);
	free_mat(copy);
	free(map);
	exit(1);
}

void	handle_error(char **copy, char *str, t_game *map, int m)
{
	if (ft_strncmp(&str[ft_strlen(str) - 4], ".ber", 4) != 0)
	{
		perror("Map most be .ber");
		free_error_map(map, copy);
	}
	if (size_map(&map) != 0)
	{
		perror("Map size is wrong");
		free_error_map(map, copy);
	}
	if (find_path(copy, &m, map->px, map->py) != 0)
	{
		perror("Invalid path");
		free_error_map(map, copy);
	}
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
