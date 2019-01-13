# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anrzepec <anrzepec@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/17 19:12:20 by anrzepec          #+#    #+#              #
#    Updated: 2019/01/13 16:10:43 by andrewrze        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	= 	libftprintf.a

SRC 	= 	ft_printf.c \
			format_parser.c \
			ft_apply_flags.c \
			ft_attributes.c \
			ft_data_types.c \
			ft_modifier.c \
			ft_precision.c \
			ft_width.c		\
			ft_wildcard.c	\
			debugtools/print_var.c

OBJS	=	$(SRC:.c=.o)

CC		=	gcc 

CFLAGS	+=	-Werror -Wall -Wextra

RM		=	rm -f

LIB		=	ar rc

LPATH	=	libft/*.o

all:		$(LIB) $(NAME)

%.o:		%.c	
			$(CC) $(CFLAGS) -c $< -o $@

$(LIB):	
			make -C libft/

$(NAME):	$(OBJS)
			$(LIB) $(NAME) $(OBJS) $(LPATH)

fcleanlib:  cleanlib
			make fclean -C libft/

cleanlib:
			make clean -C libft/

clean:		cleanlib
			$(RM) $(OBJS)

fclean:		fcleanlib clean
			$(RM) $(NAME)

re:			fclean all

.PHONY: re all fclean clean
