/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunlee <jiyunlee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 04:10:38 by jihykim2          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2023/11/20 21:42:58 by jihykim2         ###   ########.fr       */
=======
/*   Updated: 2023/11/20 19:06:21 by jiyunlee         ###   ########.fr       */
>>>>>>> main
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

<<<<<<< HEAD
/* [texturing] */
void	init_drawing_image(t_game *game);
=======
/* [parsing] */
/* check_valid_file.c */
void	error_exit(char *str);
void	check_valid_file(char **argv);

void	init_game_info(char *filename, t_game *game);

char	*get_next_line(int fd);
>>>>>>> main

#endif
