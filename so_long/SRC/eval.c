/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hverdugo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 23:05:04 by hverdugo          #+#    #+#             */
/*   Updated: 2025/01/09 14:11:07 by hverdugo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INC/so_long.h"

static int	size_map(t_game **map)
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

static char	**do_map(char *str)
{
	int		fd;
	char	*str1;
	char	*map;
	char	*temp;
	char	**map1;

	map = NULL;
	fd = open(str, O_RDONLY);
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
	free(map);
	return (map1);
}

static void	find_collect(t_game *game)
{
	int	i;
	int	j;
	int	c;

	c = 0;
	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'C')
				c++;
			if (game->map[i][j] == 'P')
			{
				game->py = i;
				game->px = j;
			}
			j++;
		}
		i++;
	}
	game->collect = c;
}

static int	find_path(char **map, int *collect, int px, int py)
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
	map->map = do_map(str);
	size_map(&map);
	find_collect(map);
	copy = copy_mat(map->map);
	m = map->collect + 1;
	if ((find_path(copy, &m, map->px, map->py) != 0) || size_map(&map) != 0
		|| ft_strncmp(&str[ft_strlen(str) - 4], ".ber", 4) != 0)
	{
		perror("Map Error");
		free_mat(map->map);
		free_mat(copy);
		free(map);
		exit(1);
	}
	free_mat(copy);
	return(map);
}
