/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 01:08:58 by jihykim2          #+#    #+#             */
/*   Updated: 2023/11/23 10:18:34 by jihykim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	play_game(t_game *game)
{
	printf("haha1\n");
	init_mlx(game);
	printf("haha2\n");
	// mlx_hook(game->win_ptr, KEY_ACT)
	mlx_loop_hook(game->mlx_ptr, &raycast_to_screen_3d_image, game);
	mlx_loop(game->mlx_ptr);
}

int	raycast_to_screen_3d_image(t_game *game)
{
	int	screen_x;	// 0 < x < screen_width

	ft_memset(&game->ray_info, 0, sizeof(t_raycast));		// 굳이...?
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
