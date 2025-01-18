/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   imagenes.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hverdugo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 15:03:05 by hverdugo          #+#    #+#             */
/*   Updated: 2025/01/15 15:52:11 by hverdugo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INC/so_long.h"

void	images_to_win(t_game *gm)
{
	int	x;
	int	y;

	y = 0;
	while (y < gm->y)
	{
		x = 0;
		while (x < gm->x)
		{
			map_fill(gm, x, y);
			x++;
		}
		y++;
	}
}

void	map_fill(t_game *gm, int x, int y)
{
	int	i;

	i = IMG_PXL;
	if (gm->map[y][x] == '0' || gm->map[y][x] == 'P' || gm->map[y][x] == 'C')
		mlx_put_image_to_window(gm->mlx, gm->win, gm->back, x * i, y * i);
	if (gm->map[y][x] == 'P')
		mlx_put_image_to_window(gm->mlx, gm->win, gm->p_rg, x * i, y * i);
	if (gm->map[y][x] == 'C')
		mlx_put_image_to_window(gm->mlx, gm->win, gm->clct, x * i, y * i);
	if (gm->map[y][x] == 'E')
		mlx_put_image_to_window(gm->mlx, gm->win, gm->esc, x * i, y * i);
	if (gm->map[y][x] == '1')
		mlx_put_image_to_window(gm->mlx, gm->win, gm->wall, x * i, y * i);
}

void	images(t_game *gm)
{
	int	i;
	int	j;
	int	k;

	k = 720;
	j = 1280;
	i = IMG_PXL;
	gm->p_up = mlx_xpm_file_to_image(gm->mlx, "textures/up.xpm", &i, &i);
	gm->p_dn = mlx_xpm_file_to_image(gm->mlx, "textures/down.xpm", &i, &i);
	gm->p_lf = mlx_xpm_file_to_image(gm->mlx, "textures/izq.xpm", &i, &i);
	gm->p_rg = mlx_xpm_file_to_image(gm->mlx, "textures/der.xpm", &i, &i);
	gm->back = mlx_xpm_file_to_image(gm->mlx, "textures/back.xpm", &i, &i);
	gm->clct = mlx_xpm_file_to_image(gm->mlx, "textures/collect.xpm", &i, &i);
	gm->esc = mlx_xpm_file_to_image(gm->mlx, "textures/exit.xpm", &i, &i);
	gm->wall = mlx_xpm_file_to_image(gm->mlx, "textures/wall.xpm", &i, &i);
	gm->winner = mlx_xpm_file_to_image(gm->mlx, "textures/win.xpm", &j, &k);
}
