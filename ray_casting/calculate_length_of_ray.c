/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_length_of_ray.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 21:39:19 by jihykim2          #+#    #+#             */
/*   Updated: 2023/11/23 11:42:59 by jihykim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	calculate_length_of_ray(t_game *game)
{
	t_raycast	*ray;

	ray = &game->ray_info;
	if (ray->side == W_OR_E)
	{
		ray->perp_wall_dist = ray->side_dist.x - ray->delta_dist.x;
		ray->hit_point = game->player.y + \
			ray->perp_wall_dist * ray->ray_dir.y;
	}
	else
	{
		ray->perp_wall_dist = ray->side_dist.y - ray->delta_dist.y;
		ray->hit_point = game->player.x + \
			ray->perp_wall_dist * ray->ray_dir.x;
	}
	ray->hit_point -= floor(ray->hit_point);
	// printf("%f\n", ray->hit_point);
}
