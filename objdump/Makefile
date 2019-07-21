##
## Makefile for  in /home/picher_y/rendu/PSU_2015_nmobjdump/objdump
## 
## Made by Yann Pichereau
## Login   <picher_y@epitech.net>
## 
## Started on  Thu Feb 18 15:31:57 2016 Yann Pichereau
## Last update Sat Feb 20 21:02:23 2016 Yann Pichereau
##

NAME =		my_objdump

CC =		cc

CP =		cp

RM =		rm -f

CFLAGS +=	-W -Wall -Werror -Wextra -I./include/

SRCS =		src/objdump.c \
		src/init_function.c \
		src/header.c \
		src/display_function.c

OBJS =		$(SRCS:.c=.o)

all :		$(NAME)

$(NAME) :	$(OBJS)
		$(CC) -o $(NAME) $(OBJS) $(CFLAGS)
		$(CP) $(NAME) ../
		$(CP) include/objdump.h ../

clean :
		$(RM) $(OBJS)

fclean :	clean
		$(RM) $(NAME)
		$(RM) ../$(NAME)
		$(RM) ../objdump.h

re :		fclean all

.PHONY :	all clean fclean re
