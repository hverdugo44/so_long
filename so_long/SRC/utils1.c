/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hverdugo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 21:33:56 by hverdugo          #+#    #+#             */
/*   Updated: 2025/01/09 13:13:11 by hverdugo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INC/so_long.h"

char	**copy_mat(char **str)
{
	char	**copy;
	int	i;

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
