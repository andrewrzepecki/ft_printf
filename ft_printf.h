/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrzepec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 12:41:48 by anrzepec          #+#    #+#             */
/*   Updated: 2018/12/13 16:13:02 by anrzepec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>

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

int				get_attribute_flag(t_flags *flags, char const *format, int *i);
int				get_modifier_flag(t_flags *flags, char const *format, int *i);
int				get_precision_flag(t_flags *flags, char const *format, int *i);
int				get_width_flag(t_flags *flags, char const *format, int *i);

int				ft_printf(const char *format, ...);
int				ft_get_flags(const char *format, t_flags flags);
int				ft_format_parser(t_flags *flags, const char *format);

t_flags			reset_flags(t_flags flags);
#endif