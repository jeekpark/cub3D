/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game_info.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunlee <jiyunlee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 09:26:56 by jiyunlee          #+#    #+#             */
/*   Updated: 2023/11/21 01:54:13 by jiyunlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	rgb_to_int(char *rgb)
{
	char	**rgb_arr;
	int		num;

	rgb_arr = ft_split(rgb, ',');
	if (!rgb_arr)
		exit(EXIT_FAILURE);
	num = 0;
	num += ft_atoi(rgb_arr[0]) * 256 * 256;
	num += ft_atoi(rgb_arr[1]) * 256;
	num += ft_atoi(rgb_arr[2]);
	// free rgb_arr => 안하면 leak
	return (num);
}

void	init_texture(t_texture *img_info, char **info, int *element)
{
	if (!ft_strcmp(info[0], "NO"))
		img_info->north = ft_strdup(info[1]);
	else if (!ft_strcmp(info[0], "SO"))
		img_info->south = ft_strdup(info[1]);
	else if (!ft_strcmp(info[0], "WE"))
		img_info->west = ft_strdup(info[1]);
	else if (!ft_strcmp(info[0], "EA"))
		img_info->east = ft_strdup(info[1]);
	else if (!ft_strcmp(info[0], "F"))
		img_info->floor = rgb_to_int(info[1]);
	else if (!ft_strcmp(info[0], "C"))
		img_info->ceiling = rgb_to_int(info[1]);
	else
		return ;
	(*element)++;
}

void	init_map_info(char *filename, t_game *game, int map_start_line)
{
	int		fd;
	char	*line;
	int		line_len;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		error_exit("Invalid file");
	while (map_start_line--)
	{
		line = get_next_line(fd);
		free(line);
	}
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
			int_line[i] = -1;
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
	int		fd;
	char	*line;
	char	**split_line;
	int		element;
	int		map_start_line = 0;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		error_exit("Invalid file");
	element = 0;
	while (1)
	{
		line = get_next_line(fd);
		// printf("서손 짱!\n")
		if (!line || element == 6)
			break ;
		split_line = ft_split(line, ' ');
		if (!split_line)
			exit(EXIT_FAILURE);
		init_texture(&game->img_info, split_line, &element);

		// free split_line => 안하면 leak
		free(line);
		map_start_line++;
	}
	if (close(fd) < 0)
		exit(EXIT_FAILURE);
	init_map_info(filename, game, map_start_line);
	init_map(filename, game, map_start_line);
	init_player_info(game);
}
