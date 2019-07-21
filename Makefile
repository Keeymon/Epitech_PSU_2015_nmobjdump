##
## Makefile for  in /home/picher_y/rendu/PSU_2015_nmobjdump
## 
## Made by Yann Pichereau
## Login   <picher_y@epitech.net>
## 
## Started on  Thu Feb 18 15:24:13 2016 Yann Pichereau
## Last update Sat Feb 20 00:57:39 2016 Yann Pichereau
##

NM_DIR =	nm/

NM =		nm

OBJDUMP_DIR = 	objdump/

OBJDUMP =	objdump

all :		$(NM) $(OBJDUMP)


$(NM) :
		make -C $(NM_DIR)

$(OBJDUMP) :
		make -C $(OBJDUMP_DIR)

clean :
		make clean -C $(NM_DIR)
		make clean -C $(OBJDUMP_DIR)

fclean :
		make fclean -C $(NM_DIR)
		make fclean -C $(OBJDUMP_DIR)

re :		fclean all

.PHONY :	all clean fclean re $(NM) $(OBJDUMP)
