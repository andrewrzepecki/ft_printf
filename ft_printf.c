/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrzepec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 14:50:29 by anrzepec          #+#    #+#             */
/*   Updated: 2018/12/12 21:35:54 by anrzepec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_get_var(char *format, int len, char **buff, va_list ap)
{
	int 	i;
	t_flags flags;

	format = format + len;
	if ((i = ft_format_parser(&flags, format)) == -1)
		return (-1);
	return (len);
}

int				ft_printf(const char *format, ...)
{
	int		i;
	int		len;
	int 	ret;
	va_list	ap;

	i = 0;
	len = 0;
	ret = 0;
	va_start(ap, format);
	while (format[i])
	{
		while (format[i] != '%' && format[i]) 
			i++;
		write(1, format, i);
		if (format[i] == '%')
		{
			if ((ret = ft_get_var(format, i, ap) == -1)
				return (-1);
		}
		len += ret + i;
		i = 0;
	}
	return (len);
}