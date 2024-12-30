/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbritto- <vbritto-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 13:01:30 by vbritto-          #+#    #+#             */
/*   Updated: 2024/12/28 17:53:48 by vbritto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

unsigned int	get_pixel_color(t_txtr *txtr, int x, int y, int index)
{
	char	*data_adr;
	char	*dst;
	int		offset;

	data_adr = mlx_get_data_addr(txtr->texture[index], &txtr->bits_per_pixel,
			&txtr->line_len, &txtr->endian);
	offset = (y * txtr->line_len + x * (txtr->bits_per_pixel / 8));
	dst = data_adr + offset;
	return (*(unsigned int *)dst);
}

void	put_texture(t_data *cub, int x, int img_index)
{
	int		y;
	int		color;
	int		txt_x;
	t_txtr	*txt;

	txt = cub->txtr;
	txt->scale = 1.0 * cub->txtr->txt_h[img_index]
		/ (double)cub->txtr->len_wall;
	txt_x = cub->txtr->txt_w[img_index] * cub->txtr->start_x;
	txt->txtr_pos = (cub->txtr->start_y
			- HEIGHT / 2 + cub->txtr->len_wall / 2) * cub->txtr->scale;
	y = cub->txtr->start_y;
	while (y < cub->txtr->last_y)
	{
		txt->txtr_pos += txt->scale;
		color = get_pixel_color(cub->txtr, txt_x, txt->txtr_pos, img_index);
		ft_put_pixels(cub->mlx, x, y, color);
		y++;
	}
}

void	get_texture_ranges(t_data *cub)
{
	cub->txtr->len_wall = (int)(HEIGHT / cub->ray->walldist);
	cub->txtr->start_y = -(cub->txtr->len_wall / 2) + (HEIGHT / 2);
	if (cub->txtr->start_y < 0)
		cub->txtr->start_y = 0;
	cub->txtr->last_y = (HEIGHT / 2) + (cub->txtr->len_wall / 2);
	if (cub->txtr->last_y > HEIGHT)
		cub->txtr->last_y = HEIGHT - 1;
	if (!cub->ray->hit_side)
		cub->txtr->start_x = cub->ray->p_y
			+ (cub->ray->walldist * cub->ray->raydir_y);
	else
		cub->txtr->start_x = cub->ray->p_x
			+ (cub->ray->walldist * cub->ray->raydir_x);
	cub->txtr->start_x -= floor(cub->txtr->start_x);
}

void	draw_wall(t_data *cub, int x)
{
	double	start_y;
	double	last_y;

	get_texture_ranges(cub);
	start_y = cub->txtr->start_y;
	last_y = cub->txtr->last_y;
	if (cub->ray->hit_side && cub->ray->raydir_y < 0)
		put_texture(cub, x, 2);
	else if (cub->ray->hit_side && cub->ray->raydir_y > 0)
		put_texture(cub, x, 3);
	else if (!cub->ray->hit_side && cub->ray->raydir_x < 0)
		put_texture(cub, x, 0);
	else if (!cub->ray->hit_side && cub->ray->raydir_x > 0)
		put_texture(cub, x, 1);
}
