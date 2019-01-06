/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrewrzepecki <anrzepec@student.42.f      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/21 19:20:33 by andrewrze         #+#    #+#             */
/*   Updated: 2019/01/06 14:13:14 by andrewrze        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int         main(void)
{
    // Mandatory Complete, floats, doubles and NaN to handle, norme to handle 
    int *ptr;
    int nbr;

    printf("%10s is a string\n", "this");
    ft_printf("%10s is a string\n", "this");

    printf(" tere %#d\n", -1); 
    ft_printf(" here %#d\n", -1);


    ft_printf("My ret: {{%d}}\n", ft_printf("Insert var here: %042.3s and %15.3s\n", "abcdef", "12345"));
    printf("Sys ret: {{%d}}\n", printf("Insert var here: %042.3s and %15.3s\n", "abcdef", "12345"));
    
    return (0);
}
