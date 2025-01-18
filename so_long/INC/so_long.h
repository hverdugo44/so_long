/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hverdugo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 17:10:10 by hverdugo          #+#    #+#             */
/*   Updated: 2025/01/16 15:39:51 by hverdugo         ###   ########.fr       */
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
# include "get_next_line.h"
# include <mlx.h>

# define UP			119
# define AUP		65362
# define DOWN		115
# define ADOWN		65364
# define LEFT		97
# define ALEFT		65361
# define RIGHT		100
# define ARIGHT		65363
# define ESC		65307
# define IMG_PXL	32

typedef struct s_game
{
	void	*mlx;
	void	*win;
	void	*p_up;
	void	*p_dn;
	void	*p_lf;
	void	*p_rg;
	void	*back;
	void	*clct;
	void	*esc;
	void	*wall;
	void	*lose;
	void	*winner;
	char	**map;
	char	*map_str;
	int		collect;
	int		moves;
	int		x;
	int		y;
	int		px;
	int		py;
}		t_game;

int		main(int argc, char **argv);
char	*get_next_line(int fd);

t_game	*evaluador(char *str);
int		size_map(t_game **map);
int		find_path(char **map, int *collect, int px, int py);
int		mat_len(char **mat);
char	**do_map(char *str, t_game *map);
char	**copy_mat(char **str);
void	find_collect(t_game *game);
void	free_error_map(t_game *map, char **copy);
void	handle_error(char **copy, char *str, t_game *map, int m);
void	map_fill(t_game *gm, int x, int y);
void	free_mat(char **str);

void	images_to_win(t_game *gm);
void	images(t_game *gm);

int		pressed_key(int keycode, t_game *gm);
void	move_right(t_game *gm, int move);
void	move_left(t_game *gm, int move);
void	move_down(t_game *gm, int move);
void	move_up(t_game *gm, int move);
void	check_finish(int keycode, t_game *gm);

int		close_program(int keycode, t_game *gm);
int		close_x(t_game *gm);
void	ft_end(t_game *gm);
void	ft_win(t_game *gm);
void	ft_lose(t_game *gm);
#endif
