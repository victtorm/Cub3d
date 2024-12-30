/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbritto- <vbritto-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 15:21:02 by vbritto-          #+#    #+#             */
/*   Updated: 2024/12/28 17:20:46 by vbritto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	rotate(t_ray *ray, double speed)
{
	double	dirt_x;
	double	dirt_y;
	double	plane_x;
	double	plane_y;

	dirt_x = ray->dir_x;
	dirt_y = ray->dir_y;
	ray->dir_x = dirt_x * cos(speed) - dirt_y * sin(speed);
	ray->dir_y = dirt_x * sin(speed) + dirt_y * cos(speed);
	plane_x = ray->plane_x;
	plane_y = ray->plane_y;
	ray->plane_x = plane_x * cos(speed) - plane_y * sin(speed);
	ray->plane_y = plane_x * sin(speed) + plane_y * cos(speed);
}
