/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_var.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrewrzepecki <anrzepec@student.42.f      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/05 20:35:52 by andrewrze         #+#    #+#             */
/*   Updated: 2019/01/11 01:21:18 by andrewrze        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../ft_printf.h"

void        ft_print_flags(t_flags flags)
{
    printf("\nFLAGS\n");
    printf("Attributes: %s\n", flags.attributes);
    printf("Width: %d\n", flags.width);
    printf("Precision %d\n", flags.precision);
    printf("Modifier %s\n", flags.modifier);
    printf("Format %c\n", flags.format);
}
