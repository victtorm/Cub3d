/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbritto- <vbritto-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 14:19:16 by vbritto-          #+#    #+#             */
/*   Updated: 2024/12/27 18:31:00 by vbritto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_move(t_data *cub)
{
	int	check_x;
	int	check_y;

	check_x = (int)cub->ray->next_x;
	check_y = (int)cub->ray->next_y;
	if (cub->map_mtrx[cub->ray->pos_mapx][check_y] == '1'
		|| (cub->map_mtrx[check_x][cub->ray->pos_mapy] == '1')
		|| (cub->map_mtrx[check_x][check_y] == '1'))
	{
		cub->ray->next_x = cub->ray->p_x;
		cub->ray->next_y = cub->ray->p_y;
	}
	else
	{
		cub->ray->p_x = cub->ray->next_x;
		cub->ray->p_y = cub->ray->next_y;
	}
	cub->ray->pos_mapx = (int)cub->ray->p_x;
	cub->ray->pos_mapy = (int)cub->ray->p_y;
}
