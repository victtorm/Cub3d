/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_words.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbritto- <vbritto-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 17:23:13 by arepsa            #+#    #+#             */
/*   Updated: 2024/12/28 12:16:50 by vbritto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_count_words(char *str)
{
	int	i;
	int	words;

	i = 0;
	words = 0;
	while (str[i])
	{
		while (str[i] && ft_iswhitespace(str[i]))
			i++;
		if (str[i] && !ft_iswhitespace(str[i]))
		{
			words++;
			while (str[i] && !ft_iswhitespace(str[i]))
				i++;
		}
	}
	return (words);
}
