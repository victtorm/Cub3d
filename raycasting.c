/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbritto- <vbritto-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 14:45:14 by vbritto-          #+#    #+#             */
/*   Updated: 2024/12/28 12:15:16 by vbritto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	find_dist(t_ray *ray)
{
	ray->disttox = (ray->p_x - ray->pos_mapx) * ray->deltadirx;
	ray->step_x = -1;
	if (ray->raydir_x >= 0)
	{
		ray->disttox = (1 + ray->pos_mapx - ray->p_x) * ray->deltadirx;
		ray->step_x = 1;
	}
	ray->disttoy = (ray->p_y - ray->pos_mapy) * ray->deltadiry;
	ray->step_y = -1;
	if (ray->raydir_y >= 0)
	{
		ray->disttoy = (1 + ray->pos_mapy - ray->p_y) * ray->deltadiry;
		ray->step_y = 1;
	}
}

void	uptade_vectors(t_data *cub, int x)
{
	cub->ray->hit_x = (int)cub->ray->p_x;
	cub->ray->hit_y = (int)cub->ray->p_y;
	cub->ray->mult = 2 * x / (double)WIDTH - 1;
	cub->ray->raydir_x = cub->ray->dir_x + cub->ray->plane_x * cub->ray->mult;
	cub->ray->raydir_y = cub->ray->dir_y + cub->ray->plane_y * cub->ray->mult;
	if (cub->ray->raydir_x == 0)
		cub->ray->deltadirx = INT_MAX;
	else
		cub->ray->deltadirx = fabs(1 / cub->ray->raydir_x);
	if (cub->ray->raydir_y == 0)
		cub->ray->deltadiry = INT_MAX;
	else
		cub->ray->deltadiry = fabs(1 / cub->ray->raydir_y);
	find_dist(cub->ray);
}

int	hit_wall(t_data *cub, t_ray *ray, int hit)
{
	if (ray->disttox < ray->disttoy)
	{
		ray->disttox += ray->deltadirx;
		ray->hit_x += ray->step_x;
		ray->hit_side = 0;
		ray->walldist = ray->disttox - ray->deltadirx;
	}
	else
	{
		ray->disttoy += ray->deltadiry;
		ray->hit_y += ray->step_y;
		ray->hit_side = 1;
		ray->walldist = ray->disttoy - ray->deltadiry;
	}
	if (cub->map_mtrx[ray->hit_x][ray->hit_y]
			&& cub->map_mtrx[ray->hit_x][ray->hit_y] == '1')
		hit = 1;
	return (hit);
}

void	raycasting(t_data *cub)
{
	int	x;
	int	hit;

	x = 0;
	hit = 0;
	while (x <= WIDTH)
	{
		uptade_vectors(cub, x);
		while (hit == 0)
			hit = hit_wall(cub, cub->ray, hit);
		hit = 0;
		draw_wall(cub, x);
		x++;
	}
}
