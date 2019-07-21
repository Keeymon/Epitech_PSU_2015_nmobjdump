##
## Makefile for  in /home/picher_y/rendu/PSU_2015_nmobjdump/nm
## 
## Made by Yann Pichereau
## Login   <picher_y@epitech.net>
## 
## Started on  Thu Feb 18 15:31:42 2016 Yann Pichereau
## Last update Sun Feb 28 21:20:55 2016 Yann Pichereau
##

NAME = 		my_nm

CC =		cc

CP =		cp

RM =		rm -f

CFLAGS +=	-W -Wall -Wextra -Werror -I./include/

SRCS = 		src/nm.c \
		src/init_function.c \
		src/display_function.c \
		src/string_function.c \
		src/sym.c

OBJS =		$(SRCS:.c=.o)

all :		$(NAME)

$(NAME) :	$(OBJS)
		$(CC) -o $(NAME) $(OBJS) $(CFLAGS)
		$(CP) $(NAME) ../
		$(CP) include/nm.h ../

clean :		
		$(RM) $(OBJS)

fclean  :	clean
		$(RM) $(NAME)
		$(RM) ../$(NAME)
		$(RM) ../nm.h

re :		fclean all

.PHONY :	all clean fclean re
