/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunlee <jiyunlee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 04:10:38 by jihykim2          #+#    #+#             */
/*   Updated: 2023/11/23 00:41:55 by jiyunlee         ###   ########.fr       */
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

/* free_func.c */
void	free_arr(char **arr);
void	free_data(t_game *game);

/* init_game_info.c */
void	init_game_info(char *filename, t_game *game);

/* init_content_info.c */
char	*delete_newline(char *line);
void	init_content_info(char *filename, t_game *game, int *map_start_line);

/* init_texture_info.c */
void	init_texture_info(t_texture *img_info, char **info, t_texture_flag *flag);

/* init_map_info.c */
void	init_map_info(char *filename, t_game *game, int map_start_line);
void	init_map(char *filename, t_game *game, int map_start_line);

/* check_valid_map.c */
void	check_valid_map(t_game *game);

/* init_player_info.c */
void	init_player_info(t_game *game);

#endif
