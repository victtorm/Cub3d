/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvarela- <rvarela-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 15:46:34 by vbritto-          #+#    #+#             */
/*   Updated: 2024/12/28 13:13:17 by rvarela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	map_ext_check(char *file)
{
	if (ft_strlen(file) <= 4 \
		|| ft_strncmp(file + ft_strlen(file) - 4, ".cub", 4) \
		|| !ft_strncmp(file + ft_strlen(file) - 5, "/.cub", 5))
		return (0);
	return (1);
}

static void	flags_init(t_data *cub)
{
	cub->flags = safe_malloc(cub, sizeof(t_flag));
	cub->flags->ea_tex = NULL;
	cub->flags->no_tex = NULL;
	cub->flags->so_tex = NULL;
	cub->flags->we_tex = NULL;
	cub->flags->c_color = 0;
	cub->flags->f_color = 0;
	cub->map_str = NULL;
	cub->map_mtrx = NULL;
}

void	run_cub3d(char *map)
{
	t_data	cub;

	ft_memset(&cub, 0, sizeof(cub));
	flags_init(&cub);
	cub.f_hexa = 0;
	cub.c_hexa = 0;
	parse_file(&cub, map);
	cub3d_init(&cub);
	cub3d_events(&cub);
	cub3d_img(&cub);
	mlx_loop(cub.mlx->mlx_connection);
}

int	main(int ac, char **av)
{
	if (ac == 2 && map_ext_check(av[1]))
		run_cub3d(av[1]);
	else
	{
		if (ac != 2)
		{
			ft_putstr_fd("Error\n", 2);
			ft_putstr_fd(SH_RED"X  Usage: ./cub3d <map_file>.cub\n"RESET, 2);
		}
		else
		{
			ft_putstr_fd("Error\n", 2);
			ft_putstr_fd(SH_RED"X  Invalid map file extension\n"RESET, 2);
		}
	}
	return (0);
}
