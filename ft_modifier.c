/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_modifier.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrzepec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/03 17:43:03 by anrzepec          #+#    #+#             */
/*   Updated: 2019/01/04 17:48:16 by anrzepec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned long long	ft_apply_umodifier(va_list ap, t_flags flags)
{
	 unsigned long long int d;

    d = 0;
	if (!flags.modifier && !ft_strchr("Uu", flags.format))
		d = va_arg(ap, unsigned int);
	else if (ft_strchr("Uu", flags.format))
		d = va_arg(ap, unsigned long long int);
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
		else
			d = va_arg(ap, unsigned int);
    }
    return (d);	
}

long long       	ft_apply_modifier(va_list ap, t_flags flags)
{
    long long d;

    d = 0;
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
		else
			d = va_arg(ap, int);
    }
    return (d);
}
