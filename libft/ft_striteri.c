/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbritto- <vbritto-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 13:07:14 by arepsa            #+#    #+#             */
/*   Updated: 2024/12/28 12:49:33 by vbritto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Apply the function ’f’ on each char of the str passed as argument,*/
/*passing its index as first argument.*/
/*Each character is passed by address to ’f’ to be modified if necessary.*/
void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	if (s)
	{
		while (s[i] != '\0')
		{
			(*f)(i, &s[i]);
			i++;
		}
	}
}
