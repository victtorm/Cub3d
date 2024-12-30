/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbritto- <vbritto-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 09:30:27 by arepsa            #+#    #+#             */
/*   Updated: 2024/12/28 12:17:48 by vbritto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*returns a pointer to the first occurrence of character in the string*/
/*if looking for \0 , returns pointer to the null char*/
/*cast to char to avoid overflow if the argument passed is 
outside the range of char*/
char	*ft_strchr(const char *s, int c)
{
	char	ch;

	ch = (char)c;
	while (*s != '\0' && *s != ch)
		s++;
	if (*s == ch && ch != '\0')
		return ((char *)s);
	return (NULL);
}
