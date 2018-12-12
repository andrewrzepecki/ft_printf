/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrzepec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 12:41:48 by anrzepec          #+#    #+#             */
/*   Updated: 2018/12/12 17:51:36 by anrzepec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>i

typedef struct	s_flags
{
	char		*attributes;
	int			width;
	int			precision;
	char		*modifier;
	char		format;
}				t_flags;

typedef struct	s_get_format
{
	char		*format;
	int			(*f)(t_flags *, const char *, int *);
}				t_get_format;

int				ft_printf(const char *format, ...);
int				ft_get_flags(const char *format, t_flags flags);

#endif