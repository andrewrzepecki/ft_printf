/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_apply_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrzepec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 15:09:42 by anrzepec          #+#    #+#             */
/*   Updated: 2018/12/14 22:08:45 by anrzepec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char 		*ft_unknown_var(va_list ap, char c);

char 		*ft_fetch_var(t_flags flags, va_list ap)
{
	char 	*str;
	t_var	*tab;

	if (!(str = ft_memalloc(2)))
		return (NULL);
	if (!(tab = set_struct_tab()))
		return (NULL);
	if (ft_strchr("diouxXpbscf", flags->format))
	{
		i = -1;
		while (++i < 4)
			if (ft_strchr(tab[i].format, flags->format))
				if (!(str = tab[i].f(ap, flags)))
					return (NULL);
	}
	else
		if (!(str = ft_unknown_var(ap, flags)))
			return (NULL);
	return (str);
}