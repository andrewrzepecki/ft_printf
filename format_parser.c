/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_parser.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrzepec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 17:23:21 by anrzepec          #+#    #+#             */
/*   Updated: 2018/12/13 16:06:03 by anrzepec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "get_format.h"

int				get_attribute_flag(t_flags *flags, char const *format, int *i)
{
	char *tmp;
	char *attrib;

	if (!(attrib = ft_strndup(&format[*i], 1)))
		return (-1);
	if (!flags->attributes)
		flags->attributes = attrib;
	else
	{
		tmp = flags->attributes;
		if (!(flags->attributes = ft_strjoin(tmp, attrib)))
			return (-1);
	//	free(tmp);
	}
	//ft_strdel(&attrib);
	return (0);
}

int				get_modifier_flag(t_flags *flags, char const *format, int *i)
{
	if (flags->modifier)
		ft_strdel(&flags->modifier);
	if (format[*i + 1] == format[*i] && format[*i] != 'L')
	{
		if (!(flags->modifier = ft_strsub(format, *i, 2)))
			return (-1);
		(*i++);
	}
	else
	{
		if (!(flags->modifier = ft_strsub(&format[*i], 0, 1)))
			return (-1);
	}
	return (0);
}

int				get_precision_flag(t_flags *flags, char const *format, int *i)
{
	(*i++);
	flags->precision = ft_atoi(&format[*i]);
	while (format[*i] >= '0' && format[*i] <= '9')
		(*i)++;
	(*i)--;
	return (0);
}

int				get_width_flag(t_flags *flags, char const *format, int *i)
{
	flags->width = ft_atoi(&format[*i]);
	while (format[*i] >= '0' && format[*i] <= '9')
		(*i)++;
	(*i)--;
	return (0);
}

int				ft_format_parser(t_flags *flags, const char *format)
{
	int i;
	int j;

	i = 1;
	while (ft_strchr("#+-0 .0123456789hlL", format[i]) && format[i])
	{
		j = -1;
		while (++j < 4)
			if (ft_strchr(g_format_tab[j].format, format[i]))
			{
				if (g_format_tab[j].f(flags, format, &i) == -1)
					return (-1);
				break;
			}
		i++;
	}
	if (format[i])
		flags->format = format[i++];
	return (i);
}