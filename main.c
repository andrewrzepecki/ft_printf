/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrewrzepecki <anrzepec@student.42.f      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 18:45:46 by andrewrze         #+#    #+#             */
/*   Updated: 2018/12/18 11:52:08 by anrzepec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int     main()
{
	printf("%.15llo\n", 999999999999);
	printf("%.15llo\n", 999999999999);
	ft_printf("%.15llo\n", 999999999999);
    ft_printf("My name is %s, my name is %.1s\n", "Andrew", "Andrew");
    return (0);
}
