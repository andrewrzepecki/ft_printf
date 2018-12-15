/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_apply_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrzepec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 15:09:42 by anrzepec          #+#    #+#             */
/*   Updated: 2018/12/15 18:42:01 by anrzepec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_float_var(va_list ap, t_flags flags)
{
	char *s;

	return (s);
}

char		*ft_char_var(va_list ap, t_flags flags)
{
	char *s;
	
	if (!(s = ft_memalloc(2)))
		return (NULL);
	*s = va_arg(ap, int);
	return (s);
}

char		*ft_str_var(va_list ap, t_flags flags)
{
	char *s;
	
	if (!(s = ft_strdup((char*)va_arg(ap, char *))))
		if (!(s = ft_strdup("(null)")))
			return (NULL);
	if (!ft_apply_precision(&s, flags))
		return (NULL);
	return (s);
}

char 		*ft_numeric_var(va_list ap, t_flags flags)
{
	char					*s;
	unsigned long long int	ud;
	long long int			ld;

	if (flags.format == 'd' || flags.format == 'i')
	{
		if (!(ld = ft_apply_modifier(ap, flags)))
			return (NULL);
		if (!(s = ft_itoa_base((int)ld, "0123456789")))
			return (NULL);
	}
	else
	{
		if (!(ud = ft_apply_modifier(ap, flags)))
			return (NULL);
		if (!(s = ft_unsigned_value(ud, flags)))
			return (NULL);
	}
	if (!(ft_apply_precision(&s, flags)))
		return (NULL);
	return (s);
}

char 		*ft_apply_flags(va_list ap, t_flags flags)
{
	int		i;
	char 	*str;
	t_var	*tab;

	if (!(tab = set_struct_tab()))
		return (NULL);
	if (ft_strchr("diouxXpbscf", flags.format))
	{
		i = -1;
		while (++i < 4)
			if (ft_strchr(tab[i].format, flags.format))
				if (!(str = tab[i].f(ap, flags)))
					return (NULL);
	}
	else
		if (!(str = ft_unknown_var(ap, flags)))
			return (NULL);
	if (!(ft_apply_attrib(&str, ap)))
		return (NULL);
	if (!(ft_apply_width(&str, ap)))
		return (NULL);
	return (str);
}