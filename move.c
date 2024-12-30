/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbritto- <vbritto-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 12:33:32 by vbritto-          #+#    #+#             */
/*   Updated: 2024/12/26 12:42:54 by vbritto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_up(t_ray *ray, double speed)
{
	ray->next_x = ray->p_x + (ray->dir_x * speed);
	ray->next_y = ray->p_y + (ray->dir_y * speed);
}

void	move_down(t_ray *ray, double speed)
{
	ray->next_x = ray->p_x - (ray->dir_x * speed);
	ray->next_y = ray->p_y - (ray->dir_y * speed);
}

void	move_right(t_ray *ray, double speed)
{
	ray->next_x = ray->p_x + (ray->plane_x * speed);
	ray->next_y = ray->p_y + (ray->plane_y * speed);
}

void	move_left(t_ray *ray, double speed)
{
	ray->next_x = ray->p_x - (ray->plane_x * speed);
	ray->next_y = ray->p_y - (ray->plane_y * speed);
}
