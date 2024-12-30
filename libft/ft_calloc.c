/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbritto- <vbritto-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 09:07:33 by arepsa            #+#    #+#             */
/*   Updated: 2024/12/28 12:16:50 by vbritto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*allocates memory for an array of nmemb elements of size bytes each..
..and returns a pointer to the allocated memory. 
The memory is set to zero.*/
/*If nmemb or size is 0, then calloc() returns either NULL, 
or a unique pointer value that can later be successfully passed to free().*/
void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*p;

	p = malloc (nmemb * size);
	if (!p)
		return (NULL);
	ft_memset (p, 0, nmemb * size);
	return (p);
}
