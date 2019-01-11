/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_width.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrewrzepecki <anrzepec@student.42.f      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 00:31:51 by andrewrze         #+#    #+#             */
/*   Updated: 2019/01/11 01:06:51 by andrewrze        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char        *ft_check_null_char(char *s, char *prefix, t_flags flags, int *len)
{
    char    *new;

    new = NULL;
    if (flags.format == 'c' && s && s[0] == '\0')
    {
        if (!(new = ft_memalloc(ft_strlen(prefix) + 2)))
            return (NULL);
        ft_memcpy(new + 1, prefix, ft_strlen(prefix));
        *len += ft_strlen(prefix);
    }
    else
        if (!(new = ft_strjoin(s, prefix)))
            return (NULL);
    return (new);
}
