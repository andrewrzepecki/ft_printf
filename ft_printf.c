/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrzepec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 14:50:29 by anrzepec          #+#    #+#             */
/*   Updated: 2018/12/13 16:13:43 by anrzepec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void			print_flags(t_flags flags)
{
	printf("attribs: %s\n", flags.attributes);
	printf("width: %d\n", flags.width);
	printf("precision: %d\n", flags.precision);
	printf("modifier: %s\n", flags.modifier);
	printf("format: %c\n", flags.format);
}

static int		ft_get_var(const char *format, int len, va_list ap)
{
	int 	i;
	t_flags flags;

	flags = reset_flags(flags);
	format = format + len;
	if ((i = ft_format_parser(&flags, format)) == -1)
		return (-1);
	print_flags(flags);
	return (len + i);
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
			if ((ret = ft_get_var(format, i, ap)) == -1)
				return (-1);
		}
		printf("%d\n", ret);
		format = format + ret;
		i = 0;
	}
	return (len);
}