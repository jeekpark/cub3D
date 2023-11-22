/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_texture_info.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunlee <jiyunlee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 02:39:44 by jiyunlee          #+#    #+#             */
/*   Updated: 2023/11/22 16:42:30 by jiyunlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	only_digit(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (FALSE);
		i++;
	}
	return (TRUE);
}

int	rgb_to_int(char *rgb_str)
{
	int		i;
	int		comma;
	char	**rgb_arr;
	int		rgb_int;
	int		rgb[3];

	comma = 0;
	i = 0;
	while (rgb_str[i])
		if (rgb_str[i++] == ',')
			comma++;
	rgb_arr = ft_split(rgb_str, ',');
	if (comma != 2 || !rgb_arr[0] || !rgb_arr[1] || !rgb_arr[2] || rgb_arr[3])
		error_exit("Invalid cub file");
	if (!only_digit(rgb_arr[0]) || !only_digit(rgb_arr[1]) || !only_digit(rgb_arr[1]))
		error_exit("Invalid cub file");
	rgb[0] = ft_atoi(rgb_arr[0]);
	rgb[1] = ft_atoi(rgb_arr[1]);
	rgb[2] = ft_atoi(rgb_arr[2]);
	if (rgb[0] > 255 || rgb[1] > 255 || rgb[2] > 255)
		error_exit("Invalid cub file");
	rgb_int = rgb[0] * 256 * 256 + rgb[1] * 256 + rgb[2];
	free_arr(rgb_arr);
	return (rgb_int);
}

void	init_texture(t_texture *img_info, char **info, t_texture_flag *flag)
{
	if (!info[0] || !info[1] || info[2])
		error_exit("Invalid cub file");
	if (!ft_strcmp(info[0], "NO") && !flag->north++ && ++flag->count)
		img_info->north = ft_strdup(info[1]);
	else if (!ft_strcmp(info[0], "SO") && !flag->south++ && ++flag->count)
		img_info->south = ft_strdup(info[1]);
	else if (!ft_strcmp(info[0], "WE") && !flag->west++ && ++flag->count)
		img_info->west = ft_strdup(info[1]);
	else if (!ft_strcmp(info[0], "EA") && !flag->east++ && ++flag->count)
		img_info->east = ft_strdup(info[1]);
	else if (!ft_strcmp(info[0], "F") && !flag->floor++ && ++flag->count)
		img_info->floor = rgb_to_int(info[1]);
	else if (!ft_strcmp(info[0], "C") && !flag->ceiling++ && ++flag->count)
		img_info->ceiling = rgb_to_int(info[1]);
	else
		error_exit("Invalid cub file");
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
	t_texture_flag *texture_flag;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		error_exit("Invalid file");
	texture_flag = ft_calloc(1, sizeof(t_texture_flag));
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
		init_texture(&game->img_info, split_line, texture_flag);
		free_arr(split_line);
		if (texture_flag->count == 6)
			break ;
	}
	if (texture_flag->count != 6)
		error_exit("Invalid cub file");
	free(texture_flag);
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
