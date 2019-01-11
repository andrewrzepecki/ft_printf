/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   umain.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrzepec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/03 15:56:45 by anrzepec          #+#    #+#             */
/*   Updated: 2019/01/11 19:36:47 by andrewrze        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		main(void)
{
	
	char *ret;
    int     i;
    int     y;
	char *tret;

	ret = NULL;
	tret= NULL;
//	printf("\n%010.3s\n", "abcde");
//	ft_printf("%010.3s\n", "abcde");

    //printf("%1c", '\n');
	//ft_printf("hello ca%----4c %1c va %10c%-c ??", '\0', '\n', (char)564, 0);
 
    i = ft_printf("%-10s is a string", "this");
    y = printf("%-10s is a string", "this");
    printf("\nDRW Ret: %d\n", i);
    printf("\nSYS Ret: %d\n", y);
    //   ft_printf("%#.o\n", 0);
  //  printf("%#.o\n", 0);

	return (0);
}
