/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrzepec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 10:19:07 by anrzepec          #+#    #+#             */
/*   Updated: 2019/02/05 12:05:30 by anrzepec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_fjoin(char *s1, char *s2)
{
	char	*tmp;
	char	*res;

	if (ft_strlen(s2))
	{
		if (!(tmp = ft_strjoin(s1, ".")))
			return (NULL);
		ft_strdel(&s1);
		if (!(res = ft_strjoin(tmp, s2)))
			return (NULL);
		ft_strdel(&s2);
		ft_strdel(&tmp);
		return (res);
	}
	ft_strdel(&s2);
	return (s1);
}

char		*ft_floating_right(long double mod, int precision)
{
	int		i;
	char	*s;
	char	*num;
	char	*tmp;

	i = 0;
	if (!(s = ft_memalloc(1)))
		return (NULL);
	mod = (mod < 0) ? mod * -1 : mod;
	if (!(num = ft_memalloc(2)))
		return (NULL);
	while (i++ < precision)
	{
		mod = ft_fmod(mod * 10, 10);
		if (i == precision)
			mod = (long long)mod % 10 >= 5 ? mod + 1 : mod;
		num[0] = (int)mod + '0';
		tmp = s;
		if (!(s = ft_strjoin(s, num)))
			return (NULL);
		ft_strdel(&tmp);
	}
	return (s);
}

char		*ft_ftoa(long double nb, int precision)
{
	char		*left;
	char		*right;
	long long	ent;
	long double	mod;

	ent = (long long)(nb);
	mod = nb - ent;
	if (!mod)
	{
		if (!(right = ft_memalloc(precision + 1)))
			return (NULL);
		right = (char*)ft_memset(right, '0', (size_t)precision);
	}
	else if (!(right = ft_floating_right(mod, precision)))
		return (NULL);
	if (!(left = ft_itoa_base(ent, "0123456789")))
		return (NULL);
	return (ft_fjoin(left, right));
}
