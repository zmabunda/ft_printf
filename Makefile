# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zmabunda <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/27 09:39:14 by zmabunda          #+#    #+#              #
#    Updated: 2018/08/27 11:41:44 by zmabunda         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRS = ft_hex.c ft_print_percent.c ft_printf.h ft_string.c \
      ft_addptr.c ft_memcpy.c ft_print_str.c ft_specifiers.c \
      ft_strlen.c ft_char.c ft_octal.c ft_print_wchar.c \
      ft_strchr_f.c ft_strsub.c ft_conversion.c ft_printfatoi.c \
      ft_print_wstr.c ft_strdel.c ft_unsigned.c ft_digit.c \
      ft_print_char.c ft_printf.c ft_strdup.c

FLAG = -Wall -Werror -Wextra

OBJ = ft_octal.o ft_strchr_f.o ft_printfatoi.o ft_strdel.o \
	  ft_print_char.o ft_strdup.o ft_addptr.o ft_print_percent.o \
	  ft_string.o ft_char.o ft_print_str.o ft_strlen.o \
      ft_conversion.o ft_print_wchar.o ft_strsub.o \
	  ft_digit.o ft_print_wstr.o ft_unsigned.o ft_hex.o \
	  ft_printf.o ft_memcpy.o ft_specifiers.o \


all: $(NAME)

$(NAME):
	gcc $(FLAG) -c $(SRS) -I ft_printf.h
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)
	
re: fclean all
