/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 02:46:50 by jihykim2          #+#    #+#             */
/*   Updated: 2023/11/23 19:29:13 by jihykim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	move_player(t_game *game)
{
	t_vec_f	new_vector;

	if (game->key.move_n == TRUE && game->key.move_s == FALSE)	// front
	{
		new_vector.x = game->player.x + game->view_dir.x * MOVE_SPEED;
		new_vector.y = game->player.y + game->view_dir.y * MOVE_SPEED;
	}
	else if (game->key.move_s == TRUE && game->key.move_n == FALSE)	// back
	{
		new_vector.x = game->player.x - game->view_dir.x * MOVE_SPEED;
		new_vector.x = game->player.y - game->view_dir.y * MOVE_SPEED;
	}
	else if (game->key.move_e == TRUE && game->key.move_w == FALSE)	// right
	{
		new_vector.x = game->player.x + game->view_dir.y * MOVE_SPEED;
		new_vector.x = game->player.y - game->view_dir.x * MOVE_SPEED;
	}
	else if (game->key.move_w == TRUE && game->key.move_e == FALSE)	// left
	{
		new_vector.x = game->player.x - game->view_dir.y * MOVE_SPEED;
		new_vector.x = game->player.y + game->view_dir.x * MOVE_SPEED;
	}
	if (game->map[(int)new_vector.y][(int)new_vector.x] != SPACE)
	{
		game->player.x = new_vector.x;
		game->player.y = new_vector.y;
	}
}

// void	move_vector(t_vec_f *vector)
// {

// }
