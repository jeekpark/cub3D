/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_texture_info.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunlee <jiyunlee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 02:39:44 by jiyunlee          #+#    #+#             */
/*   Updated: 2023/11/23 01:32:29 by jiyunlee         ###   ########.fr       */
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

int	rgb_to_int(char *str)
{
	int	num;

	num = 0;
	while (*str)
	{
		num = num * 10 + (*str - '0');
		if (!(0 <= num && num <= 255))
			error_exit("Invalid color information");
		str++;
	}
	return (num);
}

int	init_color_info(char *rgb_str)
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
	if (comma != 2 || !rgb_arr[0] || !rgb_arr[1] || !rgb_arr[2] || rgb_arr[3]
		|| !only_digit(rgb_arr[0])
		|| !only_digit(rgb_arr[1])
		|| !only_digit(rgb_arr[2]))
		error_exit("Invalid color information");
	rgb[0] = rgb_to_int(rgb_arr[0]);
	rgb[1] = rgb_to_int(rgb_arr[1]);
	rgb[2] = rgb_to_int(rgb_arr[2]);
	rgb_int = rgb[0] * 256 * 256 + rgb[1] * 256 + rgb[2];
	free_arr(rgb_arr);
	return (rgb_int);
}

void	init_texture_info(t_texture *img_info, char **info, t_texture_flag *f)
{
	if (!info[0] || !info[1] || info[2])
		error_exit("Invalid texture information");
	if (!ft_strcmp(info[0], "NO") && !f->north++ && ++f->count)
		img_info->north = ft_strdup(info[1]);
	else if (!ft_strcmp(info[0], "SO") && !f->south++ && ++f->count)
		img_info->south = ft_strdup(info[1]);
	else if (!ft_strcmp(info[0], "WE") && !f->west++ && ++f->count)
		img_info->west = ft_strdup(info[1]);
	else if (!ft_strcmp(info[0], "EA") && !f->east++ && ++f->count)
		img_info->east = ft_strdup(info[1]);
	else if (!ft_strcmp(info[0], "F") && !f->floor++ && ++f->count)
		img_info->floor = init_color_info(info[1]);
	else if (!ft_strcmp(info[0], "C") && !f->ceiling++ && ++f->count)
		img_info->ceiling = init_color_info(info[1]);
	else
		error_exit("Invalid information");
}
