/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrzepec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/03 12:25:58 by anrzepec          #+#    #+#             */
/*   Updated: 2019/01/06 14:19:02 by andrewrze        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		get_base(char *base)
{
	char	*buff;
	int		i;

	i = 0;
	if (!(buff = (char*)ft_memalloc(ft_strlen(base))))
		return (0);
	while (base[i])
	{
		if (ft_strchr(buff, (int)base[i]))
			return (0);
		buff[i] = base[i];
		i++;
	}
	ft_strdel(&buff);
	return (i);
}

static int		get_int_divlen(long long int nb, int div)
{
	int	len;

	len = 0;
	while (nb)
	{
		nb = nb / div;
		len++;
	}
	return ((len = len == 0 ? 1 : len));
}

int				add_negative_sign(char **s, int neg)
{
	char *tmp;

	tmp = NULL;
	if (neg)
	{
		if (!(tmp = ft_strjoin("-", *s)))
			return (0);
		ft_strdel(s);
		*s = tmp;
	}
	return (1);
}

char			*ft_itoa_base(long long int nb, char *base)
{
	int		i;
	int		c;
	int		res;
	int		neg;
	char	*toa;

	if (!base)
		return (NULL);
	if (!(res = get_base(base)))
		return (NULL);
	i = get_int_divlen(nb, res);
	if (!(toa = (char*)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	c = 0;
	if (nb == 0)
		toa[0] = base[0];
    neg = nb < 0 ? 1 : 0;
    nb = neg ? nb * -1 : nb;
	while (nb)
	{
		toa[i - c - 1] = base[(unsigned long long int)nb % res];
		nb = nb / res;
		c++;
	}
	toa[i] = '\0';
	if (!add_negative_sign(&toa, neg))
		return (NULL);
	return (toa);
}
