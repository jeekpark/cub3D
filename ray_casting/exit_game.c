/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 12:28:23 by jihykim2          #+#    #+#             */
/*   Updated: 2023/11/24 21:29:27 by jihykim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	exit_game(t_game *game)
{
	mlx_destroy_image(game->mlx_ptr, game->north.img);
	mlx_destroy_image(game->mlx_ptr, game->south.img);
	mlx_destroy_image(game->mlx_ptr, game->east.img);
	mlx_destroy_image(game->mlx_ptr, game->west.img);
	mlx_destroy_image(game->mlx_ptr, game->screen.img);
	mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	free_data(game);
	exit (EXIT_SUCCESS);
}
