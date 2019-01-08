/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrzepec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 14:50:29 by anrzepec          #+#    #+#             */
/*   Updated: 2019/01/08 19:45:49 by anrzepec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*ft_get_var(const char *format, va_list ap, int *len)
{
	char	*var;
	t_flags	flags;

	flags = reset_flags();
	if ((len[0] = ft_format_parser(&flags, format)) == -1)
		return (NULL);
	if (!(var = ft_apply_flags(ap, flags, &len[1])))
		return (NULL);
	return (var);
}

int				ft_printf(const char *format, ...)
{
	int		i;
	int		len[2];
	int		ret;
	char	*var;
	va_list	ap;

	ret = 0;
	va_start(ap, format);
	while (format[(i = 0)])
	{
		len[0] = 0;
		len[1] = 0;
		while (format[i] != '%' && format[i])
			i++;
		if (format[i] == '%')
			if ((var = ft_get_var(format + i, ap, len)) < 0)
				return (-1);
		write(1, format, i);
		write(1, var, len[1]);
		format = format + i + len[0];
		ret += len[1] + i;
	}
	va_end(ap);
	return (ret);
}
