/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_precision.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrzepec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 17:33:39 by anrzepec          #+#    #+#             */
/*   Updated: 2018/12/15 18:25:44 by anrzepec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_apply_precision(char **s, t_flags flags)
{
	char *tmp;

	if (flags.precision == -1)
		return (1);
	if (flags.format == 's' && ft_strlen(s) > flags.precision)
	{
		tmp = *s;
		if (!(*s = ft_strsub(*s, 0, flags.precision)))
			return (0);
		ft_strdel(&tmp);
	}
	else if (ft_strchr("diouxX", flags.format))
	{
		
	}
	return (1);
}