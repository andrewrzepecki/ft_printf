/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   umain.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrzepec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/03 15:56:45 by anrzepec          #+#    #+#             */
/*   Updated: 2019/01/08 19:36:15 by anrzepec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		main(void)
{
	
	char *ret;

	char *tret;

	ret = NULL;
	tret= NULL;
//	printf("\n%010.3s\n", "abcde");
//	ft_printf("%010.3s\n", "abcde");

    //printf("%1c", '\n');
	//ft_printf("hello ca%----4c %1c va %10c%-c ??", '\0', '\n', (char)564, 0);
   
	ft_printf("test%-8p %---32p %#5.3x%#024X", &ret, &tret, 0x25, 0);
 //   ft_printf("%#.o\n", 0);
  //  printf("%#.o\n", 0);

	return (0);
}
