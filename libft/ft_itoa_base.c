/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrewrzepecki <anrzepec@student.42.f      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 23:53:54 by andrewrze         #+#    #+#             */
/*   Updated: 2019/01/02 15:29:59 by andrewrze        ###   ########.fr       */
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

static int		get_int_divlen(long long nb, int div)
{
    int	len;

    len = 0;
    while (nb)
    {
        nb = nb / div;
        len++;
    }
    return (len);
}

char			*ft_itoa_base(long long nb, char *base)
{
    int		i;
    int		c;
    int		res;
    char	*toa;

    if (!base)
        return (NULL);
    if (!(res = get_base(base)))
        return (NULL);
    i = get_int_divlen(nb, res);
    if (!(toa = (char*)malloc(sizeof(char) * (i + 1))))
        return (NULL);
    c = 0;
    while (nb)
    {
        toa[i - c - 1] = base[nb % res];
        nb = nb / res;
        c++;
    }
    toa[i] = '\0';
    return (toa);
}
