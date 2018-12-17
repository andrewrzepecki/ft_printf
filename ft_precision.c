/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_precision.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrzepec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 17:33:39 by anrzepec          #+#    #+#             */
/*   Updated: 2018/12/17 14:58:11 by andrewrze        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_apply_precision(char **s, t_flags flags)
{
    int     len;
	char    *tmp;
    char    *stmp;

    tmp = *s;
    stmp = NULL;
    if (flags.precision == -1)
		return (1);
    if (!(stmp = ft_memalloc(flags.precision - len)))
        return (0);
    len = ft_strlen(*s);
	if (flags.format == 's' && len > flags.precision)
    {
		if (!(*s = ft_strndup(*s, flags.precision)))
			return (0);
    }
	else if (ft_strchr("diouxX", flags.format) && len < flags.precision)
        if (!(*s = ft_strjoin(stmp, *s)))
            return (0);
    ft_varchar_free(2, &tmp[1], &tmp[2]);
	return (1);
}
