/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hverdugo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 13:04:24 by hverdugo          #+#    #+#             */
/*   Updated: 2025/01/16 15:40:13 by hverdugo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INC/so_long.h"

void	ft_lose(t_game *gm)
{
	int			i;
	int			j;
	static char	path[14] = "textures/0.xpm";

	path[9] = (char)gm->collect + 48;
	i = 1280;
	j = 720;
	gm->win = mlx_new_window(gm->mlx, 1280, 720, "You lose :(");
	if (gm->collect < 6)
		path[9] = (char)gm->collect + 48;
	else
		path[9] = 't';
	gm->lose = mlx_xpm_file_to_image(gm->mlx, path, &i, &j);
	mlx_put_image_to_window(gm->mlx, gm->win, gm->lose, 0, 0);
	mlx_key_hook(gm->win, close_program, gm);
	mlx_hook(gm->win, 17, 0, close_x, gm);
	mlx_loop(gm->mlx);
}

void	ft_win(t_game *gm)
{
	gm->win = mlx_new_window(gm->mlx, 1280, 720, "You WIN!!! :)");
	mlx_put_image_to_window(gm->mlx, gm->win, gm->winner, 0, 0);
	mlx_key_hook(gm->win, close_program, gm);
	mlx_hook(gm->win, 17, 0, close_x, gm);
	mlx_loop(gm->mlx);
}
