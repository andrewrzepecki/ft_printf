/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrewrzepecki <anrzepec@student.42.f      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/21 19:20:33 by andrewrze         #+#    #+#             */
/*   Updated: 2019/01/02 21:13:17 by andrewrze        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int         main(void)
{
    // Mandatory Complete, floats, doubles and NaN to handle, norme to handle && 
    // reorganisation of compiler     
    int *ptr;
    int nbr;

    printf("%#- 0000017X\n", -42);
    ft_printf("%#- 0000017X\n", -42);

    printf(" tere %#X\n", 4); 
    ft_printf(" here %#X\n", 4);

    ft_printf("My ret: {{%d}}\n", ft_printf("Insert var here: %042.3s and %15.3s\n", "abcdef", "12345"));
    printf("Sys ret: {{%d}}\n", printf("Insert var here: %042.3s and %15.3s\n", "abcdef", "12345"));
    
    return (0);
}
