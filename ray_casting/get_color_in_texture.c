/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color_in_texture.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 22:18:18 by jihykim2          #+#    #+#             */
/*   Updated: 2023/11/23 23:59:08 by jihykim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	get_color_in_texture(t_image *component, int x, int y)
{
	int	res;
	int	*addr_ptr;

	addr_ptr = (int *)component->addr;
	if (x >= component->width || y >= component->height
		|| x < 0 || y < 0)
	{
		return (0);
	}
	res = addr_ptr[component->size_line / (component->bpp / 8) * y + x];
	if (res == -16777216)
	{
		return (0);
	}
	return (res);
}
