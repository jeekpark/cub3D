/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 01:08:58 by jihykim2          #+#    #+#             */
/*   Updated: 2023/11/23 19:43:08 by jihykim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	play_game(t_game *game)
{
	init_mlx(game);
	mlx_hook(game->win_ptr, KEY_ACT, 0, &key_press, game);
	mlx_hook(game->win_ptr, KEY_DEACT, 0, &key_release, game);
	mlx_hook(game->win_ptr, KEY_EXIT, 0, &exit_game, game);
	mlx_loop_hook(game->mlx_ptr, &raycast_to_screen_3d_image, game);
	mlx_loop(game->mlx_ptr);
}

int	raycast_to_screen_3d_image(t_game *game)
{
	int	screen_x;	// 0 < x < screen_width

	ft_memset(&game->ray_info, 0, sizeof(t_raycast));		// 굳이...?
	init_vector_by_keycode(game);
	draw_background(game);
	screen_x = 0;
	while (screen_x < SCR_WIDTH)
	{
		calculate_vector_in_image(game, screen_x);
		find_wall_from_player(game);
		calculate_length_of_ray(game);
		calculate_length_of_wall(game);
		draw_wall(game, screen_x);
		screen_x++;
	}
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->screen.img, 0, 0);
	return (EXIT_SUCCESS);
}

void	init_vector_by_keycode(t_game *game)
{
	if (game->key.rotate_l == TRUE || game->key.rotate_r)
		rotate_player(game);
	if (game->key.move_n == TRUE || game->key.move_s || \
		game->key.move_w == TRUE || game->key.move_e == TRUE)
		move_player(game);
}
