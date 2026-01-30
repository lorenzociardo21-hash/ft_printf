/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lciardo <lciardo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 10:02:16 by lciardo           #+#    #+#             */
/*   Updated: 2026/01/30 12:53:33 by lciardo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

int				ft_printf(const char *str, ...);
int				print_char(int c);
int				print_str(char *str);
int				print_dig(long n, int base, int flag);
int				print_point(void *point);
unsigned long	print_pointer(unsigned long n, unsigned long base, int flag);

#endif