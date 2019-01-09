/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_modifier.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrzepec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/03 17:43:03 by anrzepec          #+#    #+#             */
/*   Updated: 2019/01/09 16:39:10 by anrzepec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned long long		ft_apply_umodifier(va_list ap, t_flags flags)
{
	unsigned long long int	d;

	d = 0;
	if (!flags.modifier && !ft_strchr("Up", flags.format))
		d = va_arg(ap, unsigned int);
	else if (ft_strchr("Uup", flags.format))
		d = va_arg(ap, unsigned long long int);
	else if (ft_strlen(flags.modifier) == 2 || ft_strchr(flags.modifier, 'j')
			|| ft_strchr(flags.modifier, 'z'))
	{
		if (flags.modifier[0] == 'l' || ft_strchr(flags.modifier, 'j')
				|| ft_strchr(flags.modifier, 'z'))
			d = va_arg(ap, unsigned long long int);
		else
			d = (unsigned char)va_arg(ap, unsigned long long int);
	}
	else
	{
		if (flags.modifier[0] == 'l')
			d = va_arg(ap, unsigned long int);
		else if (flags.modifier[0] != 'L')
			d = va_arg(ap, unsigned int);
		else
			d = va_arg(ap, unsigned int);
	}
	return (d);
}

long long int			ft_apply_modifier(va_list ap, t_flags flags)
{
	long long int	d;

	d = 0;
	if (!flags.modifier && flags.format != 'D')
		d = va_arg(ap, int);
	else if (flags.format == 'D' || ft_strlen(flags.modifier) == 2
			|| ft_strchr(flags.modifier, 'j') || ft_strchr(flags.modifier, 'z'))
	{
		if (flags.format == 'D' || flags.modifier[0] == 'l'
				|| ft_strchr(flags.modifier, 'j') || ft_strchr(flags.modifier, 'z'))
			d = va_arg(ap, long long int);
		else
			d = (char)va_arg(ap, int);
	}
	else
	{
		if (flags.modifier[0] == 'l')
			d = (long)va_arg(ap, long);
		else if (flags.modifier[0] == 'L' && flags.format == 'f')
			d = (long double)va_arg(ap, long double);
		else if (flags.modifier[0] != 'L')
			d = (short)va_arg(ap, int);
		else
			d = va_arg(ap, int);
	}
	return (d);
}
