/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hverdugo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 17:10:10 by hverdugo          #+#    #+#             */
/*   Updated: 2025/01/11 16:23:22 by hverdugo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 2
# endif

# include "libft.h"
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <limits.h>
# include <stdbool.h>
# include <mlx.h>

# define UP      13
# define DOWN    1
# define LEFT    0
# define RIGHT   2
# define ESC     53
# define IMG_PXL 32
# define WND_NAME "so_long"

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
	void	*p_up;
	void	*p_dn;
	void	*p_lf;
	void	*p_rg;
	void	*back;
	void	*clct;
	void	*esc;
	void	*wall;
}		t_game;

int		main(int argc, char **argv);
char	*get_next_line(int fd);

t_game	*evaluador(char *str);
int		size_map(t_game **map);
char	**do_map(char *str);
void	find_collect(t_game *game);
int		find_path(char **map, int *collect, int px, int py);
void	free_error_map(t_game *map, char **copy);
void	handle_error(char **copy, char *str, t_game *map, int m);

void	images_to_win(t_game *gm);
void	map_fill(t_game *gm, int x, int y);
void	images(t_game *gm);
int		mat_len(char **mat);
char	**copy_mat(char **str);
void	free_mat(char **str);
#endif
