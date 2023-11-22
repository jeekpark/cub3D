/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_content_info.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunlee <jiyunlee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 00:39:56 by jiyunlee          #+#    #+#             */
/*   Updated: 2023/11/23 01:38:19 by jiyunlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	init_content_info_2(int fd, t_texture_flag *flag, int *map_start_line);

void	init_content_info(char *filename, t_game *game, int *map_start_line)
{
	int				fd;
	char			*line;
	char			**split_line;
	t_texture_flag	*texture_flag;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		error_exit("Invalid file");
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
	init_content_info_2(fd, texture_flag, map_start_line);
}

void	init_content_info_2(int fd, t_texture_flag *flag, int *map_start_line)
{
	char	*line;

	if (flag->count != 6)
		error_exit("Invalid information");
	free(flag);
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
