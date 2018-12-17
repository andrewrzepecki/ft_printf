/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_modifier.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrewrzepecki <anrzepec@student.42.f      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/16 14:38:54 by andrewrze         #+#    #+#             */
/*   Updated: 2018/12/17 01:12:34 by andrewrze        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long long       ft_apply_modifier(va_list ap, t_flags flags)
{
    long long d;

    if (!flags.modifier)
        d = va_arg(ap, int);
    else if (ft_strlen(flags.modifier) == 2)
    {
        if (flags.modifier[0] == 'l')
            d = (long long)va_arg(ap, long long);
        else
            d = (short)va_arg(ap, int);
    }
    else
    {
        if (flags.modifier[0] == 'l')
            d = (long)va_arg(ap, long);
        else if (flags.modifier[0] == 'L' && flags.format == 'f')
            d = (long double)va_arg(ap, long double);
        else if (flags.modifier[0] != 'L')
            d = (short)va_arg(ap, int);
    }
    return (d);
}
