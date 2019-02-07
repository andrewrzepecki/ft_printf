/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fmod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrzepec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 10:25:08 by anrzepec          #+#    #+#             */
/*   Updated: 2019/02/07 12:33:18 by anrzepec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long			fast_floor(long double x)
{
	long long	xi;

	xi = (long long)x;
	return (x < xi ? xi - 1 : xi);
}

long double			ft_fmod(long double nb, long double mod)
{
	return (nb - mod * fast_floor(nb / mod));
}
