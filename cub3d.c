/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunlee <jiyunlee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 04:09:18 by jihykim2          #+#    #+#             */
/*   Updated: 2023/11/20 19:05:44 by jiyunlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3d.h"

int	main(int argc, char **argv)
{
	t_game	*game;

	if (argc != 2)
		error_exit("Invalid argument");
	check_valid_file(argv);

	game = ft_calloc(1, sizeof(t_game));
	init_game_info(argv[1], game);

	return (0);
}
