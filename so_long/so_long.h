/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hverdugo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 17:10:10 by hverdugo          #+#    #+#             */
/*   Updated: 2024/12/27 17:46:20 by hverdugo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 2
# endif

# include "libft/libft.h"
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <limits.h>
# include <stdbool.h>

typedef struct s_game
{
	void	*mlx;
	void	*win;
	char	**map;
	int		collect;
	int		moves;
	int		x;
	int		y;
	int		px;
	int		py;
}	t_game;

char	*get_next_line(int fd);
void	free_mat(char **str);
t_game	*evaluador(char *str);
int	mat_len(char **mat);
char	**copy_mat(char **str);
#endif
