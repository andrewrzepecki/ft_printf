/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_data_types.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrzepec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 18:16:01 by anrzepec          #+#    #+#             */
/*   Updated: 2018/12/14 22:08:47 by anrzepec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_numeric_var(va_list ap, char c)
{
	char					*str;
	unsigned long long int	d;
	
	d = va_arg(ap, unsigned long long int);
	
	return (str);	
}

t_var		set_struct_tab(void)
{
	t_var	*tab;

	if (!(tab = (t_var*)malloc(sizeof(t_var) * 4)))
		return (NULL);
	if (!(tab[0].format = ft_strdup("diouxXpb")))
		return (NULL);
	tab[0].f = ft_numeric_var;
	if (!(tab[1].format = ft_strdup("s")))
		return (NULL);
	tab[1].f = ft_str_var;
	if (!(tab[2].format = ft_strdup("c")))
		return (NULL);
	tab[2].f = ft_char_var;
	if (!(tab[3].format = ft_strdup("f")))
		return (NULL);
	tab[3].f = ft_float_var;
//	if (!(tab[4].format = ft_strdup("")))
//		return (NULL);
//	tab[4].f = function_name;

}