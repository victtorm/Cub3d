/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbritto- <vbritto-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 18:13:59 by vbritto-          #+#    #+#             */
/*   Updated: 2024/12/28 12:11:12 by vbritto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_texture(t_data *cub)
{
	t_mlx		*conection;

	cub->txtr = safe_malloc(cub, sizeof(t_txtr));
	conection = cub->mlx->mlx_connection;
	cub->txtr->texture[0] = mlx_xpm_file_to_image(conection, cub->flags->no_tex,
			&cub->txtr->txt_w[0], &cub->txtr->txt_h[0]);
	cub->txtr->texture[1] = mlx_xpm_file_to_image(conection, cub->flags->so_tex,
			&cub->txtr->txt_w[1], &cub->txtr->txt_h[1]);
	cub->txtr->texture[2] = mlx_xpm_file_to_image(conection, cub->flags->we_tex,
			&cub->txtr->txt_w[2], &cub->txtr->txt_h[2]);
	cub->txtr->texture[3] = mlx_xpm_file_to_image(conection, cub->flags->ea_tex,
			&cub->txtr->txt_w[3], &cub->txtr->txt_h[3]);
	if (cub->txtr->texture[0] == NULL || cub->txtr->texture[1] == NULL
		|| cub->txtr->texture[2] == NULL || cub->txtr->texture[3] == NULL)
		safe_exit(cub, "Texture not defined\n", ERR_CODE);
	cub->txtr->start_y = 0;
	cub->txtr->last_y = 0;
	cub->txtr->len_wall = 0;
	cub->txtr->scale = 0.0;
	cub->txtr->txtr_pos = 0;
	cub->txtr->pixels_adr = NULL;
	cub->txtr->bits_per_pixel = 0;
	cub->txtr->endian = 0;
	cub->txtr->line_len = 0;
}

void	init_mlx(t_data *cub)
{
	cub->mlx = safe_malloc(cub, sizeof(t_mlx));
	cub->mlx->mlx_connection = mlx_init();
	if (cub->mlx->mlx_connection == NULL)
		free(cub->mlx->mlx_connection);
	cub->mlx->mlx_window = mlx_new_window(cub->mlx->mlx_connection,
			WIDTH, HEIGHT, "Cub3D");
	if (cub->mlx->mlx_window == NULL)
	{
		mlx_destroy_display(cub->mlx->mlx_connection);
		free(cub->mlx->mlx_connection);
	}
	cub->mlx->img = mlx_new_image(cub->mlx->mlx_connection,
			WIDTH, HEIGHT);
	if (cub->mlx->img == NULL)
	{
		mlx_destroy_window(cub->mlx->mlx_connection, cub->mlx->mlx_window);
		mlx_destroy_display(cub->mlx->mlx_connection);
		free(cub->mlx->mlx_connection);
	}
	cub->mlx->pixels_adr = mlx_get_data_addr(cub->mlx->img,
			&cub->mlx->bits_per_pixel, &cub->mlx->line_len, &cub->mlx->endian);
}

void	init_player(t_data *cub)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (cub->map_mtrx[x])
	{
		while (cub->map_mtrx[x][y])
		{
			if (cub->map_mtrx[x][y] == 'N' || cub->map_mtrx[x][y] == 'S'
				|| cub->map_mtrx[x][y] == 'E' || cub->map_mtrx[x][y] == 'W')
			{
				cub->ray->p_x = x + 0.5;
				cub->ray->p_y = y + 0.5;
				cub->ray->pos_mapx = x;
				cub->ray->pos_mapy = y;
			}
			y++;
		}
		y = 0;
		x++;
	}
	cub->ray->next_x = cub->ray->p_x;
	cub->ray->next_y = cub->ray->p_y;
}

void	init_ray(t_data *cub)
{
	cub->ray = safe_malloc(cub, sizeof(t_ray));
	init_player(cub);
	init_dir(cub->play_dir, cub);
	cub->ray->mult = 0.0;
	cub->ray->raydir = 0.0;
	cub->ray->raydir_x = 0.0;
	cub->ray->raydir_y = 0.0;
	cub->ray->deltadirx = 0.0;
	cub->ray->deltadiry = 0.0;
	cub->ray->disttox = 0.0;
	cub->ray->disttoy = 0.0;
	cub->ray->speed = 0.3;
}

void	cub3d_init(t_data *cub)
{
	init_mlx(cub);
	init_ray(cub);
	init_texture(cub);
}
