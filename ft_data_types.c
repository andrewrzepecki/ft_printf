/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_data_types.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrzepec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 18:16:01 by anrzepec          #+#    #+#             */
/*   Updated: 2018/12/15 17:58:02 by anrzepec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_get_format	*set_flag_tab(void)
{
	t_get_format	*tab;
	
	if (!(tab = (t_get_format*)malloc(sizeof(t_get_format) * 4)))
		return (NULL);
	if (!(tab[0].format = ft_strdup("#+-0")))
		return (NULL);
	tab[0].f = &get_attribute_flag;
	if (!(tab[1].format = ft_strdup("0123456789")))
		return (NULL);
	tab[1].f = &get_width_flag;
	if (!(tab[2].format = ft_strdup(".")))
		return (NULL);
	tab[2].f = &get_precision_flag;
	if (!(tab[3].format = ft_strdup("hlL")))
		return (NULL);
	tab[3].f = &get_modifier_flag;
	return (tab);
}

t_var			*set_struct_tab(void)
{
	t_var	*tab;

	if (!(tab = (t_var*)malloc(sizeof(t_var) * 4)))
		return (NULL);
	if (!(tab[0].format = ft_strdup("diouxXpb")))
		return (NULL);
	tab[0].f = &ft_numeric_var;
	if (!(tab[1].format = ft_strdup("s")))
		return (NULL);
	tab[1].f = &ft_str_var;
	if (!(tab[2].format = ft_strdup("c")))
		return (NULL);
	tab[2].f = &ft_char_var;
	if (!(tab[3].format = ft_strdup("f")))
		return (NULL);
	tab[3].f = &ft_float_var;
//	if (!(tab[4].format = ft_strdup("")))
//		return (NULL);
//	tab[4].f = function_name;
	return (tab);
}

t_flags			reset_flags(t_flags flags)
{
	flags.attributes = NULL;
	flags.width = 0;
	flags.precision = -1;
	flags.modifier = NULL;
	flags.format = 0;
	return (flags);
}