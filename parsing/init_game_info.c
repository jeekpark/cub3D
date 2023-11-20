/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game_info.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunlee <jiyunlee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 09:26:56 by jiyunlee          #+#    #+#             */
/*   Updated: 2023/11/20 21:02:31 by jiyunlee         ###   ########.fr       */
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

void	init_texture(t_texture *img_info, char **info)
{
	if (!ft_strcmp(info[0], "NO"))
		img_info->north = ft_strdup(info[1]);
	if (!ft_strcmp(info[0], "SO"))
		img_info->south = ft_strdup(info[1]);
	if (!ft_strcmp(info[0], "WE"))
		img_info->west = ft_strdup(info[1]);
	if (!ft_strcmp(info[0], "EA"))
		img_info->east = ft_strdup(info[1]);
	if (!ft_strcmp(info[0], "F"))
		img_info->floor = rgb_to_int(info[1]);
	if (!ft_strcmp(info[0], "C"))
		img_info->ceiling = rgb_to_int(info[1]);

}

void	init_game_info(char *filename, t_game *game)
{
	int		fd;
	char	*line;
	char	**split_line;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		error_exit("Invalid file");
	while (1)
	{
		line = get_next_line(fd);
		// printf("서손 짱!\n");
		if (!line)
			break ;
		split_line = ft_split(line, ' ');
		if (!split_line)
			exit(EXIT_FAILURE);
		init_texture(&game->img_info, split_line);
		// free split_line => 안하면 leak
		free(line);
	}
}
