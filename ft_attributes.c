/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_attributes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrzepec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 14:15:06 by anrzepec          #+#    #+#             */
/*   Updated: 2019/01/09 17:45:45 by anrzepec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char			*ft_move_prefix(char *s, char *prefix, t_flags flags)
{
	char	*del;
	char	*tmp;
	char	*str;

	tmp = ft_strchr("Xxbp", flags.format) ? ft_strsub(s, 2, ft_strlen(s) - 2)
		: ft_strsub(s, 1, ft_strlen(s) - 1);
	if (!tmp)
		return (NULL);
	if (!(del = ft_strjoin(prefix, tmp)))
		return (NULL);
	ft_strdel(&tmp);
	tmp = ft_strchr("Xxbp", flags.format) ? ft_strndup(s, 2) : ft_strndup(s, 1);
	if (!tmp)
		return (NULL);
	if (!(str = ft_strjoin(tmp, del)))
		return (NULL);
	ft_varchar_free(2, &tmp, &del);
	return (str);
}

int				ft_apply_width(char **s, t_flags flags, int width)
{
	char	*tmp;
	char	prefix[width + 1];

	ft_memset(prefix, ' ', width);
	prefix[width] = '\0';
	tmp = *s;
	if (ft_strchr(flags.attributes, '0') && !ft_strchr(flags.attributes, '-')
			&& !(ft_strchr("diOouUxXbp", flags.format) && flags.precision <\
				flags.width && flags.precision != -1))
		ft_memset(prefix, '0', width);
	if (ft_strchr(flags.attributes, '-'))
	{
		if (!(*s = ft_strjoin(*s, prefix)))
			return (1);
	}
	else if (ft_strchr(flags.attributes, '0') && ((ft_strchr(flags.attributes, '#')
			&& ft_strchr("OoxXb", flags.format) && !(ft_strlen(*s) == 1 && s[0][0] == '0'))
				|| flags.format == 'p' || (ft_strchr("+- ", s[0][0]) && ft_strchr("Ddi", flags.format)))
					&& !(ft_strchr("diOouUxXbp", flags.format) && flags.precision < flags.width
						&& flags.precision != -1))
	{
		if (!(*s = ft_move_prefix(*s, prefix, flags)))
			return (0);
	}
	else if (!(*s = ft_strjoin(prefix, *s)))
		return (0);
	//ft_strdel(&tmp);
	return (1);
}

int				ft_sign_attrib(char **s, t_flags flags)
{
	char	*tmp;

	if (ft_strchr("Ddi", flags.format) && s[0][0] != '-')
	{
		tmp = *s;
		*s = ft_strchr(flags.attributes, '+') ? ft_strjoin("+", *s)
			: ft_strjoin(" ", *s);
		ft_strdel(&tmp);
	}
	if (*s == NULL)
		return (0);
	return (1);
}

int				ft_hash_attrib(char **s, t_flags flags)
{
	char	*tmp;

	if (ft_strchr("pxXbOo", flags.format) == NULL || (!ft_strcmp(*s, "0") && flags.format != 'p')
			|| (!ft_strlen(*s) && !ft_strchr("Oo", flags.format)))
		return (1);
	tmp = *s;
	if (ft_strchr("xXp", flags.format))
		*s = flags.format == 'X' ? ft_strjoin("0X", *s) : ft_strjoin("0x", *s);
	else if (flags.format == 'b')
		*s = ft_strjoin("0b", *s);
	else
		*s = ft_strjoin("0", *s);
	ft_strdel(&tmp);
	if (*s == NULL)
		return (0);
	return (1);
}

int		ft_apply_attrib(char **s, t_flags flags, int *len)
{
	int	width;

	if ((ft_strchr(flags.attributes, '#') || flags.format == 'p')
			&& !(flags.format == 'o' && (int)ft_strlen(*s) == flags.precision 
				&& s[0][0] == '0'))
		if (!ft_hash_attrib(s, flags))
			return (0);
	if (ft_strchr(flags.attributes, '+') || ft_strchr(flags.attributes, ' '))
	{
		if (!ft_sign_attrib(s, flags))
			return (0);
	}
	if ((width = flags.width - ft_strlen(*s) - *len) > 0)
		if (!ft_apply_width(s, flags, width))
			return (0);
	return (1);
}
