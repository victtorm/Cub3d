/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbritto- <vbritto-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 16:25:47 by vbritto-          #+#    #+#             */
/*   Updated: 2024/12/13 16:26:16 by vbritto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	is_space(char c)
{
	if (c == ' ' || (c >= 9 && c <= 13))
		return (true);
	return (false);
}

//a line with only tabs or spaces is not an empty line! Check this after
bool	empty_line(char *line)
{
	while (*line)
	{
		if (*line != '\r' || *line != '\n')
			return (false);
		line ++;
	}
	return (true);
}

void	safe_exit(t_data *cub, char *msg, int exit_code)
{
	if (exit_code == ERR_CODE)
		ft_putstr_fd("Error\n", (exit_code + 1));
	if (msg)
		ft_putstr_fd(msg, (exit_code + 1));
	cub_clean(cub);
	exit (exit_code);
}

void	*safe_malloc(t_data *cub, size_t size)
{
	void	*mem;

	mem = malloc(size);
	if (!mem)
		safe_exit(cub, "malloc failed to allocate memory\n", ERR_CODE);
	return (mem);
}

void	*safe_calloc(t_data *cub, size_t n_args, size_t size)
{
	void	*mem;

	mem = calloc(n_args, size);
	if (!mem)
		safe_exit(cub, "calloc failed to allocate memory\n", ERR_CODE);
	return (mem);
}
