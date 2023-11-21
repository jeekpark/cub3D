/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_texture_info.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunlee <jiyunlee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 02:39:44 by jiyunlee          #+#    #+#             */
/*   Updated: 2023/11/21 20:28:28 by jiyunlee         ###   ########.fr       */
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
	// printf("%s\n", info[0]);

	// 개행만 있었을 경우
	if (!info[0])
		return ;
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
	// if (!ft_strcmp(info[0], "NO"))
	// {
		
	// 	img_info->north = (char *)malloc(sizeof(char) * ft_strlen(info[1]));
	// 	ft_strlcpy(img_info->north, info[1], ft_strlen(info[1]));
	// }
	// else if (!ft_strcmp(info[0], "SO"))
	// {
	// 	img_info->south = (char *)malloc(sizeof(char) * ft_strlen(info[1]));
	// 	ft_strlcpy(img_info->south, info[1], ft_strlen(info[1]));
	// }
	// else if (!ft_strcmp(info[0], "WE"))
	// {
	// 	img_info->west = (char *)malloc(sizeof(char) * ft_strlen(info[1]));
	// 	ft_strlcpy(img_info->west, info[1], ft_strlen(info[1]));
	// }
	// else if (!ft_strcmp(info[0], "EA"))
	// {
	// 	img_info->east = (char *)malloc(sizeof(char) * ft_strlen(info[1]));
	// 	ft_strlcpy(img_info->east, info[1], ft_strlen(info[1]));
	// }
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
	// printf("%s", line);
	if (line[len - 1] != '\n')
		return (line);
	str = (char *)malloc(sizeof(char) * len);
	// malloc fail
	ft_strlcpy(str, line, len);
	free(line);
	return (str);
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
		// printf("line: %s", line);
		if (!line)
			break ;
		line = delete_newline(line);	// line = "\n"이었다면 line = "\0"이 됨
		// printf("%s\n", line);
		split_line = ft_split(line, ' ');
		free(line);
		init_texture(&game->img_info, split_line, &element);
		free_arr(split_line);
		(*map_start_line)++;
		if (element == 6)
			break ;
	}
	if (close(fd) < 0)
		exit(EXIT_FAILURE);
}
