/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 01:08:58 by jihykim2          #+#    #+#             */
/*   Updated: 2023/11/24 21:05:17 by jihykim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	play_game(t_game *game)
{
	init_mlx(game);
	mlx_hook(game->win_ptr, KEY_ACT, 0, &key_press, game);
	mlx_hook(game->win_ptr, KEY_DEACT, 0, &key_release, game);
	mlx_hook(game->win_ptr, KEY_EXIT, 0, &exit_game, game);
	mlx_loop_hook(game->mlx_ptr, &render_image, game);
	mlx_loop(game->mlx_ptr);
}
