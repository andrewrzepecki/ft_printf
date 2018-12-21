/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrzepec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 15:06:07 by anrzepec          #+#    #+#             */
/*   Updated: 2018/12/19 17:09:53 by andrewrze        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	unsigned int len;

    if (!str)
        return (NULL);
	len = 0;
	while (str[len])
	{
		if (str[len] == (char)c)
			return ((char*)str + len);
		len++;
	}
	if (str[len] == c)
		return ((char*)str + len);
	else
		return (NULL);
}
