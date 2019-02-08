/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_floor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrzepec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 12:03:37 by anrzepec          #+#    #+#             */
/*   Updated: 2019/02/08 12:05:35 by anrzepec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long		ft_floor(long double nb)
{
	long long	nbi;

	nbi = (long long)nb;
	return (nb < nbi ? nbi - 1 : nbi);
}
