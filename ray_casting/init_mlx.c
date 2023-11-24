/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 21:12:21 by jihykim2          #+#    #+#             */
/*   Updated: 2023/11/24 22:07:01 by jihykim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	_check_mlx_image(t_game *game);

void	init_mlx(t_game *game)
{
	game->mlx_ptr = mlx_init();
	game->win_ptr = mlx_new_window(game->mlx_ptr, \
		SCR_WIDTH, SCR_HEIGHT, "cub3D");
	game->screen.img = mlx_new_image(game->mlx_ptr, SCR_WIDTH, SCR_HEIGHT);
	game->screen.addr = mlx_get_data_addr(game->screen.img, \
		&game->screen.bpp, &game->screen.size_line, &game->screen.endian);
	game->north.img = mlx_xpm_file_to_image(game->mlx_ptr, \
		game->img_info.north, &game->north.width, &game->north.height);
	game->south.img = mlx_xpm_file_to_image(game->mlx_ptr, \
		game->img_info.south, &game->south.width, &game->south.height);
	game->west.img = mlx_xpm_file_to_image(game->mlx_ptr, \
		game->img_info.west, &game->west.width, &game->west.height);
	game->east.img = mlx_xpm_file_to_image(game->mlx_ptr, \
		game->img_info.east, &game->east.width, &game->east.height);
	_check_mlx_image(game);
	game->north.addr = mlx_get_data_addr(game->north.img, &game->north.bpp, \
		&game->north.size_line, &game->north.endian);
	game->south.addr = mlx_get_data_addr(game->south.img, &game->south.bpp, \
		&game->south.size_line, &game->south.endian);
	game->west.addr = mlx_get_data_addr(game->west.img, &game->west.bpp, \
		&game->west.size_line, &game->west.endian);
	game->east.addr = mlx_get_data_addr(game->east.img, &game->east.bpp, \
		&game->east.size_line, &game->east.endian);
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, \
		game->north.img, 0, 0);
}

static void	_check_mlx_image(t_game *game)
{
	if (game->screen.img == NULL || \
		game->north.img == NULL || \
		game->south.img == NULL || \
		game->west.img == NULL || \
		game->east.img == NULL)
		error_exit("Invalid xpm image");
}
