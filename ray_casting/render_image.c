/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 21:04:22 by jihykim2          #+#    #+#             */
/*   Updated: 2023/11/24 21:14:33 by jihykim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	_init_player_by_keycode(t_game *game);

int	render_image(t_game *game)
{
	int	screen_x;

	ft_memset(&game->ray_info, 0, sizeof(t_raycast));
	_init_player_by_keycode(game);
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
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, \
		game->screen.img, 0, 0);
	return (EXIT_SUCCESS);
}

static void	_init_player_by_keycode(t_game *game)
{
	if (game->key.rotate_l == TRUE || game->key.rotate_r)
		rotate_player(game);
	if (game->key.move_n == TRUE || game->key.move_s || \
		game->key.move_w == TRUE || game->key.move_e == TRUE)
		move_player(game);
}
