/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrzepec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 14:50:29 by anrzepec          #+#    #+#             */
/*   Updated: 2018/12/23 18:41:04 by andrewrze        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*ft_join_buff(char **s, char **buff, const char **format, int *i)
{
	char *tmp;
	char *res;

	if (!(tmp = ft_strndup(*format, *i)))
		return (NULL);
	if (*s)
        res = (*buff) ? ft_strjoin(*s, *buff) : ft_strjoin(*s, tmp);
	else
        res = (*buff) ? ft_strdup(*buff) : tmp;
    if (!res)
	    return (NULL);
	if (res != tmp)
		ft_strdel(&tmp);
	ft_varchar_free(2, buff, s);
	*buff = NULL;
    *format = *format + *i;
	return (res);
}

static char		*ft_get_var(const char *format, int *i, va_list ap)
{
	int 	len;
	char	*var;
	char	*buff;
	char	*tmp;
	t_flags flags;

	if (!(tmp = ft_strndup(format, *i)))
		return (NULL);	
	flags = reset_flags();
	format = format + *i;
	if ((len = ft_format_parser(&flags, format)) == -1)
		return (NULL);
	if (!(var = ft_apply_flags(ap, flags)))
		return (NULL);
    if (!(buff = ft_strjoin(tmp, var)))
		return (NULL);
//	ft_varchar_free(2, &tmp, &var);
	*i += len;
	return (buff);
}

int				ft_printf(const char *format, ...)
{
	int		i;
	char	*s;
	char	*buff;
	va_list	ap;

	buff = 0;
    s = 0;
	va_start(ap, format);
	while (format[(i = 0)])
	{
		while (format[i] != '%' && format[i]) 
			i++;
		if (format[i] == '%')
			if (!(buff = ft_get_var(format, &i, ap)))
				return (-1);
		if (!(s = ft_join_buff(&s, &buff, &format, &i)))
			return (-1);
	}
    write(1, s, (i = ft_strlen(s)));
    ft_varchar_free(2, &buff, &s);
    va_end(ap);
	return (i);
}
