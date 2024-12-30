/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvarela- <rvarela-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 15:46:18 by vbritto-          #+#    #+#             */
/*   Updated: 2024/12/27 18:30:00 by rvarela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	cub_clean(t_data *cub)
{
	if (!cub)
		return ;
	safe_memfree(cub->mlx);
	safe_memfree(cub->ray);
	safe_memfree(cub->txtr);
	if (cub->map_mtrx)
		ft_free_matrix(cub->map_mtrx);
	safe_memfree(cub->flags->ea_tex);
	safe_memfree(cub->flags->no_tex);
	safe_memfree(cub->flags->so_tex);
	safe_memfree(cub->flags->we_tex);
	safe_memfree(cub->flags);
	safe_memfree(cub->map_str);
	safe_memfree(cub->f_line);
	get_next_line(-3);
}

void	safe_memfree(void *mem)
{
	if (mem)
		free (mem);
}

void	clean_err_quit(t_data *cub, char *err_msg)
{
	if (cub->fd > 0)
		close (cub->fd);
	safe_exit(cub, err_msg, ERR_CODE);
}
