/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hverdugo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 23:05:04 by hverdugo          #+#    #+#             */
/*   Updated: 2025/01/22 12:26:31 by hverdugo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INC/so_long.h"

int	size_map(t_game **map)
{
	int	i;

	i = 0;
	(*map)->x = ft_strlen((*map)->map[0]);
	(*map)->y = mat_len((*map)->map);
	while (i < (*map)->x)
	{
		if ((*map)->map[0][i] != '1' || (*map)->map[(*map)->y - 1][i] != '1')
			return (1);
		i++;
	}
	i = 0;
	while (i < (*map)->y)
	{
		if ((*map)->map[i][0] != '1' || (*map)->map[i][(*map)->x - 1] != '1')
			return (1);
		i++;
	}
	i = 0;
	while ((*map)->map[++i])
	{
		if ((*map)->x != (int)ft_strlen((*map)->map[i]))
			return (1);
	}
	return (0);
}

char	**do_map(char *str, t_game *gm)
{
	int		fd;
	char	*str1;
	char	*map;
	char	*temp;
	char	**map1;

	map = NULL;
	fd = open(str, O_RDONLY);
	if (fd <= 0)
		return (NULL);
	str1 = get_next_line(fd);
	temp = get_next_line(fd);
	while (temp != NULL)
	{
		map = ft_strjoin(str1, temp);
		free(str1);
		free(temp);
		str1 = map;
		temp = get_next_line(fd);
	}
	close(fd);
	map1 = ft_split(map, '\n');
	gm->map_str = map;
	return (map1);
}

void	find_collect(t_game *game)
{
	int	i;
	int	j;

	game->collect = 0;
	i = 0;
	game->p = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'C')
				game->collect++;
			if (game->map[i][j] == 'P')
			{
				game->py = i;
				game->px = j;
				game->p++;
			}
			if (game->map[i][j] == 'E')
				game->e++;
			j++;
		}
		i++;
	}
}

int	find_path(char **map, int *collect, int px, int py)
{
	if (map[py][px] == 'C' || map[py][px] == 'E')
		collect[0]--;
	map[py][px] = 'x';
	if (map[py][px - 1] != '1' && map[py][px - 1] != 'x')
		find_path(map, collect, px - 1, py);
	if (map[py][px + 1] != '1' && map[py][px + 1] != 'x')
		find_path(map, collect, px + 1, py);
	if (map[py + 1][px] != '1' && map[py + 1][px] != 'x')
		find_path(map, collect, px, py + 1);
	if (map[py - 1][px] != '1' && map[py - 1][px] != 'x')
		find_path(map, collect, px, py - 1);
	return (*collect);
}

t_game	*evaluador(char *str)
{
	t_game	*map;
	char	**copy;
	int		m;

	map = (t_game *)malloc(sizeof(t_game));
	map->map = do_map(str, map);
	if (!map->map)
	{
		free(map);
		perror("Error\nThe file was not found or could not be open");
		exit(1);
	}
	map->e = 0;
	size_map(&map);
	find_collect(map);
	copy = copy_mat(map->map);
	if (!copy)
		close_x(map);
	m = map->collect + map->e;
	handle_error(copy, str, map, m);
	free_mat(copy);
	return (map);
}
