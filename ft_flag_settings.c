/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_settings.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrzepec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 15:59:33 by anrzepec          #+#    #+#             */
/*   Updated: 2018/12/13 16:13:33 by anrzepec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flags			reset_flags(t_flags flags)
{
	flags.attributes = NULL;
	flags.width = 0;
	flags.precision = 0;
	flags.modifier = NULL;
	flags.format = 0;
	return (flags);
}