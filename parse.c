/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvarela- <rvarela-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 13:17:26 by rvarela-          #+#    #+#             */
/*   Updated: 2024/12/28 13:17:29 by rvarela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//check if all textures and colors are set
bool	all_textures_colors(t_data *cub)
{
	if (cub->n_plan_colors_set == 2 && cub->n_textures_set == 4)
		return (true);
	return (false);
}

static void	parse_textures_colors(t_data *cub)
{
	int	l_len;

	l_len = ft_strlen(cub->f_line);
	if (!ft_strncmp(cub->f_line, "WE ", 3) && l_len > 7)
		parse_texture(cub, 'w');
	else if (!ft_strncmp(cub->f_line, "SO ", 3) && l_len > 7)
		parse_texture(cub, 's');
	else if (!ft_strncmp(cub->f_line, "NO ", 3) && l_len > 7)
		parse_texture(cub, 'n');
	else if (!ft_strncmp(cub->f_line, "EA ", 3) && l_len > 7)
		parse_texture(cub, 'e');
	else if (!ft_strncmp(cub->f_line, "F ", 2) && l_len > 6)
		parse_color(cub, 'f');
	else if (!ft_strncmp(cub->f_line, "C ", 2) && l_len > 6)
		parse_color(cub, 'c');
	else if (cub->f_line)
		clean_err_quit(cub, "Invalid line in map file\n");
}

static void	into_map(t_data *cub, char *line)
{
	if ((line[0] == ' ' || line[0] == '1') && all_textures_colors(cub))
	{
		get_map_plan(cub, line);
		cub->map_y++;
	}
	else
	{
		free (line);
		missing_text_color(cub);
	}
}

static void	parse_line(t_data *cub, char *line)
{
	cub->f_line = NULL;
	if (ft_strchr(line, ',') || ft_strchr(line, '.'))
	{
		cub->f_line = ft_strtrim(line, " \r\t");
		free(line);
		line = NULL;
		parse_textures_colors(cub);
	}
	if (cub->f_line)
		free (cub->f_line);
	else if (empty_line(line) && cub->map_y > 0)
	{
		free(line);
		clean_err_quit(cub, "Empty line in map plan\n");
	}
	else if (!empty_line(line))
		into_map(cub, line);
	safe_memfree(line);
}

void	parse_file(t_data *cub, char *map)
{
	char	*line;
	char	*trim_line;

	cub->fd = open(map, O_RDONLY);
	if (cub->fd < 0)
		safe_exit(cub, "Cannot open map file\n", ERR_CODE);
	line = get_next_line(cub->fd);
	while (line)
	{
		trim_line = ft_strtrim(line, "\r\n");
		free (line);
		parse_line(cub, trim_line);
		line = get_next_line(cub->fd);
	}
	get_next_line(-3);
	parse_map_plan(cub);
}
