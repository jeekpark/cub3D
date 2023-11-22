/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_length_of_wall.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 21:42:02 by jihykim2          #+#    #+#             */
/*   Updated: 2023/11/22 16:04:52 by jihykim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	calculate_length_of_wall(t_game *game)
{	// 실제 그려야 할 스크린 상의 벽의 길이와, 해당 벽이 어느 방향인지 구하기
	t_raycast	*ray;

	ray = &game->ray_info;
	ray->wall_length_in_screen = (int)(SCR_HEIGHT / ray->perp_wall_dist);
	ray->draw_start = -ray->wall_length_in_screen / 2 + SCR_HEIGHT / 2;
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	ray->draw_end = ray->wall_length_in_screen / 2 + SCR_HEIGHT / 2;
	if (ray->draw_end >= SCR_HEIGHT)
		ray->draw_end = SCR_HEIGHT - 1;

	if (ray->side == W_OR_E && ray->ray_dir.x > 0)		// EAST
		ray->wall_data = &game->east;
	else if (ray->side == W_OR_E && ray->ray_dir.x < 0)	// WEST
		ray->wall_data = &game->west;
	else if (ray->side == N_OR_S && ray->ray_dir.y > 0)	// NORTH
		ray->wall_data = &game->north;
	else if (ray->side == N_OR_S && ray->ray_dir.y < 0)	// SOUTH
		ray->wall_data = &game->south;
}
