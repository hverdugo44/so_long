/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hverdugo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 17:56:25 by hverdugo          #+#    #+#             */
/*   Updated: 2025/01/11 21:57:25 by hverdugo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INC/so_long.h"

int	pressed_key(int keycode, t_game *gm)
{
	if (keycode == ESC)
		close_program(gm);
	else if (keycode == UP || keycode == AUP)
		move_up(gm, keycode);
	else if (keycode == DOWN || keycode == ADOWN)
		move_down(gm, keycode);
	else if (keycode == LEFT || keycode == ALEFT)
		move_left(gm, keycode);
	else if (keycode == RIGHT || keycode == ARIGHT)
		move_right(gm, keycode);
	return (0);
}

void	check_finish(int keycode, t_game *gm)
{
	if (keycode == UP || keycode == AUP)
		gm->py--;
	else if (keycode == DOWN || keycode == ADOWN)
		gm->py++;
	else if (keycode == LEFT || keycode == ALEFT)
		gm->px--;
	else if (keycode == RIGHT || keycode == ARIGHT)
		gm->px++;
	if (gm->map[gm->py][gm->px] == 'E' && gm->collect == 0)
		ft_win(gm);
/*	else if (gm->map[gm->py][gm->px] == 'E' && gm->collect != 0)
		ft_lose(gm);*/
}

void	ft_win(t_game *gm)
{
	mlx_destroy_window(gm->mlx, gm->win);
	free(gm->mlx);
	free_mat(gm->map);
	free(gm);
	exit(0);
}

int	close_program(t_game *gm)
{
	mlx_destroy_window(gm->mlx, gm->win);
	free(gm->mlx);
	free_mat(gm->map);
	free(gm);
	exit(0);
}
