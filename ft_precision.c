/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_precision.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrzepec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 17:33:39 by anrzepec          #+#    #+#             */
/*   Updated: 2018/12/18 01:19:54 by andrewrze        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_apply_precision(char **s, t_flags flags)
{
    int     len;
    char    *zero;
    char    *tmp;

    tmp = *s;
    if (flags.precision == -1)
        return (1);
    if (flags.format == 's')
    {
        if (!(*s = ft_strndup(*s, flags.precision)))
            return (0);
    }
    else if ((len = ft_strlen(*s)) < flags.precision
            && ft_strchr("diouxX", flags.format))
    {
        if (!(zero = (char*)ft_memalloc(flags.precision - len + 1)))
            return (0);
        zero = (char*)ft_memset(zero, '0', flags.precision - len);
        if (!(*s = ft_strjoin(zero, *s)))
            return (0);
    }
 //   ft_varchar_free(2, &tmp, &zero);
    return (1);
}
