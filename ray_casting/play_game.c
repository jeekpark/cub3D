/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 01:08:58 by jihykim2          #+#    #+#             */
/*   Updated: 2023/11/20 21:36:18 by jihykim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	play_game(t_game *game)
{
	game->mlx_ptr = mlx_init();
	game->win_ptr = mlx_new_window(game->mlx_ptr, SCR_WIDTH, SCR_HEIGHT, \
					"jiji-cub3D");
	init_drawing_image(game);
	mlx_loop_hook(game->mlx_ptr, &draw_into_screen, game);
	mlx_hook(game->win_ptr, KEY_ACT, 0, &key_press, game);
	mlx_loop(game->mlx_ptr);
}

int	draw_into_screen(t_game *game)
{
	t_data	screen;
}
