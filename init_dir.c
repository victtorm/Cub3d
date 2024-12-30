/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_dir.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbritto- <vbritto-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 16:20:33 by vbritto-          #+#    #+#             */
/*   Updated: 2024/12/28 17:19:00 by vbritto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	sector_w(t_data *cub)
{
	cub->ray->dir_x = 0;
	cub->ray->dir_y = -1;
	cub->ray->plane_x = -0.66;
	cub->ray->plane_y = 0;
}

void	sector_e(t_data *cub)
{
	cub->ray->dir_x = 0;
	cub->ray->dir_y = 1;
	cub->ray->plane_x = 0.66;
	cub->ray->plane_y = 0;
}

void	sector_s(t_data *cub)
{
	cub->ray->dir_x = 1;
	cub->ray->dir_y = 0;
	cub->ray->plane_x = 0;
	cub->ray->plane_y = -0.66;
}

void	sector_n(t_data *cub)
{
	cub->ray->dir_x = -1;
	cub->ray->dir_y = 0;
	cub->ray->plane_x = 0;
	cub->ray->plane_y = 0.66;
}

void	init_dir(char c, t_data *cub)
{
	if (c == 'N')
		sector_n(cub);
	else if (c == 'S')
		sector_s(cub);
	else if (c == 'E')
		sector_e(cub);
	else if (c == 'W')
		sector_w(cub);
}
