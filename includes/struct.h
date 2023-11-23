/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 11:54:38 by jihykim2          #+#    #+#             */
/*   Updated: 2023/11/23 10:35:03 by jihykim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

/* macro instead of bool-type */
# define TRUE			1
# define FALSE			0
# define ERROR			"Error\n"

/* get_next_line buffer size */
# define BUFFER_SIZE	1

/* map(wall or not) */
# define SPACE			0
# define WALL			1
# define EMPTY			-1

/* screen size*/
# define SCR_WIDTH		1200	// screen 값 -> 변경 가능
# define SCR_HEIGHT		800

/* hit direction */
# define N_OR_S			1
# define W_OR_E			0

/* key-code */
# define KEY_EXIT		17
# define KEY_ESC		53
# define KEY_ACT		2
# define KEY_DEACT		3

# define KEY_W			13
# define KEY_A			0
# define KEY_S			1
# define KEY_D			2
# define KEY_LEFT		123
# define KEY_RIGHT		124

/* speed */
# define MOVE_SPEED		0.05	// moving speed (고정 상수)
# define ROTATE_SPEED	0.05	// rotating speed (pi/180으로 진행되기도 함)

/* parsing data */
typedef enum e_direction
{
	NORTH = 2,
	SOUTH,
	WEST,
	EAST,
}	t_direction;

typedef struct s_texture_flag
{
	int	count;
	int	north;
	int	south;
	int	west;
	int	east;
	int	floor;
	int	ceiling;
}	t_texture_flag;

/* executing data */
typedef struct s_vec_f
{
	double	x;
	double	y;
}	t_vec_f;

typedef struct s_vec_i
{
	int	x;
	int	y;
}	t_vec_i;

typedef struct s_texture
{
	char	*north;
	char	*south;
	char	*west;
	char	*east;
	int		floor;		// ex) 0xFF0000
	int		ceiling;	// ex) 0xFF0000
}	t_texture;

typedef struct s_image
{
	void	*img;
	char	*addr;
	int		bpp;
	int		size_line;
	int		endian;
	int		width;
	int		height;
}	t_image;

typedef struct s_key
{
	int	move_n;
	int	move_s;
	int	move_w;
	int	move_e;
	int	rotate_r;
	int	rotate_l;
}	t_key;

typedef struct s_raycast
{
	t_vec_f	ray_dir;
	t_vec_f	side_dist;
	t_vec_f	delta_dist;

	t_vec_i	map_pos;
	t_vec_i	step_dir;

	int		side;
	int		perp_wall_dist;
	int		wall_length_in_screen;
	int		draw_start;
	int		draw_end;
	double	hit_point;		// hit_point at wall-texture(real pixel value of x)

	t_image	*wall_data;		// copy address of t_game's t_texture
}	t_raycast;


/* [parse -> execute]: 넘겨줄 인자 */
// : 이들 모두 2차원 평면 상으로 가정하므로 값 방향 유의하기
typedef struct s_game
{
	int			**map;		// parse: 2차원 좌표평면계와 동일한 형태로 x, y값을 저장한 지도 (0, 1, -1)
	int			map_width;	// parse: map's width
	int			map_height;	// parse: map's height

	t_vec_f		player;		// parse: player 위치 저장 (2차원 평면 상) 단, 이때, 초기 값은 0.5씩 더해주어야 함
	t_vec_f		view_dir;	// parse: player의 보고 있는 방향
	t_vec_f		plane_dir;	// parse: player의 보고 있는 방향에 수직인 평면 벡터 (N이라 가정할 때: x=0, y=0.66 이 비율은 고정(66도))
	t_texture	img_info;	// parse: image, color에 대한 정보

	t_raycast	ray_info;	// info for ray-casting

	void		*mlx_ptr;
	void		*win_ptr;
	t_image		screen;
	t_image		north;
	t_image		south;
	t_image		west;
	t_image		east;

	t_key		key;

}	t_game;

#endif
