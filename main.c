/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrewrzepecki <anrzepec@student.42.f      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 18:45:46 by andrewrze         #+#    #+#             */
/*   Updated: 2018/12/18 01:17:15 by andrewrze        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int     main()
{
    ft_printf("%.10d\n", 42);
    ft_printf("My name is %s, my name is %.1s\n", "Andrew", "Andrew");
    return (0);
}
