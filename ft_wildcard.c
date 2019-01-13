/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wildcard.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrewrzepecki <anrzepec@student.42.f      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/13 15:35:25 by andrewrze         #+#    #+#             */
/*   Updated: 2019/01/13 16:12:30 by andrewrze        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int         ft_precision_wildcard(t_flags *flags, va_list ap)
{
    flags->precision = va_arg(ap, int);
    flags->precision = flags->precision < 0 ? -1 : flags->precision;
    return (0);
}

int         ft_width_wildcard(t_flags *flags, va_list ap)
{
    char    *tmp;

    flags->width = va_arg(ap, int);
    if (flags->width < 0)
    {
        if (!flags->attributes)
        {
            if (!(flags->attributes = ft_strdup("-")))
                return (-1);
            flags->width = flags->width * -1;
            return (0);
        }
        tmp = flags->attributes;
        if (!(tmp = ft_strjoin(flags->attributes, "-")))
            return (-1);
        ft_strdel(&flags->attributes);
        flags->attributes = tmp;
        flags->width = flags->width * -1;
    }
    return (0);
}
