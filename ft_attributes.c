/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_attributes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrzepec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 14:15:06 by anrzepec          #+#    #+#             */
/*   Updated: 2018/12/19 02:41:18 by andrewrze        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char    *ft_move_prefix(char *s, char *prefix, t_flags flags)
{
    char *del;
    char *tmp;
    char *str;

    tmp = ft_strchr("Xxbp", flags.format) ? ft_strsub(s, 2, ft_strlen(s) - 2) /
          : ft_strsub(s, 1, ft_strlen(s) - 1);
    if (!tmp)
        return (NULL);
    if (!(del = ft_strjoin(prefix, tmp)))
        return (NULL);
    ft_strdel(&tmp);
    tmp = ft_strchr("Xxbp", flags.format) ? ft_strndup(s, 2) : ft_strndup(s, 1);
    if (!tmp)
        return (NULL);
    if (!(str = ft_strjoin(tmp, del)))
        return (NULL);
    ft_varchar_free(2, &tmp, &del);
    return (str);
}

int		ft_apply_width(char **s, t_flags flags, int len)
{
    char *tmp;
    char prefix[len + 1];

    prefix = ft_strchr(flags.attributes, '0') && !ft_strchr(flags.attributes, '-') ? \
             (char*)ft_memset(prefix, '0', len) : (char*)ft_memset(prefix, ' ', len);
    prefix[len] = '\0';
    tmp = *s
    if (ft_strchr(flags.attributes, '-'))
        if (!(*s = ft_strjoin(*s, prefix)))
            return (1);
    else if ((ft_strchr("diouxXb", flags.format) && (ft_strchr(flags.attributes, '#')
            || s[0][0] == '-')) || flags.format == 'p')
        if (!(s = ft_move_prefix(*s, prefix, flags)))
            return (0);
    else
        if (!(*s = ft_strjoin(prefix, *s)))
            return (0);
    ft_strdel(&tmp);
	return (1);
}

int		ft_sign_attrib(char **s, t_flags flags)
{
    char *tmp;

    if (ft_strchr("di", flags.format) && s[0][0] != '-')
    {
        tmp = *s;
        *s = ft_strchr(flags.attributes, '+') ? ft_strjoin("+", *s) : ft_strjoin(" ", *s);
        ft_strdel(&tmp);
    }
    if (*s == NULL)
        return (0);
    return (1);
}

int		ft_hash_attrib(char **s, t_flags flags)
{
    char *tmp;

    if (!ft_strchr("pxXbo", flags.format))
        return (1);
    tmp = *s
    if (ft_strchr("pxX", flags.format))
        *s = flags.format == 'X' ? ft_strjoin("0X", *s) : ft_strjoin("0x", *s);
    if else (flags.format == 'b')
        *s = ft_strjoin("0b", *s);
    else
        *s = ft_strjoin("0", *s);
    ft_strdel(&tmp);
    if (*s == NULL)
        return (0);
	return (1);
}

int		ft_apply_attrib(char **s, t_flags flags)
{
    int len;

	if (ft_strchr(flags.attributes, '#') || flags.format == 'p')
		if (!ft_hash_attrib(s, flags))
			return (0);
	if (ft_strchr(flags.attributes, '+') || ft_strchr(flags.attributes, ' '))
		if (!ft_sign_attrib(s))
			return (0);
	if ((len = flags.width - ft_strlen(*s)) > 0)
		if (ft_strchr(flags.attributes, '0') || ft_strchr(flags.attributes, '-'))
			if (!ft_apply_width(s, flags, len))
				return (0);
	return (1);
}
