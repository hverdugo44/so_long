/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hverdugo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 11:14:56 by hverdugo          #+#    #+#             */
/*   Updated: 2025/01/22 14:32:33 by hverdugo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INC/so_long.h"

static void	screen(t_game *gm)
{
	gm->mlx = mlx_init();
	if (!gm->mlx)
	{
		perror("Error\nLibrary error, Memory asingment");
		free_mat(gm->map);
		free(gm);
		exit (1);
	}
	gm->p_up = NULL;
	gm->p_dn = NULL;
	gm->p_lf = NULL;
	gm->p_rg = NULL;
	gm->back = NULL;
	gm->clct = NULL;
	gm->esc = NULL;
	gm->wall = NULL;
	gm->winner = NULL;
	gm->moves = 0;
}

int	main(int argc, char **argv)
{
	t_game	*game;

	if (argc != 2)
		return (0);
	game = evaluador(argv[1]);
	check_chars(game);
	screen(game);
	images(game);
	game->win = mlx_new_window(game->mlx, game->x * IMG_PXL, game->y * IMG_PXL,
			"So Long");
	images_to_win(game);
	mlx_hook(game->win, 17, 0, close_x, game);
	mlx_key_hook(game->win, pressed_key, game);
	mlx_loop(game->mlx);
	return (0);
}
