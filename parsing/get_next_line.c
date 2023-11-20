/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunlee <jiyunlee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 14:18:56 by jiyunlee          #+#    #+#             */
/*   Updated: 2023/11/20 20:56:35 by jiyunlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static char	*free_mem(char **ptr)
{
	free(*ptr);
	*ptr = 0;
	return (NULL);
}

static char	*read_line(int fd, char **backup)
{
	char	buff[BUFFER_SIZE + 1];
	ssize_t	read_byte;
	char	*tmp;

	while (!ft_strchr(*backup, '\n'))
	{
		read_byte = read(fd, buff, BUFFER_SIZE);
		if (read_byte <= 0)
			break ;
		buff[read_byte] = 0;
		if (!*backup)
			*backup = ft_strdup("");
		tmp = *backup;
		*backup = ft_strjoin(*backup, buff);
		free(tmp);
		if (!*backup)
			return (NULL);
	}
	if (read_byte < 0)
		return (free_mem(backup));
	return (*backup);
}

static char	*split_line(char **backup, size_t i)
{
	char	*line;
	char	*tmp;

	line = malloc(sizeof(char) * (i + 1));
	if (!line)
		return (free_mem(backup));
	ft_strlcpy(line, *backup, i + 1);
	tmp = *backup;
	*backup = ft_strdup(&(*backup)[i]);
	free(tmp);
	if (!*backup)
		return (free_mem(&line));
	if (!*backup[0])
		free_mem(backup);
	return (line);
}

char	*get_next_line(int fd)
{
	static char		*backup;
	char			*line;
	size_t			i;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!read_line(fd, &backup))
		return (NULL);
	i = 0;
	while (backup[i] && backup[i] != '\n')
		i++;
	if (backup[i] == '\n')
		return (split_line(&backup, i + 1));
	else
	{
		line = ft_strdup(backup);
		free_mem(&backup);
		if (!line)
			return (NULL);
		return (line);
	}
}
