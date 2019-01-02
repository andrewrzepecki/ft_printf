/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrewrzepecki <anrzepec@student.42.f      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 19:17:07 by andrewrze         #+#    #+#             */
/*   Updated: 2018/12/28 15:54:49 by andrewrze        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void    ft_strrev(char *str)
{
    int     i;
    int     j;
    char     tmp;

    if (str)
    {
        i = -1;
        j = ft_strlen(str);
        while (++i < --j)
        {
            tmp = str[i];
            str[i] = str[j];
            str[j] = tmp;
        }
    }
}
