/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvarela- <rvarela-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 14:23:43 by rvarela           #+#    #+#             */
/*   Updated: 2024/12/27 19:30:28 by rvarela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	missing_text_color(t_data *cub)
{
	close (cub->fd);
	if (!all_textures_colors(cub))
		safe_exit(cub, "Color or texture missing\n", ERR_CODE);
	safe_exit(cub, "Invalid line in map file\n", ERR_CODE);
}

static bool	is_valid_color(t_data *cub, int *i, int j, int color)
{
	if (color < 0 || color > 255)
		return (false);
	while (cub->f_line[*i] && is_space(cub->f_line[*i]))
		(*i)++;
	if (j < 2 && cub->f_line[*i] != ',')
		return (false);
	else if (j < 2 && cub->f_line[*i] == ',')
		(*i)++;
	while (cub->f_line[*i] && is_space(cub->f_line[*i]))
		(*i)++;
	if (j == 2 && cub->f_line[*i] && !is_space(cub->f_line[*i]))
		return (false);
	return (true);
}

static void	color_hexa(t_data *cub, int *rgb, char plane)
{
	int	color_hexa;

	color_hexa = (rgb[0] << 16 | rgb[1] << 8 | rgb[2]);
	if (plane == 'f')
	{
		cub->n_plan_colors_set += 1;
		cub->f_hexa = color_hexa;
	}
	else if (plane == 'c')
	{
		cub->n_plan_colors_set += 1;
		cub->c_hexa = color_hexa;
	}
	else
		clean_err_quit(cub, "Invalid plane for color\n");
}

static void	parse_rgb(t_data *cub, int i, char plane)
{
	int	rgb[3];
	int	j;

	rgb[0] = 0;
	rgb[1] = 0;
	rgb[2] = 0;
	j = 0;
	while (cub->f_line[i])
	{
		while (cub->f_line[i] && is_space(cub->f_line[i]))
			i++;
		if (!ft_isdigit(cub->f_line[i]))
			clean_err_quit(cub, "Invalid color\n");
		while (cub->f_line[i] && ft_isdigit(cub->f_line[i]))
			rgb[j] = rgb[j] * 10 + (cub->f_line[i++] - 48);
		if (!is_valid_color(cub, &i, j, rgb[j]))
			clean_err_quit(cub, "Invalid color\n");
		j++;
		if (j == 3 && cub->f_line[i])
			clean_err_quit(cub, "Invalid color\n");
	}
	if (j != 3)
		clean_err_quit(cub, "Invalid color\n");
	color_hexa(cub, rgb, plane);
}

void	parse_color(t_data *cub, char plane)
{
	int	i;

	if ((cub->flags->c_color && plane == 'c') \
		|| (cub->flags->f_color && plane == 'f') \
		|| (cub->flags->c_color && cub->flags->f_color))
		clean_err_quit(cub, "Color already exists\n");
	i = 2;
	while (cub->f_line[i] && is_space(cub->f_line[i]))
		i++;
	parse_rgb(cub, i, plane);
}
