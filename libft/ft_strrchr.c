/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbritto- <vbritto-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 10:01:37 by arepsa            #+#    #+#             */
/*   Updated: 2024/12/28 12:18:02 by vbritto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*searches for the last occurrence of the character in the string*/
/*s[i] -> end of string*/
/*cast to char to avoid overflow if the argument passed is 
outside the range of char*/
char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	ch;

	ch = (char)c;
	i = ft_strlen(s);
	while (i > 0 && s[i] != ch)
		i--;
	if (s[i] == ch)
		return ((char *)&s[i]);
	return (NULL);
}
