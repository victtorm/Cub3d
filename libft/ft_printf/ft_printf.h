/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbritto- <vbritto-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 12:19:51 by vbritto-          #+#    #+#             */
/*   Updated: 2024/12/28 12:19:51 by vbritto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>

void	ft_putchar_pf(char c, int *count);
void	ft_putstr_pf(char *str, int *count);
void	ft_check(va_list args, char *string, int i, int *count);
int		ft_printf(const char *format, ...);
void	ft_putnbr_pf(int nbr, int *count);
void	ft_putnbr_pf_base(unsigned int nbr, char *base, int *count);
void	ft_print_ptr(unsigned long long ptr, char *base, int *count);
void	ft_putnbr_ptr(unsigned long long ptr, char *base, int *count);

#endif
