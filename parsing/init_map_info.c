/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map_info.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunlee <jiyunlee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 02:56:15 by jiyunlee          #+#    #+#             */
/*   Updated: 2023/11/22 01:14:53 by jiyunlee         ###   ########.fr       */
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
		line = delete_newline(line);
		line_len = ft_strlen(line);
		if (line_len > game->map_width)
			game->map_width = line_len;
		game->map_height++;
		free(line);
	}
	if (close(fd) < 0)
		exit(EXIT_FAILURE);
}

void	map_to_int(int width, char *line, int *int_line)
{
	int	i;

	i = 0;
	while (i < width)
		int_line[i++] = EMPTY;
	i = 0;
	while (line[i])
	{
		if (line[i] == '0')
			int_line[i] = SPACE;
		else if (line[i] == '1')
			int_line[i] = WALL;
		else if (line[i] == 'N')
			int_line[i] = NORTH;
		else if (line[i] == 'S')
			int_line[i] = SOUTH;
		else if (line[i] == 'W')
			int_line[i] = WEST;
		else if (line[i] == 'E')
			int_line[i] = EAST;
		else if (line[i] != ' ')
			error_exit("Invalid map");
		i++;
	}
}

void	reverse_y_value(t_game *game)
{
	int	i;
	int	*tmp;

	i = 0;
	while (i < game->map_height / 2)
	{
		tmp = game->map[i];
		game->map[i] = game->map[game->map_height - 1 - i];
		game->map[game->map_height - 1 - i] = tmp;
		i++;
	}
}

void	init_map(char *filename, t_game *game, int map_start_line)
{
	int		fd;
	char	*line;
	int		i;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		error_exit("Invalid file");
	while (map_start_line--)
		free(get_next_line(fd));
	game->map = ft_calloc(game->map_height, sizeof(int *));
	i = 0;
	while (i < game->map_height)
	{
		line = get_next_line(fd);
		line = delete_newline(line);
		game->map[i] = ft_calloc(game->map_width, sizeof(int));
		if (!game->map[i])
			exit(EXIT_FAILURE);
		map_to_int(game->map_width, line, game->map[i]);
		free(line);
		i++;
	}
	if (close(fd) < 0)
		exit(EXIT_FAILURE);
	reverse_y_value(game);
}
