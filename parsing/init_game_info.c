/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game_info.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunlee <jiyunlee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 09:26:56 by jiyunlee          #+#    #+#             */
/*   Updated: 2023/11/20 20:29:33 by jiyunlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	init_game_info(char *filename, t_game *game)
{
	int		fd;
	char	*line;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		error_exit("Invalid file");
	while (1)
	{
		line = get_next_line(fd);
		printf("서손 짱!\n");
		if (!line)
			break ;
		

		free(line);
	}
}
