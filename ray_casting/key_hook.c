/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 02:45:56 by jihykim2          #+#    #+#             */
/*   Updated: 2023/11/23 19:37:59 by jihykim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	key_press(int keycode, t_game *game)
{
	if (keycode == KEY_LEFT)
		game->key.rotate_l = TRUE;
	else if (keycode == KEY_RIGHT)
		game->key.rotate_r = TRUE;
	else if (keycode == KEY_W)
		game->key.move_n = TRUE;
	else if (keycode == KEY_S)
		game->key.move_s = TRUE;
	else if (keycode == KEY_D)
		game->key.move_e = TRUE;
	else if (keycode == KEY_A)
		game->key.move_w = TRUE;
	else if (keycode == KEY_ESC)
		exit_game(game);
	return (EXIT_SUCCESS);
}

int	key_release(int keycode, t_game *game)
{
	if (keycode == KEY_LEFT)
		game->key.rotate_l = FALSE;
	else if (keycode == KEY_RIGHT)
		game->key.rotate_r = FALSE;
	else if (keycode == KEY_W)
		game->key.move_n = FALSE;
	else if (keycode == KEY_S)
		game->key.move_s = FALSE;
	else if (keycode == KEY_D)
		game->key.move_e = FALSE;
	else if (keycode == KEY_A)
		game->key.move_w = FALSE;
	return (EXIT_SUCCESS);
}
