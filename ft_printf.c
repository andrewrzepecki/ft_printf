/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrzepec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 14:50:29 by anrzepec          #+#    #+#             */
/*   Updated: 2019/01/11 19:27:25 by andrewrze        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char            *ft_add_buffsize(char *buff, int *len)
{
    char    *new;

    if (!(new = ft_memalloc(len[RETURN] + len[INDEX] + len[VLEN] + 1)))
        return (NULL);
    ft_memcpy(new, buff, len[RETURN] + 1);
    ft_strdel(&buff);
    buff = NULL;
    return (new);
}

int             ft_write_stdo(char **buff, const char *s, char *v, int *len)
{
    int i;

    if (*buff == NULL)
    {
        if (!(*buff = ft_memalloc(len[INDEX] + len[VLEN] + 1)))
            return (-1);
    }
    else
        if (!(*buff = ft_add_buffsize(*buff, len)))
            return (-1);
    i = 0;
    while (i < len[INDEX])
        (*buff)[len[RETURN]++] = s[i++];
    i = 0;
    while (i < len[VLEN])
        (*buff)[len[RETURN]++] = v[i++];
    (*buff)[len[RETURN]] = '\0';
    return (1);
}

char            *ft_get_var(const char *format, va_list ap, int *len)
{
	char	*var;
	t_flags	flags;

	flags = reset_flags();
	if ((len[POSITION] = ft_format_parser(&flags, format)) == -1)
		return (NULL);
	if (!(var = ft_apply_flags(ap, flags, &len[VLEN])))
		return (NULL);
	return (var);
}

int				ft_printf(const char *format, ...)
{
	int		len[4];
	char	*var;
    char    *buff;
	va_list	ap;

	len[RETURN] = 0;
	va_start(ap, format);
    buff = NULL;
	while (format[(len[INDEX] = 0)])
	{
		len[VLEN] = 0;
		len[POSITION] = 0;
		while (format[len[INDEX]] != '%' && format[len[INDEX]])
			len[INDEX]++;
		if (format[len[INDEX]] == '%')
			if ((var = ft_get_var(format + len[INDEX], ap, len)) < 0)
				return (-1);
        if (ft_write_stdo(&buff, format, var, len) < 0)
            return (-1);
		format = format + len[INDEX] + len[POSITION];
	}
    write(1, buff, len[RETURN]);
	va_end(ap);
	return (len[RETURN]);
}
