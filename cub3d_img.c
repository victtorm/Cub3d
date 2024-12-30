/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_img.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbritto- <vbritto-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 18:17:02 by vbritto-          #+#    #+#             */
/*   Updated: 2024/12/27 18:30:06 by vbritto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_put_pixels(t_mlx *mlx, int x, int y, int color)
{
	int	move;

	move = 0;
	move = (y * mlx->line_len) + (x * (mlx->bits_per_pixel / 8));
	*(unsigned int *)(mlx->pixels_adr + move) = color;
}

void	background(t_data *cub)
{
	int	w;
	int	h;

	w = 0;
	while (w <= WIDTH)
	{
		h = 0;
		while (h < HEIGHT)
		{
			if (h >= HEIGHT / 2)
				ft_put_pixels(cub->mlx, w, h, cub->c_hexa);
			else
				ft_put_pixels(cub->mlx, w, h, cub->f_hexa);
			h++;
		}
		w++;
	}
}

void	cub3d_img(t_data *cub)
{
	background(cub);
	raycasting(cub);
	mlx_put_image_to_window(cub->mlx->mlx_connection,
		cub->mlx->mlx_window, cub->mlx->img, 0, 0);
}
