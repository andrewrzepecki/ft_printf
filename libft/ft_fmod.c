/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fmod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrzepec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 10:25:08 by anrzepec          #+#    #+#             */
/*   Updated: 2019/02/04 12:52:34 by anrzepec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long double			ft_fmod(long double nb, long double mod)
{
	long double		res;

	res = nb;
	while (res >= mod)
		res -= mod;
	return (res);
}
