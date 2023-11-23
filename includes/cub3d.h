/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 04:10:38 by jihykim2          #+#    #+#             */
/*   Updated: 2023/11/23 10:20:40 by jihykim2         ###   ########.fr       */
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
void	check_argument(int argc, char **argv);

/* get_next_line.c */
char	*get_next_line(int fd);

/* free_func.c */
void	free_arr(char **arr);
void	free_str_arr(char *str, char **arr);
void	free_data(t_game *game);

/* utils.c */
void	error_exit(char *str);
char	*gnl_no_newline(int fd);

/* init_game_info.c */
void	init_game_info(char *filename, t_game *game);

/* init_content_info.c */
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


/* [texturing] */
void	init_mlx(t_game *game);

void	play_game(t_game *game);

void	init_mlx(t_game *game);

int		raycast_to_screen_3d_image(t_game *game);

void	calculate_vector_in_image(t_game *game, int screen_x);
void	find_wall_from_player(t_game *game);
void	calculate_length_of_ray(t_game *game);
void	calculate_length_of_wall(t_game *game);

void	draw_background(t_game *game);
void	draw_wall(t_game *game, int screen_x);

#endif
