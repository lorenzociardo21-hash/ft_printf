/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lciardo <lciardo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 10:02:09 by lciardo           #+#    #+#             */
/*   Updated: 2026/01/30 12:15:19 by lciardo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_case(char *str, va_list ap, int x)
{
	int	count;

	count = 0;
	if (str[x] == 'c')
		count += print_char(va_arg (ap, int));
	else if (str[x] == 's')
		count += print_str(va_arg (ap, char *));
	else if (str[x] == 'p')
		count += print_point(va_arg (ap, void *));
	else if (str[x] == 'd')
		count += print_dig((long)va_arg (ap, int), 10, 1);
	else if (str[x] == 'i')
		count += print_dig((long)va_arg (ap, int), 10, 1);
	else if (str[x] == 'u')
		count += print_dig((long)va_arg (ap, unsigned int), 10, 1);
	else if (str[x] == 'x')
		count += print_dig((long)va_arg (ap, unsigned int), 16, 1);
	else if (str[x] == 'X')
		count += print_dig((long)va_arg (ap, unsigned int), 16, 0);
	else if (str[x] == '%')
		count += print_char('%');
	else
		count += write (1, &str[x], 1);
	return (count);
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		count;
	int		x;

	if (!str)
		return (-1);
	x = 0;
	count = 0;
	va_start (ap, str);
	while (str[x])
	{
		if (str[x] == '%')
		{
			x++;
			count = count + print_case((char *)str, ap, x);
		}
		else
			count = count + write(1, &str[x], 1);
		x++;
	}
	va_end (ap);
	return (count);
}

/* int main(void)
{
    int len_ft = 0;
    int len_std = 0;

    len_ft = ft_printf("This %p is even stranger\n", (void *)-1);
    len_std = printf("This %p is even stranger\n", (void *)-1);
    printf("Len: Mio=%d | Org=%d\n", len_ft, len_std);
} */