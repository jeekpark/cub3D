/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunlee <jiyunlee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 03:12:22 by jiyunlee          #+#    #+#             */
/*   Updated: 2023/11/21 23:22:05 by jiyunlee         ###   ########.fr       */
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

void	free_arr_int(int **arr)
{
	int	idx;

	if (arr == NULL)
		return ;
	idx = 0;
	while (arr[idx])
		free(arr[idx++]);
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
	free_arr_int(game->map);
	free_texture(game->img_info);
	free(game);
}
