/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_width.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrzepec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 14:15:06 by anrzepec          #+#    #+#             */
/*   Updated: 2018/12/18 19:22:57 by anrzepec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_apply_width(char **s, t_flags flags)
{

	return (1);
}

int		ft_space_attrib(char **s)
{
	return (1);
}

int		ft_plus_attrib(char **s)
{
	return (1);
}

int		ft_hash_attrib(char **s, t_flags flags)
{
	return (1);
}

int		ft_apply_attrib(char **s, t_flags flags)
{
	if (ft_strchr(flags.attributes, '#') || flags.format == 'p')
		if (!ft_hash_attrib(s, flags))
			return (0);
	if (ft_strchr(flags.attributes, '+'))
	{
		if (!ft_plus_attrib(s))
			return (0);
	}
	else if (ft_strchr(flags.attributes, ' '))
		if (!ft_space_attrib(s))
			return (0);
	if ((len = flags.width - ft_strlen(*s)) > 0)
		if (ft_strchr(flags.attributes, '0') || ft_strchr(flags.attributes, '-'))
			if (!ft_apply_width(s, flags))
				return (0);
	return (1);
}
