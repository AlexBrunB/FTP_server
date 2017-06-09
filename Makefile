##
## Makefile for Makefile in /home/abrun/delivery/Tek2/PSU/PSU_2016_myftp
## 
## Made by Alexandre Brun
## Login   <abrun@epitech.net>
## 
## Started on  Wed May 10 11:38:09 2017 Alexandre Brun
## Last update Sun May 21 18:52:52 2017 Alexandre Brun
##

CC		=	gcc

RM		=	rm -f

CFLAGS		=	-Wall -Wextra

SERVER_NAME	=	server


SERVER_SRC	=	server.c	\
			utils.c		\
			my_commands.c


SERVER_OBJS	=	$(SERVER_SRC:.c=.o)


all	:		server

server	:		$(SERVER_OBJS)
			$(CC) -o $(SERVER_NAME) $(SERVER_OBJS)

clean	:
			$(RM) $(SERVER_OBJS)

fclean	:		clean
			$(RM) $(SERVER_NAME)

re	:		fclean all

.PHONY	:		all clean fclean re server
