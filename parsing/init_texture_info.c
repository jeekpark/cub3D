/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_texture_info.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunlee <jiyunlee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 02:39:44 by jiyunlee          #+#    #+#             */
/*   Updated: 2023/11/21 03:19:27 by jiyunlee         ###   ########.fr       */
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
	free_arr(rgb_arr);
	return (num);
}

void	init_texture(t_texture *img_info, char **info, int *element)
{
	if (!ft_strcmp(info[0], "NO"))
	{
		img_info->north = (char *)malloc(sizeof(char) * ft_strlen(info[1]));
		ft_strlcpy(img_info->north, info[1], ft_strlen(info[1]));
	}
	else if (!ft_strcmp(info[0], "SO"))
	{
		img_info->south = (char *)malloc(sizeof(char) * ft_strlen(info[1]));
		ft_strlcpy(img_info->south, info[1], ft_strlen(info[1]));
	}
	else if (!ft_strcmp(info[0], "WE"))
	{
		img_info->west = (char *)malloc(sizeof(char) * ft_strlen(info[1]));
		ft_strlcpy(img_info->west, info[1], ft_strlen(info[1]));
	}
	else if (!ft_strcmp(info[0], "EA"))
	{
		img_info->east = (char *)malloc(sizeof(char) * ft_strlen(info[1]));
		ft_strlcpy(img_info->east, info[1], ft_strlen(info[1]));
	}
	else if (!ft_strcmp(info[0], "F"))
		img_info->floor = rgb_to_int(info[1]);
	else if (!ft_strcmp(info[0], "C"))
		img_info->ceiling = rgb_to_int(info[1]);
	else
		return ;
	(*element)++;
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
	*map_start_line = 0;
	element = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		split_line = ft_split(line, ' ');
		if (!split_line)
			exit(EXIT_FAILURE);
		init_texture(&game->img_info, split_line, &element);

		// free split_line => 안하면 leak
		free_arr(split_line);
		free(line);
		(*map_start_line)++;
		if (element == 6)
			break ;
	}
	if (close(fd) < 0)
		exit(EXIT_FAILURE);
}
