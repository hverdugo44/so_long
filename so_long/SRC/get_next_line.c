/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hverdugo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 11:04:23 by hverdugo          #+#    #+#             */
/*   Updated: 2025/01/13 02:35:27 by hverdugo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INC/get_next_line.h"

size_t	ft_strlen1(const char *c)
{
	size_t	x;

	x = 0;
	while (c[x])
		x++;
	return (x);
}

static char	*get_line(char *buff, int fd)
{
	char	*temp;
	int		bytes;

	temp = ft_calloc1(BUFFER_SIZE + 1, sizeof(char));
	if (!temp)
		return (NULL);
	while (ft_strchar1(buff, '\n') == -1)
	{
		bytes = read(fd, temp, BUFFER_SIZE);
		if (bytes == -1)
		{
			free(buff);
			free(temp);
			return (NULL);
		}
		if (bytes == 0)
			break ;
		buff = ft_strjoin1(buff, temp);
		ft_bzero1(temp, BUFFER_SIZE);
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
		linea = ft_calloc1(i + 1, 1);
	else
		linea = ft_calloc1(i + 2, 1);
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
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (buff[i] && buff[i] != '\n')
		i++;
	if (buff[i] == '\0')
	{
		free(buff);
		return (NULL);
	}
	dup = ft_calloc1(ft_strlen1(buff) - i + 1, sizeof(char));
	if (!dup)
		return (NULL);
	i++;
	while (buff[i] != 0)
		dup[j++] = buff[i++];
	free(buff);
	return (dup);
}

char	*get_next_line(int fd)
{
	static char	*buff;
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
