/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hverdugo <hverdugo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 14:06:48 by hverdugo          #+#    #+#             */
/*   Updated: 2025/01/11 16:21:31 by hverdugo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INC/so_long.h"

static void	screen(t_game *gm)
{
	gm->mlx = mlx_init();
	gm->win = mlx_new_window(gm->mlx, gm->x * 32, gm->y * 32, "So_long");
}

int	main(int argc, char **argv)
{
	t_game	*game;

	if (argc != 2)
		return (0);
	game = evaluador(argv[1]);
	screen(game);
	while (1)
	{
		images(game);
		images_to_win(game);
		mlx_loop(game->mlx);
	}
	return (0);
}
