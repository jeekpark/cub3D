/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player_info.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunlee <jiyunlee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 03:29:39 by jiyunlee          #+#    #+#             */
/*   Updated: 2023/11/23 01:29:42 by jiyunlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	init_player_north(t_game *game, int x, int y);
void	init_player_south(t_game *game, int x, int y);
void	init_player_west(t_game *game, int x, int y);
void	init_player_east(t_game *game, int x, int y);

void	init_player_info(t_game *game)
{
	int	player;
	int	x;
	int	y;

	player = 0;
	y = -1;
	while (++y < game->map_height)
	{
		x = -1;
		while (++x < game->map_width)
		{
			if (NORTH <= game->map[y][x] && game->map[y][x] <= EAST)
				player++;
			if (game->map[y][x] == NORTH)
				init_player_north(game, x, y);
			else if (game->map[y][x] == SOUTH)
				init_player_south(game, x, y);
			else if (game->map[y][x] == WEST)
				init_player_west(game, x, y);
			else if (game->map[y][x] == EAST)
				init_player_east(game, x, y);
		}
	}
	if (player != 1)
		error_exit("Invalid map");
}

void	init_player_north(t_game *game, int x, int y)
{
	game->player = (t_vec_f){x + 0.5, y + 0.5};
	game->view_dir.x = 0;
	game->view_dir.y = 1;
	game->plane_dir.x = 0.66;
	game->plane_dir.y = 0;
	game->map[y][x] = SPACE;
}

void	init_player_south(t_game *game, int x, int y)
{
	game->player = (t_vec_f){x + 0.5, y + 0.5};
	game->view_dir.x = 0;
	game->view_dir.y = -1;
	game->plane_dir.x = -0.66;
	game->plane_dir.y = 0;
	game->map[y][x] = SPACE;
}

void	init_player_west(t_game *game, int x, int y)
{
	game->player = (t_vec_f){x + 0.5, y + 0.5};
	game->view_dir.x = -1;
	game->view_dir.y = 0;
	game->plane_dir.x = 0;
	game->plane_dir.y = 0.66;
	game->map[y][x] = SPACE;
}

void	init_player_east(t_game *game, int x, int y)
{
	game->player = (t_vec_f){x + 0.5, y + 0.5};
	game->view_dir.x = 1;
	game->view_dir.y = 0;
	game->plane_dir.x = 0;
	game->plane_dir.y = -0.66;
	game->map[y][x] = SPACE;
}
