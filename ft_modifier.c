/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_modifier.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrewrzepecki <anrzepec@student.42.f      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/16 14:38:54 by andrewrze         #+#    #+#             */
/*   Updated: 2018/12/18 14:14:46 by anrzepec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned long long	ft_apply_umodifier(va_list ap, t_flags flags)
{
	 unsigned long long d;

    if (!flags.modifier)
        d = (unsigned int)va_arg(ap, unsigned long long int);
    else if (ft_strlen(flags.modifier) == 2)
    {
        if (flags.modifier[0] == 'l')
            d = va_arg(ap, unsigned long long int);
        else
            d = (unsigned char)va_arg(ap, unsigned long long int);
    }
    else
    {
        if (flags.modifier[0] == 'l')
            d = va_arg(ap, unsigned long int);
        else if (flags.modifier[0] != 'L')
            d = (unsigned char)va_arg(ap, unsigned long long int);
    }
    return (d);	
}

long long       	ft_apply_modifier(va_list ap, t_flags flags)
{
    long long d;

    if (!flags.modifier)
        d = va_arg(ap, int);
    else if (ft_strlen(flags.modifier) == 2)
    {
        if (flags.modifier[0] == 'l')
            d = (long long)va_arg(ap, long long);
        else
            d = (char)va_arg(ap, int);
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
