/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_precision.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrzepec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 17:33:39 by anrzepec          #+#    #+#             */
/*   Updated: 2019/01/04 17:48:14 by anrzepec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_positive_precision(char **s, t_flags flags, int len)
{
	char	*zero;
	char 	*tmp;

	tmp = *s;
	if (!(zero = (char*)ft_memalloc(flags.precision - len + 1)))
           return (0);
	zero = (char*)ft_memset(zero, '0', flags.precision - len);
	if (!(*s = ft_strjoin(zero, *s)))
		return (0);
	ft_strdel(&tmp);
	ft_strdel(&zero);
	return (1);
}

int			ft_negative_precision(char **s, t_flags flags, int len)
{
	char	*tmp;
	char	*zero;

	if (!(tmp = ft_strsub(*s, 1, ft_strlen(*s) - 1)))
		return (0);
	ft_strdel(s);
	if (!(zero = (char*)ft_memalloc(flags.precision - len + 1)))
		return (0);
	zero = (char*)ft_memset(zero, '0', flags.precision - len);
	if (!(*s = ft_strjoin(zero, tmp)))
		return (0);
	ft_strdel(&tmp);
	ft_strdel(&zero);
	tmp = *s;
	if (!(*s = ft_strjoin("-", *s)))
		return (0);
	ft_strdel(&tmp);
	return (1);	
}

int			ft_apply_precision(char **s, t_flags flags)
{
    int     len;
    char    *tmp;

    if (flags.precision == -1)
        return (1);
    if (flags.format == 's')
    {
		tmp = *s;
        if (!(*s = ft_strndup(*s, flags.precision)))
            return (0);
		//ft_strdel(&tmp);
    }
    else if ((len = ft_strlen(*s)) < flags.precision
            && ft_strchr("diouxXpb", flags.format))
    {
		if (s[0][0] == '-')
		{
			if (!(ft_negative_precision(s, flags, len - 1)))
				return (0);
		}
		else
			if (!(ft_positive_precision(s, flags, len)))
				return (0);
    }
    return (1);
}
