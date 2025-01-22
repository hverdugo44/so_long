/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hverdugo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 11:14:56 by hverdugo          #+#    #+#             */
/*   Updated: 2025/01/18 11:32:35 by hverdugo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INC/so_long.h"

static void	screen(t_game *gm)
{
	gm->mlx = mlx_init();
	if (!gm->mlx)
	{
		close_x(gm);
		perror("Error\nLibrary error, Memory asingment");
		exit(1);
	}
	gm->win = mlx_new_window(gm->mlx, gm->x * IMG_PXL,
			gm->y * IMG_PXL, "So_long");
	if (!gm->win)
	{
		close_x(gm);
		perror("Error\nLibrary error, Memory asingment");
		exit(1);
	}
	gm->moves = 0;
}

int	main(int argc, char **argv)
{
	t_game	*game;

	if (argc != 2)
		return (0);
	game = evaluador(argv[1]);
	screen(game);
	images(game);
	images_to_win(game);
	mlx_hook(game->win, 17, 0, close_x, game);
	mlx_key_hook(game->win, pressed_key, game);
	mlx_loop(game->mlx);
	return (0);
}
