/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vipereir <vipereir@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 14:31:44 by vipereir          #+#    #+#             */
/*   Updated: 2022/06/22 15:09:46 by vipereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *s, ...);
int		ft_putunbr_print(unsigned int n);
int		ft_hex_print(char xx, unsigned int nb);
int		ft_pointeraddress_print(unsigned long nb);
int		ft_putchar_print(char c);
int		ft_putstr_print(char *s);
int		ft_putnbr_print(int n);
int		ft_print_params(char c, va_list params);

#endif
