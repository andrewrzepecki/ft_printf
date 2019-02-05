/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fmod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrzepec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 10:25:08 by anrzepec          #+#    #+#             */
/*   Updated: 2019/02/05 12:44:06 by anrzepec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int fast_floor(long double x) 
{
	int xi;
	xi = (int)x;
	return (x < xi ? xi - 1 : xi);
}

long double			ft_fmod(long double nb, long double mod)
{
	return (nb - mod * fast_floor(nb / mod));
}
