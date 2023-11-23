/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_background.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 22:30:04 by jihykim2          #+#    #+#             */
/*   Updated: 2023/11/23 23:53:54 by jihykim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	draw_background(t_game *game)
{
	int	screen_x;
	int	screen_y;

	screen_x = 0;
	while (screen_x < SCR_WIDTH)
	{
		screen_y = 0;
		while (screen_y < SCR_HEIGHT / 2)
			my_mlx_pixel_put(&game->screen, screen_x, screen_y++, \
				game->img_info.ceiling);
		while (screen_y < SCR_HEIGHT)
			my_mlx_pixel_put(&game->screen, screen_x, screen_y++, \
				game->img_info.floor);
		screen_x++;
	}
}
