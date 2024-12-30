/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_plan.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbritto- <vbritto-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 14:24:20 by rvarela           #+#    #+#             */
/*   Updated: 2024/12/28 13:29:59 by vbritto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	is_valid_map_char(t_data *cub, char c)
{
	if (ft_strchr(" 01NSEW", c))
	{
		if (ft_isalpha(c))
		{
			if (cub->play_dir != 0)
				return (false);
			cub->play_dir = c;
		}
		return (true);
	}
	return (false);
}

static void	get_nbr_map_collumns(t_data *cub, char *line)
{
	if (ft_strlen(line) > cub->map_x)
		cub->map_x = ft_strlen(line);
}

static void	save_map_string(t_data *cub, char *line)
{
	char	*tmp;

	tmp = NULL;
	if (!cub->map_str)
		cub->map_str = ft_strdup(line);
	else
	{
		tmp = ft_strjoin(cub->map_str, "-");
		free(cub->map_str);
		cub->map_str = ft_strjoin(tmp, line);
		free(tmp);
	}
}

void	get_map_plan(t_data *cub, char *line)
{
	char	*tmp_line;

	tmp_line = line;
	if (cub->map_y > 0 && (line[0] != ' ' && line[0] != '1'))
	{
		free(line);
		clean_err_quit(cub, "Invalid map char\n");
	}
	while (*tmp_line)
	{
		if (!is_valid_map_char(cub, *tmp_line++))
		{
			free(line);
			clean_err_quit(cub, "Invalid map char\n");
		}
	}
	save_map_string(cub, line);
	get_nbr_map_collumns(cub, line);
}

void	parse_map_plan(t_data *cub)
{
	if (!cub->map_str)
		clean_err_quit(cub, "Empty map\n");
	cub->map_mtrx = ft_split(cub->map_str, '-');
	if (cub->play_dir == 0)
		safe_exit(cub, "Player not defined\n", ERR_CODE);
	check_map(cub);
}
