/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunlee <jiyunlee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 00:46:55 by jiyunlee          #+#    #+#             */
/*   Updated: 2023/11/22 01:10:10 by jiyunlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	check_surrounded(t_game *game, int x, int y)
{
	if (x == 0 || x == game->map_width - 1)
		error_exit("Invalid map path");
	if (y == 0 || y == game->map_height - 1)
		error_exit("Invalid map path");
	if (game->map[y][x - 1] == EMPTY)
		error_exit("Invalid map path");
	if (game->map[y][x + 1] == EMPTY)
		error_exit("Invalid map path");
	if (game->map[y - 1][x] == EMPTY)
		error_exit("Invalid map path");
	if (game->map[y + 1][x] == EMPTY)
		error_exit("Invalid map path");
}

void	check_valid_map(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map_height)
	{
		x = 0;
		while (x < game->map_width)
		{
			if (game->map[y][x] == SPACE)
				check_surrounded(game, x, y);
			else if (NORTH <= game->map[y][x] && game->map[y][x] <= EAST)
				check_surrounded(game, x, y);
			x++;
		}
		y++;
	}
}
