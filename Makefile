# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wwatik <wwatik@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/19 00:30:16 by wwatik            #+#    #+#              #
#    Updated: 2023/06/19 05:54:44 by wwatik           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

SRC_C = mandelbrot.c julia.c fractol.c utils.c 

CC = cc -Wall -Wextra -Werror

OBJS_C = ${SRC_C:%.c=%.o}

all :  $(NAME) 

$(NAME) : $(OBJS_C)
	$(CC) $(OBJS_C) -lmlx -framework OpenGl -framework AppKit -o $(NAME)
%.o : %.c fractol.h
	$(CC) -c $< -o $@

clean :
	rm -f $(OBJS_C)
fclean : clean
	rm -f $(NAME)


re : fclean all 

.PHONY :  all clean fclean re
