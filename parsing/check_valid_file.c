/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_file.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunlee <jiyunlee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 03:14:07 by jiyunlee          #+#    #+#             */
/*   Updated: 2023/11/20 09:29:21 by jiyunlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	error_exit(char *str)
{
	ft_putendl_fd("Error", STDERR_FILENO);
	ft_putendl_fd(str, STDERR_FILENO);
	exit(EXIT_FAILURE);
}

void	check_valid_file(char **argv, int *fd)
{
	char	*filename;
	size_t	len;

	filename = argv[1];
	len = ft_strlen(filename);
	if (len <= 4 || ft_strncmp(filename + len - 4, ".cub", 4) \
		|| filename[len - 5] == '/')
		error_exit("Invalid filename");
	*fd = open(argv[1], O_RDONLY);
	if (*fd < 0)
		error_exit("Invalid filename");
}