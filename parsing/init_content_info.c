/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_content_info.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunlee <jiyunlee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 00:39:56 by jiyunlee          #+#    #+#             */
/*   Updated: 2023/11/23 00:41:16 by jiyunlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

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
		init_texture_info(&game->img_info, split_line, texture_flag);
		free_arr(split_line);
		if (texture_flag->count == 6)
			break ;
	}
	if (texture_flag->count != 6)
		error_exit("Invalid information");
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
