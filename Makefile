# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: inicole- <inicole-@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/14 15:07:24 by inicole-          #+#    #+#              #
#    Updated: 2022/11/21 16:32:46 by inicole-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER	= server

CLIENT	= client

SRCS	= client.c server.c minitalk_utils.c

S_OBJ	= server.o minitalk_utils.o
C_OBJ	= client.o minitalk_utils.o

FLAGS	= -Wall -Werror -Wextra -g
CC		= cc $(FLAGS)

LIBFT	= libft/libft.a

all: $(LIBFT) $(SERVER) $(CLIENT)

.c.o: $(SRCS)
		cc -Wall -Wextra -Werror -c -o $@ $<
	
$(LIBFT) : 
	cd libft && make

$(SERVER) : $(S_OBJ)
	$(CC) $(S_OBJ) $(LIBFT) -o $@

$(CLIENT) : $(C_OBJ)
	$(CC) $(C_OBJ) $(LIBFT) -o $@

clean :
		rm -f *.o
	
fclean: clean
		cd ./libft && make fclean
		rm -f $(SERVER) $(CLIENT)

re: fclean all

.PHONY:	all clean fclean re
