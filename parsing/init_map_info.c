/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map_info.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunlee <jiyunlee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 02:56:15 by jiyunlee          #+#    #+#             */
/*   Updated: 2023/11/21 03:26:02 by jiyunlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	init_map_info(char *filename, t_game *game, int map_start_line)
{
	int		fd;
	char	*line;
	int		line_len;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		error_exit("Invalid file");
	while (map_start_line--)
		free(get_next_line(fd));
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		line_len = ft_strlen(line);
		if (line_len > game->map_width)
		{
			if (line[line_len - 1] == '\n')
				line_len--;
			game->map_width = line_len;		// 끝에 newline이 들어옴
		}
		game->map_height++;
		free(line);
	}
	if (close(fd) < 0)
		exit(EXIT_FAILURE);
}

void	map_to_int(char *line, int *int_line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == ' ')
			int_line[i] = 8;
		else if (line[i] == '1')
			int_line[i] = 1;
		else if (line[i] == 'N')
			int_line[i] = NORTH;
		else if (line[i] == 'S')
			int_line[i] = SOUTH;
		else if (line[i] == 'W')
			int_line[i] = WEST;
		else if (line[i] == 'E')
			int_line[i] = EAST;
		// else if (line[i] != '0')
		// 	error
		i++;
	}
}

void	init_map(char *filename, t_game *game, int map_start_line)
{
	int		fd;
	char	*line;
	int		*tmp;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		error_exit("Invalid file");
	while (map_start_line--)
	{
		line = get_next_line(fd);
		free(line);
	}
	game->map = ft_calloc(game->map_height, sizeof(int *));
	int i = 0;
	while (i < game->map_height)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		game->map[i] = ft_calloc(game->map_width, sizeof(int));
		if (!game->map[i])
			exit(EXIT_FAILURE);
		map_to_int(line, game->map[i]);
		
		free(line);
		i++;
	}
	if (close(fd) < 0)
		exit(EXIT_FAILURE);

	i = 0;
	while (i < game->map_height / 2)
	{
		tmp = game->map[i];
		game->map[i] = game->map[game->map_height - 1 - i];
		game->map[game->map_height - 1 - i] = tmp;
		i++;
	}
}
