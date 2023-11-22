/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_argument.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunlee <jiyunlee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 03:14:07 by jiyunlee          #+#    #+#             */
/*   Updated: 2023/11/23 01:14:56 by jiyunlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	check_argument(int argc, char **argv)
{
	char	*filename;
	size_t	len;

	if (argc != 2)
		error_exit("Invalid argument");
	filename = argv[1];
	len = ft_strlen(filename);
	if (len <= 4 || ft_strncmp(filename + len - 4, ".cub", 4) \
		|| filename[len - 5] == '/')
		error_exit("Invalid filename");
}
