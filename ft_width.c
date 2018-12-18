/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_width.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrzepec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 14:15:06 by anrzepec          #+#    #+#             */
/*   Updated: 2018/12/18 16:03:44 by anrzepec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_apply_attrib(int len, char **s, t_flags flags)
{
	if ()
	return (1);
}

int		ft_apply_width(char **s, t_flags flags)
{
	int		len;
	char 	*tmp;

	tmp = *s;
	if (flags.format == 'p')
	{
		if (!(*s = ft_strjoin("0x", *s)))
			return (0);
		ft_strdel(&tmp);
		tmp = *s;
	}
	if ((len = flags.width - ft_strlen(*s)) > 0)
		if (!ft_apply_attrib(len, s, flags))
			return (0);
	else
		if (!ft_apply_attrib(0, s, flags))
			return (0);
	if (tmp != *s)
		ft_strdel(&tmp);
	return (1);
}