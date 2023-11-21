/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_texture_info.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunlee <jiyunlee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 02:39:44 by jiyunlee          #+#    #+#             */
/*   Updated: 2023/11/22 01:15:56 by jiyunlee         ###   ########.fr       */
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
	free_arr(rgb_arr);
	return (num);
}

void	init_texture(t_texture *img_info, char **info, int *element)
{
	if (!info[0] || !info[1] || info[2])
		error_exit("Invalid cub file");
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
	else if (!ft_strcmp(info[0], "F"))
		img_info->floor = rgb_to_int(info[1]);
	else if (!ft_strcmp(info[0], "C"))
		img_info->ceiling = rgb_to_int(info[1]);
	else
		error_exit("Invalid cub file");
	(*element)++;
}

char	*delete_newline(char *line)
{
	char	*str;
	size_t	len;

	len = ft_strlen(line);
	if (line[len - 1] != '\n')
		return (line);
	str = (char *)malloc(sizeof(char) * len);
	if (!str)
		exit(EXIT_FAILURE);
	ft_strlcpy(str, line, len);
	free(line);
	return (str);
}

char	*gnl_no_newline(int fd)
{
	char	*line;

	line = get_next_line(fd);
	if (!line)
		return (NULL);
	return (delete_newline(line));
}

void	init_texture_info(char *filename, t_game *game, int *map_start_line)
{
	int		fd;
	char	*line;
	char	**split_line;
	int		element;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		error_exit("Invalid file");
	element = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		(*map_start_line)++;
		line = delete_newline(line);
		if (!ft_strcmp(line, "\0"))
		{
			free(line);
			continue ;
		}
		split_line = ft_split(line, ' ');
		free(line);
		init_texture(&game->img_info, split_line, &element);
		free_arr(split_line);
		if (element == 6)
			break ;
	}
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		line = delete_newline(line);
		if (ft_strcmp(line, "\0"))
		{
			free(line);
			break ;
		}
		free(line);
		(*map_start_line)++;
	}
	if (close(fd) < 0)
		exit(EXIT_FAILURE);
}
