/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbritto- <vbritto-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 12:15:46 by arepsa            #+#    #+#             */
/*   Updated: 2024/12/28 12:17:38 by vbritto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*Searches within the n bytes of the block of memory pointed by s..*/
/*..for the first occurrence of char c*/
/*doesn't take into account NUL char, stops at defined length n*/
/*returns a pointer to the matching byte..*/
/*..or NULL if the character does not occur*/
void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t		i;
	char		*str;
	char		ch;

	str = (char *)s;
	ch = (char)c;
	i = 0;
	while (i < n)
	{
		if (str[i] == ch)
			return ((void *)&str[i]);
		i++;
	}
	return (0);
}
