/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   casiprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lciardo <lciardo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 16:12:02 by lciardo           #+#    #+#             */
/*   Updated: 2025/12/16 18:43:41 by lciardo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_char(int c)
{
	return (write(1, &c, 1));
}

int	print_str(char *str)
{
	int	x;
	int	count;

	if (!str)
		str = "(null)";
	x = 0;
	count = 0;
	while (str[x])
	{
		count += print_char(str[x]);
		x++;
	}
	return (count);
}

int	print_dig(long n, int base, int flag)
{
	int		count;
	char	*symbol;

	if (flag == 1)
		symbol = "0123456789abcdef";
	else
		symbol = "0123456789ABCDEF";
	if (n < 0)
	{
		write (1, "-", 1);
		return (print_dig (-n, base, flag) + 1);
	}
	else if (n < base)
		return (print_char (symbol[n]));
	else
	{
		count = print_dig (n / base, base, flag);
		return (count + print_dig (n % base, base, flag));
	}
}

int	print_point(void *point)
{
	int				count;
	unsigned long	addres;

	count = 0;
	if (!point)
		return (write(1, "(nil)", 5));
	addres = (unsigned long)point;
	count += write(1, "0x", 2);
	count += print_dig(addres, 16, 1);
	return (count);
}
