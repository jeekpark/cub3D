/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunlee <jiyunlee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 03:12:22 by jiyunlee          #+#    #+#             */
/*   Updated: 2023/11/23 01:39:54 by jiyunlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	free_arr(char **arr)
{
	int	idx;

	if (arr == NULL)
		return ;
	idx = 0;
	while (arr[idx])
		free(arr[idx++]);
	free(arr);
}

void	free_str_arr(char *str, char **arr)
{
	free(str);
	free_arr(arr);
}

void	free_arr_int(int **arr, int idx)
{
	int	i;

	if (arr == NULL)
		return ;
	i = 0;
	while (i < idx)
		free(arr[i++]);
	free(arr);
}

void	free_texture(t_texture texture)
{
	free(texture.north);
	free(texture.south);
	free(texture.west);
	free(texture.east);
}

void	free_data(t_game *game)
{
	free_arr_int(game->map, game->map_height);
	free_texture(game->img_info);
	free(game);
}
