/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbritto- <vbritto-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 08:11:37 by arepsa            #+#    #+#             */
/*   Updated: 2024/12/28 12:17:10 by vbritto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*lst - the node to free*/
/*frees the memory of the node’s content..*/
/*..using the function ’del’ given as a parameter..*/
/*..and free the node. The memory of ’next’ must not be freed.*/
/*(lst->content implicitly cast to void*)*/
void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (!lst)
		return ;
	(*del)(lst->content);
	free(lst);
}
