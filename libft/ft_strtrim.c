/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbritto- <vbritto-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 15:51:48 by arepsa            #+#    #+#             */
/*   Updated: 2024/12/28 12:18:05 by vbritto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*returns a copy of ’s1’ with the characters specified in ’set’ removed..*/
/*..from the beginning and the end of the string*/
/*send the set to strchr to compare char by char of the string*/
/*if set char exists, move forward*/
/*do same from the end, using stlen as counter*/
/*length of result str: last index - first index + 1*/
char	*ft_strtrim(char const *s1, char const *set)
{
	char	*res;
	int		i;
	int		j;

	if (!s1 || !set)
		return (0);
	i = 0;
	j = ft_strlen(s1);
	while (s1[i] != '\0' && ft_strchr(set, s1[i]) != 0)
		i++;
	while (j > i && s1[j - 1] && ft_strchr(set, s1[j - 1]) != 0)
		j--;
	res = ft_substr(s1, i, j - i);
	return (res);
}
