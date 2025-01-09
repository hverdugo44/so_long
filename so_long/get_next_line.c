/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hverdugo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 16:18:50 by hverdugo          #+#    #+#             */
/*   Updated: 2024/12/24 12:49:53 by hverdugo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	*ft_strjoint(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (s1 == NULL)
		return (ft_strdup(s2));
	str = ft_calloc((ft_strlen(s1) + ft_strlen(s2) + 1), sizeof(char));
	if (str == NULL)
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
	free(s1);
	return (str);
}

static char	*get_line(char *buff, int fd)
{
	char	*temp;
	int		bytes;

	temp = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!temp)
		return (NULL);
	bytes = read(fd, temp, BUFFER_SIZE);
	while (bytes != 0)
	{
		if (bytes == -1)
		{
			free(buff);
			free(temp);
			return (NULL);
		}
		buff = ft_strjoint(buff, temp);
		ft_bzero(temp, BUFFER_SIZE);
		if (ft_strchr(buff, 10) != NULL)
			break ;
		bytes = read(fd, temp, BUFFER_SIZE);
	}
	free(temp);
	return (buff);
}

static char	*line(char *buff)
{
	char	*linea;
	int		i;

	i = 0;
	if (!buff[0])
		return (NULL);
	while (buff[i] && buff[i] != 10)
		i++;
	if (!buff[i])
		linea = ft_calloc(i + 1, 1);
	else
		linea = ft_calloc(i + 2, 1);
	if (!linea)
		return (NULL);
	i = 0;
	while (buff[i] && buff[i] != 10)
	{
		linea[i] = buff[i];
		i++;
	}
	linea[i] = buff[i];
	return (linea);
}

static char	*limpiar(char *buff)
{
	char	*dup;
	int		x;

	x = 0;
	while (buff[x] && buff[x] != 10)
		x++;
	if (buff[x] == 0)
	{
		free(buff);
		return (NULL);
	}
	x++;
	dup = ft_strdup(&buff[x]);
	if (!dup)
		return (NULL);
	free(buff);
	return (dup);
}

char	*get_next_line(int fd)
{
	static char	*buff = NULL;
	char		*resultado;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buff = get_line(buff, fd);
	if (buff == NULL)
		return (NULL);
	resultado = line(buff);
	buff = limpiar(buff);
	return (resultado);
}
