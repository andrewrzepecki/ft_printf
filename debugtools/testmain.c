/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testmain.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrewrzepecki <anrzepec@student.42.f      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/04 19:57:45 by andrewrze         #+#    #+#             */
/*   Updated: 2019/01/04 20:09:17 by andrewrze        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int         main()
{
    printf("%056.3s\n", "abcdef");
    printf("%04.2d\n", 1);

    ft_putendl("my function: ");
    ft_printf("%056.3s\n", "abcdef");
    ft_printf("%04.2d\n", 1);
    return (0);
}
