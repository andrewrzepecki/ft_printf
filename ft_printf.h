/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrzepec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 12:41:48 by anrzepec          #+#    #+#             */
/*   Updated: 2019/01/13 16:09:31 by andrewrze        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>

# define INDEX      0
# define POSITION   1
# define VLEN       2
# define RETURN     3

typedef struct	s_flags
{
	char			*attributes;
	int				width;
	int				precision;
	char			*modifier;
	char			format;
}					t_flags;

typedef struct		s_get_format
{
	char			*format;
	int				(*f)(t_flags *, const char *, int *);
    int             (*fnum)(t_flags *, const char *, int *, va_list ap);
}					t_get_format;

typedef struct		s_var
{
	char 			*format;
	char			*(*f)(va_list, t_flags);
}					t_var;

char				*ft_numeric_var(va_list ap, t_flags flags);
char				*ft_str_var(va_list ap, t_flags flags);
char				*ft_char_var(va_list ap, t_flags flags, int *len);
char				*ft_float_var(va_list ap, t_flags flags);

int					get_attribute_flag(t_flags *flags, char const *format, int *i);
int					get_modifier_flag(t_flags *flags, char const *format, int *i);
int					get_precision_flag(t_flags *flags, char const *format, int *i, va_list ap);
int					get_width_flag(t_flags *flags, char const *format, int *i, va_list ap);

int                 ft_width_wildcard(t_flags *flags, va_list ap);
int                 ft_precision_wildcard(t_flags *flags, va_list ap);

int					ft_printf(const char *format, ...);
int					ft_get_flags(const char *format, t_flags flags);
int					ft_format_parser(t_flags *flags, const char *format, va_list ap);
char				*ft_apply_flags(va_list ap, t_flags flags, int *len);
unsigned long long	ft_apply_umodifier(va_list ap, t_flags flags);
long long int       ft_apply_modifier(va_list ap, t_flags flags);
int             	ft_apply_precision(char **s, t_flags flags);
int             	ft_apply_attrib(char **s, t_flags flags, int *len);
int             	ft_apply_width(char **s, t_flags flags, int width, int *len);
int                 ft_invert_prefix(char **s, char *prefix, t_flags flags, int *len);

char				*ft_unsigned_value(unsigned long long d, t_flags flags);
void            	ft_varchar_free(int nb, ...);
t_flags				reset_flags(void);
t_var           	*set_struct_tab(void);
t_get_format    	*set_flag_tab(void);

/*
 * DEBUGGING FUNCTIONS
 *
*/

void                ft_print_flags(t_flags flags);

#endif
