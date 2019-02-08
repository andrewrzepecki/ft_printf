# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anrzepec <anrzepec@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/17 19:12:20 by anrzepec          #+#    #+#              #
#    Updated: 2019/02/08 12:07:11 by anrzepec         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	= 	libftprintf.a

SRC 	= 	ft_printf.c \
			format_parser.c \
			ft_apply_flags.c \
			ft_attributes.c \
			ft_struct_settings.c \
			ft_modifier.c \
			ft_precision.c \
			ft_width.c		\
			ft_wildcard.c	\
			ft_tools.c		\
			libft/ft_strchr.c \
			libft/ft_strlen.c \
			libft/ft_strdel.c \
			libft/ft_memset.c \
			libft/ft_memcpy.c \
			libft/ft_memalloc.c \
			libft/ft_strdup.c \
			libft/ft_strndup.c \
			libft/ft_strjoin.c \
			libft/ft_strcmp.c \
			libft/ft_strsub.c \
			libft/ft_atoi.c \
			libft/ft_ftoa.c \
			libft/ft_itoa_base.c \
			libft/ft_uitoa_base.c \
			libft/ft_fmod.c \
			libft/ft_floor.c \
			libft/ft_memdel.c
			
OBJS	=	$(SRC:.c=.o)

CC		=	gcc 

CFLAGS	+=	-Werror -Wall -Wextra

RM		=	rm -f

LIB		=	ar rc

all:		$(NAME)

%.o:		%.c	
			$(CC) $(CFLAGS) -c $< -o $@

$(NAME):	$(OBJS)
			$(LIB) $(NAME) $(OBJS)

clean:
			$(RM) $(OBJS)

fclean:
			$(RM) $(OBJS) $(NAME)

re:			fclean all

.PHONY: re all fclean clean
