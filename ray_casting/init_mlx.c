/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 21:12:21 by jihykim2          #+#    #+#             */
/*   Updated: 2023/11/21 14:13:57 by jihykim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	init_mlx(t_game *game)
{
	// get screen image in mlx-screen
	game->mlx_ptr = mlx_init();
	game->win_ptr = mlx_new_window(game->mlx_ptr, SCR_WIDTH, SCR_HEIGHT, "cub3D");

	// get image-pointer in mlx-screen
	game->north.img = mlx_xpm_file_to_image(game->mlx_ptr, \
		game->img_info.north, &game->north.width, &game->north.height);
	game->south.img = mlx_xpm_file_to_image(game->mlx_ptr, \
		game->img_info.south, &game->south.width, &game->south.height);
	game->west.img = mlx_xpm_file_to_image(game->mlx_ptr, \
		game->img_info.west, &game->west.width, &game->west.height);
	game->east.img = mlx_xpm_file_to_image(game->mlx_ptr, \
		game->img_info.east, &game->east.width, &game->east.height);

	// get pixel-address in image
	game->north.addr = mlx_get_data_addr(game->north.img, game->north.bpp, \
		game->north.line_length, game->north.endian);
	game->south.addr = mlx_get_data_addr(game->south.img, game->south.bpp, \
		game->south.line_length, game->south.endian);
	game->west.addr = mlx_get_data_addr(game->west.img, game->west.bpp, \
		game->west.line_length, game->west.endian);
	game->east.addr = mlx_get_data_addr(game->east.img, game->east.bpp, \
		game->east.line_length, game->east.endian);
}

// void	get_image_data(t_data *image, void *mlx_ptr)
// {
		// for getting image-pointer, pixel-address
// }
