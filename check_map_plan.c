/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_plan.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbritto- <vbritto-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 16:44:17 by rvarela           #+#    #+#             */
/*   Updated: 2024/12/28 13:30:00 by vbritto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	is_limit(t_data *cub, size_t x, size_t y)
{
	char	**tmp_map;

	tmp_map = cub->map_mtrx;
	if (x == 0 || x == (ft_strlen(tmp_map[y]) - 1) || y == 0 \
		|| y == (cub->map_y) - 1)
		return (true);
	else if (x >= ft_strlen(tmp_map[y - 1]) || x >= ft_strlen(tmp_map[y + 1]))
		return (true);
	return (false);
}

static void	check_limit(t_data *cub, char point)
{
	if (point != '1' && point != ' ')
		clean_err_quit(cub, "Map is not closed\n");
}

static void	check_around_player(t_data *cub, char **map, size_t x, size_t y)
{
	if ((map[y - 1][x - 1] == '1' && map[y - 1][x] == '1' \
	&& map[y - 1][x + 1] == '1' && map[y][x - 1] == '1' \
	&& map[y][x + 1] == '1' && map[y + 1][x - 1] == '1' \
	&& map[y + 1][x] == '1' && map[y + 1][x + 1] == '1') || \
	(map[y - 1][x - 1] == ' ' && map[y - 1][x] == ' ' \
	&& map[y - 1][x + 1] == ' ' && map[y][x - 1] == ' ' \
	&& map[y][x + 1] == ' ' && map[y + 1][x - 1] == ' ' \
	&& map[y + 1][x] == ' ' && map[y + 1][x + 1] == ' '))
		clean_err_quit(cub, "Player can't move\n");
}

static void	check_valid_around(t_data *cub, char **m, size_t x, size_t y)
{
	if (m[y][x] == ' ')
	{
		if ((m[y - 1][x - 1] && !ft_strchr(" 1", m[y - 1][x - 1])) \
		|| (m[y - 1][x] && !ft_strchr(" 1", m[y - 1][x])) \
		|| (m[y - 1][x + 1] && !ft_strchr(" 1", m[y - 1][x + 1])) \
		|| (m[y][x - 1] && !ft_strchr(" 1", m[y][x - 1])) \
		|| (m[y][x + 1] && !ft_strchr(" 1", m[y][x + 1])) \
		|| (m[y + 1][x - 1] && !ft_strchr(" 1", m[y + 1][x - 1])) \
		|| (m[y + 1][x] && !ft_strchr(" 1", m[y + 1][x])) \
		|| (m[y + 1][x + 1] && !ft_strchr(" 1", m[y + 1][x + 1])))
			clean_err_quit(cub, "Not a valid map\n");
	}
	else if (m[y][x] == '0')
	{
		if (!ft_strchr("01SWNE", m[y - 1][x - 1]) || \
		!ft_strchr("01SWNE", m[y - 1][x]) \
		|| !ft_strchr("01SWNE", m[y - 1][x + 1]) \
		|| !ft_strchr("01SWNE", m[y][x - 1]) \
		|| !ft_strchr("01SWNE", m[y][x + 1]) \
		|| !ft_strchr("01SWNE", m[y + 1][x - 1]) \
		|| !ft_strchr("01SWNE", m[y + 1][x]) \
		|| !ft_strchr("01SWNE", m[y + 1][x + 1]))
			clean_err_quit(cub, "Not a valid map\n");
	}
}

void	check_map(t_data *cub)
{
	char	**map;
	size_t	x;
	size_t	y;

	map = cub->map_mtrx;
	y = 0;
	while (y < cub->map_y)
	{
		x = 0;
		while (x < ft_strlen(map[y]))
		{
			if (is_limit(cub, x, y))
				check_limit(cub, map[y][x]);
			else if (!is_limit(cub, x, y) && ft_strchr("NSEW", map[y][x]))
				check_around_player(cub, map, x, y);
			else if (!is_limit(cub, x, y) && ((map[y][x] == ' ') \
				|| (map[y][x] == '0')))
				check_valid_around(cub, map, x, y);
			x++;
		}
		y++;
	}
}
