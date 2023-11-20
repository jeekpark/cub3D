/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunlee <jiyunlee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 11:54:38 by jihykim2          #+#    #+#             */
/*   Updated: 2023/11/20 19:05:21 by jiyunlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# define TRUE		1
# define FALSE		0
# define ERROR		"Error\n"

# define KEY_EXIT	17
# define KEY_ESC	53
# define KEY_ACT	2

# define KEY_W		13
# define KEY_A		0
# define KEY_S		1
# define KEY_D		2

# define KEY_LEFT	123
# define KEY_RIGHT	124

# define BUFFER_SIZE 42

typedef struct	s_vec_f
{
	double	x;
	double	y;
	double	ratio;
}	t_vec_f;

// typedef struct	s_vec_i
// {
// 	int	x;
// 	int	y;
// }	t_vec_i;

typedef struct s_data
{
	void	*img;
}	t_data;

typedef struct s_texture
{
	char	*north;
	char	*south;
	char	*west;
	char	*east;
	int		floor;		// ex) 0xFF0000
	int		ceiling;	// ex) 0xFF0000
}	t_texture;


/* [parse -> execute]: 넘겨줄 인자 */
// 이들 모두 2차원 평면 상으로 가정하므로 값 방향 유의하기
typedef struct s_game
{
	char				**map;		// parse: 2차원 좌표평면계와 동일한 형태로 x, y값을 저장한 지도
	struct s_vec_f		*player;	// parse: player 위치 저장 (2차원 평면 상)
	struct s_vec_f		*view_dir;	// parse: player의 보고 있는 방향
	struct s_vec_f		*plane_dir;	// parse: player의 보고 있는 방향에 수직인 평면 벡터 (N이라 가정할 때: x=0, y=0.66 이 비율은 고정(66도))
	struct s_texture	*img_info;	// parse: image, color에 대한 정보
}	t_game;

#endif
