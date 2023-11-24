/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 03:15:56 by jihykim2          #+#    #+#             */
/*   Updated: 2023/11/24 21:24:37 by jihykim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	rotate_vector(t_vec_f *vector, double degree);

void	rotate_player(t_game *game)
{
	if (game->key.rotate_l == TRUE && game->key.rotate_r == FALSE)
	{
		rotate_vector(&game->view_dir, ROTATE_SPEED);
		rotate_vector(&game->plane_dir, ROTATE_SPEED);
	}
	else if (game->key.rotate_r == TRUE && game->key.rotate_l == FALSE)
	{
		rotate_vector(&game->view_dir, -ROTATE_SPEED);
		rotate_vector(&game->plane_dir, -ROTATE_SPEED);
	}
}

static void	rotate_vector(t_vec_f *vector, double degree)
{
	t_vec_f	old_vector;
	double	rad;

	old_vector.x = vector->x;
	old_vector.y = vector->y;
	rad = M_PI / 180.0 * degree;
	vector->x = old_vector.x * cos(rad) - old_vector.y * sin(rad);
	vector->y = old_vector.x * sin(rad) + old_vector.y * cos(rad);
}
