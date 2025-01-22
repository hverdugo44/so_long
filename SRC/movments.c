/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movments.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hverdugo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 21:00:09 by hverdugo          #+#    #+#             */
/*   Updated: 2025/01/20 17:11:10 by hverdugo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INC/so_long.h"

void	move_up(t_game *gm, int move)
{
	if (gm->map[gm->py - 1][gm->px] == 'E' && gm->collect != 0)
		return ;
	if (gm->map[gm->py - 1][gm->px] != '1')
	{
		if (gm->map[gm->py - 1][gm->px] == 'C')
		{
			gm->collect--;
			gm->map[gm->py - 1][gm->px] = '0';
		}
		mlx_put_image_to_window(gm->mlx, gm->win, gm->back, gm->px * IMG_PXL,
			gm->py * IMG_PXL);
		gm->moves++;
		ft_putstr_fd("Llevas   ", 1);
		ft_putnbr_fd(gm->moves, 1);
		ft_putstr_fd("   movimientos\n", 1);
		check_finish(move, gm);
		mlx_put_image_to_window(gm->mlx, gm->win, gm->p_up, gm->px * IMG_PXL,
			gm->py * IMG_PXL);
	}
}

void	move_down(t_game *gm, int move)
{
	if (gm->map[gm->py + 1][gm->px] == 'E' && gm->collect != 0)
		return ;
	if (gm->map[gm->py + 1][gm->px] != '1')
	{
		if (gm->map[gm->py + 1][gm->px] == 'C')
		{
			gm->collect--;
			gm->map[gm->py + 1][gm->px] = '0';
		}
		mlx_put_image_to_window(gm->mlx, gm->win, gm->back, gm->px * IMG_PXL,
			gm->py * IMG_PXL);
		gm->moves++;
		ft_putstr_fd("Llevas   ", 1);
		ft_putnbr_fd(gm->moves, 1);
		ft_putstr_fd("   movimientos\n", 1);
		check_finish(move, gm);
		mlx_put_image_to_window(gm->mlx, gm->win, gm->p_dn, gm->px * IMG_PXL,
			gm->py * IMG_PXL);
	}
}

void	move_left(t_game *gm, int move)
{
	if (gm->map[gm->py][gm->px - 1] == 'E' && gm->collect != 0)
		return ;
	if (gm->map[gm->py][gm->px - 1] != '1')
	{
		if (gm->map[gm->py][gm->px - 1] == 'C')
		{
			gm->collect--;
			gm->map[gm->py][gm->px - 1] = '0';
		}
		mlx_put_image_to_window(gm->mlx, gm->win, gm->back, gm->px * IMG_PXL,
			gm->py * IMG_PXL);
		gm->moves++;
		ft_putstr_fd("Llevas   ", 1);
		ft_putnbr_fd(gm->moves, 1);
		ft_putstr_fd("   movimientos\n", 1);
		check_finish(move, gm);
		mlx_put_image_to_window(gm->mlx, gm->win, gm->p_lf, gm->px * IMG_PXL,
			gm->py * IMG_PXL);
	}
}

void	move_right(t_game *gm, int move)
{
	if (gm->map[gm->py][gm->px + 1] == 'E' && gm->collect != 0)
		return ;
	if (gm->map[gm->py][gm->px + 1] != '1')
	{
		if (gm->map[gm->py][gm->px + 1] == 'C')
		{
			gm->collect--;
			gm->map[gm->py][gm->px + 1] = '0';
		}
		mlx_put_image_to_window(gm->mlx, gm->win, gm->back, gm->px * IMG_PXL,
			gm->py * IMG_PXL);
		gm->moves++;
		ft_putstr_fd("Llevas   ", 1);
		ft_putnbr_fd(gm->moves, 1);
		ft_putstr_fd("   movimientos\n", 1);
		check_finish(move, gm);
		mlx_put_image_to_window(gm->mlx, gm->win, gm->p_rg, gm->px * IMG_PXL,
			gm->py * IMG_PXL);
	}
}
