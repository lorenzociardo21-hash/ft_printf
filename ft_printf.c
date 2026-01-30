/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lciardo <lciardo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 10:02:09 by lciardo           #+#    #+#             */
/*   Updated: 2026/01/30 14:59:34 by lciardo          ###   ########.fr       */
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

// int main(void)
// {
// 	int ret1;
// 	int ret2;

// 	printf("========== EDGE CASES TESTER ==========\n\n");

// 	/* CHAR */
// 	printf("---- CHAR ----\n");
// 	ret1 = printf("printf   : [%c]\n", 0);
// 	ret2 = ft_printf("ft_printf: [%c]\n", 0);
// 	printf("return printf = %d | return ft_printf = %d\n\n", ret1, ret2);

// 	/* STRING */
// 	printf("---- STRING ----\n");
// 	ret1 = printf("printf   : [%s]\n", "");
// 	ret2 = ft_printf("ft_printf: [%s]\n", "");
// 	printf("empty string -> printf = %d | ft_printf = %d\n", ret1, ret2);

// 	ret1 = printf("printf   : [%s]\n", NULL);
// 	ret2 = ft_printf("ft_printf: [%s]\n", NULL);
// 	printf("NULL string -> printf = %d | ft_printf = %d\n\n", ret1, ret2);

//  /* POINTER */
//  printf("---- POINTER ----\n");
//  ret1 = printf("printf   : [%p]\n", NULL);
//  ret2 = ft_printf("ft_printf: [%p]\n", NULL);
//  printf("NULL pointer -> printf = %d | ft_printf = %d\n\n", ret1, ret2);

//  int x = 42;
//  ret1 = printf("printf   : [%p]\n", 9223372036854775807);
//  ret2 = ft_printf("ft_printf: [%p]\n", 9223372036854775807);
//  printf("valid pointer -> printf = %d | ft_printf = %d\n\n", ret1, ret2);

// 	/* INT / DECIMAL */
// 	printf("---- INT / DECIMAL ----\n");
// 	ret1 = printf("printf   : [%d]\n", 0);
// 	ret2 = ft_printf("ft_printf: [%d]\n", 0);
// 	printf("zero -> printf = %d | ft_printf = %d\n", ret1, ret2);

// 	ret1 = printf("printf   : [%d]\n", INT_MIN);
// 	ret2 = ft_printf("ft_printf: [%d]\n", INT_MIN);
// 	printf("INT_MIN -> printf = %d | ft_printf = %d\n", ret1, ret2);

// 	ret1 = printf("printf   : [%d]\n", INT_MAX);
// 	ret2 = ft_printf("ft_printf: [%d]\n", INT_MAX);
// 	printf("INT_MAX -> printf = %d | ft_printf = %d\n\n", ret1, ret2);

// 	/* UNSIGNED */
// 	printf("---- UNSIGNED ----\n");
// 	ret1 = printf("printf   : [%u]\n", 0);
// 	ret2 = ft_printf("ft_printf: [%u]\n", 0);
// 	printf("zero -> printf = %d | ft_printf = %d\n", ret1, ret2);

// 	ret1 = printf("printf   : [%u]\n", UINT_MAX);
// 	ret2 = ft_printf("ft_printf: [%u]\n", UINT_MAX);
// 	printf("UINT_MAX -> printf = %d | ft_printf = %d\n\n", ret1, ret2);

// 	/* HEX */
// 	printf("---- HEX ----\n");
// 	ret1 = printf("printf   : [%x]\n", 0);
// 	ret2 = ft_printf("ft_printf: [%x]\n", 0);
// 	printf("zero lower -> printf = %d | ft_printf = %d\n", ret1, ret2);

// 	ret1 = printf("printf   : [%X]\n", UINT_MAX);
// 	ret2 = ft_printf("ft_printf: [%X]\n", UINT_MAX);
// 	printf("UINT_MAX upper -> printf = %d | ft_printf = %d\n\n", ret1, ret2);

// 	/* PERCENT */
// 	printf("---- PERCENT ----\n");
// 	ret1 = printf("printf   : [%%]\n");
// 	ret2 = ft_printf("ft_printf: [%%]\n");
// 	printf("percent -> printf = %d | ft_printf = %d\n\n", ret1, ret2);

// 	/* MIXED EDGE CASE */
// 	printf("---- MIXED ----\n");
// 	ret1 = printf("printf   : [%s %d %u %x %p %%]\n", NULL, INT_MIN, 0, \
// 0, NULL);
// 	ret2 = ft_printf("ft_printf: [%s %d %u %x %p %%]\n", NULL, INT_MIN, 0, \
// 0, NULL);
// 	printf("mixed -> printf = %d | ft_printf = %d\n\n", ret1, ret2);
// 	int d  = ft_printf(0);
// 	int n  = printf(0);
// 	printf("num ft: %d, num print: %d", d, n);
// 	printf("========== END ==========\n");
// 	return (0);
// }