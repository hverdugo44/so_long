/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hverdugo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 21:33:56 by hverdugo          #+#    #+#             */
/*   Updated: 2024/12/25 22:24:04 by hverdugo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**copy_mat(char **str)
{
	char	**copy;
	int	i;

	i = 0;
	copy = (char **)malloc(sizeof(char *) * mat_len(str));
	if (!copy)
		return (NULL);
	while (str[i])
	{
		copy[i] = ft_strdup(str[i]);
		i++;
	}
	return (copy);
}
