/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 02:46:50 by jihykim2          #+#    #+#             */
/*   Updated: 2023/11/24 20:51:00 by jihykim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static t_vec_f	_get_new_vector(t_game *game);

void	move_player(t_game *game)
{
	t_vec_f	new_vector;
	double	gap;

	new_vector = _get_new_vector(game);
	gap = 0.001;
	if (game->map[(int)(new_vector.y + gap)][(int)game->player.x] == SPACE && \
		game->map[(int)game->player.y][(int)(new_vector.x + gap)] == SPACE && \
		game->map[(int)(new_vector.y - gap)][(int)game->player.x] == SPACE && \
		game->map[(int)game->player.y][(int)(new_vector.x - gap)] == SPACE)
	{
		game->player.x = new_vector.x;
		game->player.y = new_vector.y;
	}
}

static t_vec_f	_get_new_vector(t_game *game)
{
	t_vec_f	new_vector;

	if (game->key.move_n == TRUE)
	{
		new_vector.x = game->player.x + game->view_dir.x * MOVE_SPEED;
		new_vector.y = game->player.y + game->view_dir.y * MOVE_SPEED;
	}
	else if (game->key.move_s == TRUE)
	{
		new_vector.x = game->player.x - game->view_dir.x * MOVE_SPEED;
		new_vector.y = game->player.y - game->view_dir.y * MOVE_SPEED;
	}
	else if (game->key.move_e == TRUE)
	{
		new_vector.x = game->player.x + game->view_dir.y * MOVE_SPEED;
		new_vector.y = game->player.y - game->view_dir.x * MOVE_SPEED;
	}
	else if (game->key.move_w == TRUE)
	{
		new_vector.x = game->player.x - game->view_dir.y * MOVE_SPEED;
		new_vector.y = game->player.y + game->view_dir.x * MOVE_SPEED;
	}
	else
		return (game->player);
	return (new_vector);
}
