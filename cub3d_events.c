/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_events.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbritto- <vbritto-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 12:36:43 by vbritto-          #+#    #+#             */
/*   Updated: 2024/12/28 17:21:17 by vbritto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	close_window(t_data *cub)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (cub->txtr->texture[i])
			mlx_destroy_image(cub->mlx->mlx_connection, cub->txtr->texture[i]);
		i++;
	}
	mlx_destroy_image(cub->mlx->mlx_connection, cub->mlx->img);
	mlx_destroy_window(cub->mlx->mlx_connection, cub->mlx->mlx_window);
	mlx_destroy_display(cub->mlx->mlx_connection);
	free (cub->mlx->mlx_connection);
	cub_clean(cub);
	exit(1);
}

int	mouse_imput(int button, int x, int y, t_data *cub)
{
	(void)button;
	mlx_destroy_image(cub->mlx->mlx_connection, cub->mlx->img);
	cub->mlx->img = mlx_new_image(cub->mlx->mlx_connection,
			WIDTH, HEIGHT);
	mlx_mouse_get_pos(cub->mlx->mlx_connection, cub->mlx->mlx_window, &x, &y);
	return (0);
}

int	key_imput(int keysym, t_data *cub)
{
	if (keysym == XK_Escape)
		close_window(cub);
	mlx_destroy_image(cub->mlx->mlx_connection, cub->mlx->img);
	cub->mlx->img = mlx_new_image(cub->mlx->mlx_connection,
			WIDTH, HEIGHT);
	if (keysym == XK_w)
		move_up(cub->ray, cub->ray->speed);
	if (keysym == XK_s)
		move_down(cub->ray, cub->ray->speed);
	if (keysym == XK_a)
		move_left(cub->ray, cub->ray->speed);
	if (keysym == XK_d)
		move_right(cub->ray, cub->ray->speed);
	if (keysym == XK_Left)
		rotate(cub->ray, cub->ray->speed);
	if (keysym == XK_Right)
		rotate(cub->ray, -cub->ray->speed);
	check_move(cub);
	cub3d_img(cub);
	return (0);
}

void	cub3d_events(t_data *cub)
{
	mlx_hook(cub->mlx->mlx_window, KeyPress, KeyPressMask, key_imput, cub);
	mlx_hook(cub->mlx->mlx_window, ButtonPress, ButtonPressMask,
		mouse_imput, cub);
	mlx_hook(cub->mlx->mlx_window, DestroyNotify, StructureNotifyMask,
		close_window, cub);
}
