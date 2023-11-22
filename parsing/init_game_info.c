/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game_info.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunlee <jiyunlee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 09:26:56 by jiyunlee          #+#    #+#             */
/*   Updated: 2023/11/23 01:30:08 by jiyunlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	init_game_info(char *filename, t_game *game)
{
	int	map_start_line;

	map_start_line = 0;
	init_content_info(filename, game, &map_start_line);
	init_map_info(filename, game, map_start_line);
	init_map(filename, game, map_start_line);
	check_valid_map(game);
	init_player_info(game);
}
