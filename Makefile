# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anrzepec <anrzepec@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/17 19:12:20 by anrzepec          #+#    #+#              #
#    Updated: 2019/01/02 16:27:48 by andrewrze        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	= 	printflibft.a

SRC 	= 	ft_printf.c \
			format_parser.c \
			ft_apply_flags.c \
			ft_attributes.c \
			ft_data_types.c \
			ft_modifier.c \
			ft_precision.c 

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
