/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strn_strl_cmp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbritto- <vbritto-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 15:24:44 by arepsa            #+#    #+#             */
/*   Updated: 2024/12/28 12:18:15 by vbritto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* 
** compare two strings by content and by length 
** returns "true" if strings are equal
*/
bool	strn_strl_cmp(char *s1, char *s2)
{
	if (s1 == NULL)
		return (false);
	if (ft_strncmp(s1, s2, ft_strlen(s2)) == 0 && \
		ft_strlen(s1) == ft_strlen(s2))
		return (true);
	return (false);
}
