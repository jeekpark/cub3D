/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_content_info.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunlee <jiyunlee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 00:39:56 by jiyunlee          #+#    #+#             */
/*   Updated: 2023/11/23 21:38:58 by jiyunlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	check_valid_texture_file(t_texture *img_info);
void	init_content_info_2(t_texture_flag *flag, t_texture *img_info,
			int fd, int *map_start_line);

void	init_content_info(char *filename, t_game *game, int *map_start_line)
{
	int				fd;
	char			*line;
	char			**split_line;
	t_texture_flag	*texture_flag;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		error_exit("Invalid map file");
	texture_flag = ft_calloc(1, sizeof(t_texture_flag));
	while (texture_flag->count < 6)
	{
		line = gnl_no_newline(fd);
		if (!line)
			break ;
		(*map_start_line)++;
		if (!ft_strcmp(line, "\0"))
		{
			free(line);
			continue ;
		}
		split_line = ft_split(line, ' ');
		init_texture_info(&game->img_info, split_line, texture_flag);
		free_str_arr(line, split_line);
	}
	init_content_info_2(texture_flag, &game->img_info, fd, map_start_line);
}

void	init_content_info_2(t_texture_flag *flag, t_texture *img_info,
								int fd, int *map_start_line)
{
	char	*line;

	if (flag->count != 6)
		error_exit("Invalid information");
	free(flag);
	check_valid_texture_file(img_info);
	while (1)
	{
		line = gnl_no_newline(fd);
		if (!line)
			break ;
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

void	check_valid_texture_file(t_texture *img_info)
{
	int		fd;

	fd = open(img_info->north, O_RDONLY);
	if (fd < 0 || close(fd) < 0)
		error_exit("Invalid texture file");
	fd = open(img_info->south, O_RDONLY);
	if (fd < 0 || close(fd) < 0)
		error_exit("Invalid texture file");
	fd = open(img_info->west, O_RDONLY);
	if (fd < 0 || close(fd) < 0)
		error_exit("Invalid texture file");
	fd = open(img_info->east, O_RDONLY);
	if (fd < 0 || close(fd) < 0)
		error_exit("Invalid texture file");
}
