/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game_info.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunlee <jiyunlee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 09:26:56 by jiyunlee          #+#    #+#             */
/*   Updated: 2023/11/21 03:26:16 by jiyunlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	init_player_info(t_game *game)
{
	int		x;
	int		y;

	y = 0;
	while (y < game->map_height)
	{
		x = 0;
		while (x < game->map_width)
		{
			if (NORTH <= game->map[y][x] && game->map[y][x] <= EAST)
			{
				// game->player = {x + 0.5, y + 0.5};
				game->player.x = x + 0.5;
				game->player.y = y + 0.5;
			}
			if (game->map[y][x] == NORTH)
			{
				game->view_dir.x = 0;
				game->view_dir.y = 1;
				game->plane_dir.x = 0.66;
				game->plane_dir.y = 0;
			}
			else if (game->map[y][x] == SOUTH)
			{
				game->view_dir.x = 0;
				game->view_dir.y = -1;
				game->plane_dir.x = -0.66;
				game->plane_dir.y = 0;
			}
			else if (game->map[y][x] == WEST)
			{
				game->view_dir.x = -1;
				game->view_dir.y = 0;
				game->plane_dir.x = 0;
				game->plane_dir.y = 0.66;
			}
			else if (game->map[y][x] == EAST)
			{
				game->view_dir.x = 1;
				game->view_dir.y = 0;
				game->plane_dir.x = 0;
				game->plane_dir.y = -0.66;
			}
			x++;
		}
		y++;
	}
}

void	init_game_info(char *filename, t_game *game)
{
	int	map_start_line;

	init_texture_info(filename, game, &map_start_line);
	init_map_info(filename, game, map_start_line);
	init_map(filename, game, map_start_line);
	init_player_info(game);
}
