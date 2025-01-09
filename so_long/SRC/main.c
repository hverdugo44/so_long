/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hverdugo <hverdugo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 14:06:48 by hverdugo          #+#    #+#             */
/*   Updated: 2025/01/09 15:40:25 by hverdugo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INC/so_long.h"

void	screen(t_game *game)
{
	game->mlx = mlx_win;
	game->img = 

int	main(int argc, char **argv)
{
	t_game	*game;

	if (argc != 2)
		return (0);
	game = evaluador(argv[1]);

	free_mat(game->map);
	free(game);
	return (0);
}
