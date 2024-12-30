/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbritto- <vbritto-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 15:45:34 by vbritto-          #+#    #+#             */
/*   Updated: 2024/12/27 15:45:36 by vbritto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	is_valid_xpm(t_data *cub, int i)
{
	int	fnm_len;

	if (ft_strchr(cub->f_line, '/'))
	{
		while (cub->f_line[i] != '/')
			i++;
	}
	fnm_len = ft_strlen(cub->f_line) - i;
	if (fnm_len <= 4 || ft_strncmp(cub->f_line + i + fnm_len - 4, ".xpm", 4))
		return (false);
	return (true);
}

void	set_text_flag(t_data *cub, char wall, int i)
{
	if (wall == 'n')
	{
		if (!cub->flags->no_tex)
			cub->n_textures_set += 1;
		cub->flags->no_tex = ft_strdup(cub->f_line + i);
	}
	else if (wall == 'w')
	{
		if (!cub->flags->we_tex)
			cub->n_textures_set += 1;
		cub->flags->we_tex = ft_strdup(cub->f_line + i);
	}
	else if (wall == 's')
	{
		if (!cub->flags->so_tex)
			cub->n_textures_set += 1;
		cub->flags->so_tex = ft_strdup(cub->f_line + i);
	}
	else if (wall == 'e')
	{
		if (!cub->flags->ea_tex)
			cub->n_textures_set += 1;
		cub->flags->ea_tex = ft_strdup(cub->f_line + i);
	}
}

static bool	text_exists(t_data *cub, char wall)
{
	if (wall == 's' && cub->flags->so_tex)
		return (true);
	else if (wall == 'n' && cub->flags->no_tex)
		return (true);
	else if (wall == 'w' && cub->flags->we_tex)
		return (true);
	else if (wall == 'e' && cub->flags->ea_tex)
		return (true);
	return (false);
}

void	parse_texture(t_data *cub, char wall)
{
	int	fd_text;
	int	i;

	if (text_exists(cub, wall))
		clean_err_quit(cub, "There are two textures for the same wall\n");
	i = 3;
	while (cub->f_line[i] && is_space(cub->f_line[i]))
		i++;
	if (!is_valid_xpm(cub, i))
		clean_err_quit(cub, "Invalid extension texture file\n");
	fd_text = open(cub->f_line + i, O_RDONLY);
	if (fd_text < 0)
		clean_err_quit(cub, "Invalid texture file\n");
	close (fd_text);
	set_text_flag(cub, wall, i);
}
