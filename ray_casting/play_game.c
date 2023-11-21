/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 01:08:58 by jihykim2          #+#    #+#             */
/*   Updated: 2023/11/21 16:31:43 by jihykim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	play_game(t_game *game)
{
	init_mlx(game);
	mlx_loop_hook(game->mlx_ptr, &raycast_to_screen_3d_image, game);
	mlx_hook(game->win_ptr, KEY_ACT, 0, &key_press, game);
	mlx_loop(game->mlx_ptr);
}

int	raycast_to_screen_3d_image(t_game *game)
{
	int	screen_x;	// 0 < x < screen_width

	drawing_background(game);
	screen_x = 0;
	while (screen_x < SCR_WIDTH)
	{
		calculate_vector_in_image(game, screen_x);
		find_wall_from_player(game);
	}
}
