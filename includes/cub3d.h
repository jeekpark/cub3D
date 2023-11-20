/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunlee <jiyunlee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 04:10:38 by jihykim2          #+#    #+#             */
/*   Updated: 2023/11/21 02:45:32 by jiyunlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../mlx/mlx.h"
# include "../libft/libft.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
# include "./struct.h"

/* [parsing] */
/* check_valid_file.c */
void	error_exit(char *str);
void	check_argument(int argc, char **argv);

/* get_next_line.c */
char	*get_next_line(int fd);

/* init_game_info.c */
void	init_game_info(char *filename, t_game *game);

/* init_texture_info.c */
void	init_texture_info(char *filename, t_game *game, int *map_start_line);

#endif
