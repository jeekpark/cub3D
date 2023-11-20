/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunlee <jiyunlee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 04:09:18 by jihykim2          #+#    #+#             */
/*   Updated: 2023/11/20 09:29:42 by jiyunlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3d.h"

int	main(int argc, char **argv)
{
	// t_game	game;
	int		fd;

	if (argc != 2)
		error_exit("Invalid argument");
	check_valid_file(argv, &fd);
	
	// init_game_info(argv[1], &game);

	return (0);
}
