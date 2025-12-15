/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testvari.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lciardo <lciardo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 10:21:57 by lciardo           #+#    #+#             */
/*   Updated: 2025/12/15 11:44:17 by lciardo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//variadic function
//  gcc prova.c -Llibft -lft 
#include <stdarg.h>  //per muoverci in tutte quelle funzioni utili
#include <stdio.h>    //va_start   va_arg  va_end

int ft_media(int n, ...)
{
	int i;
	int total;
	va_list	ap;// ap argment pointer, ap punta al primio argomento (n)
	va_start(ap, n); // gli sto dicendo di prendere ap e saltare n e inziare a contare da quello dopo
	total = 0;
	i = 0;
	while (i < n)
	{
		total += va_arg(ap, int);//faccio muovere il mio puntaratoe su tutti gli int che incontrera,
		i++;
	}
	return total/n;
}
//int main()
{
	int	media;
	media = ft_media(3, 5, 10, 15);
	printf("%d\n", media);
}