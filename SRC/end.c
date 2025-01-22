/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hverdugo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 13:04:24 by hverdugo          #+#    #+#             */
/*   Updated: 2025/01/20 16:02:50 by hverdugo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INC/so_long.h"

void	ft_win(t_game *gm)
{
	gm->win = mlx_new_window(gm->mlx, 1280, 720, "You WIN!!! :)");
	mlx_put_image_to_window(gm->mlx, gm->win, gm->winner, 0, 0);
	mlx_key_hook(gm->win, close_program, gm);
	mlx_hook(gm->win, 17, 0, close_x, gm);
	mlx_loop(gm->mlx);
}
