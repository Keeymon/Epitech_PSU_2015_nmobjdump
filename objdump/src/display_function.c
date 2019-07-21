/*
** display_function.c for  in /home/picher_y/rendu/PSU_2015_nmobjdump/objdump/src
** 
** Made by Yann Pichereau
** Login   <picher_y@epitech.net>
** 
** Started on  Sat Feb 20 20:58:30 2016 Yann Pichereau
** Last update Sun Feb 28 23:30:21 2016 Yann Pichereau
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "objdump.h"

char	display_hexa(unsigned char c)
{
  printf(HEXA, c);
  if (isprint(c))
    return (c);
  return ('.');
}

void		display_content(Elf64_Shdr *s_elf, unsigned char *str)
{
  unsigned int	i;
  unsigned int	j;
  char		buf[BUFF + 1];

  i = 0;
  while (i < s_elf->sh_size)
    {
      printf(ADR, s_elf->sh_addr + i);
      j = 0;
      while (j < BUFF)
        {
          buf[j] = ' ';
          if (i + j < s_elf->sh_size)
            buf[j] = display_hexa(str[i + j]);
          else
            printf("  ");
          j++;
          if (j % 4 == 0)
            printf(" ");
        }
      buf[j] = '\0';
      printf(STR, buf);
      i += j;
    }
}

void		display_section(Elf64_Ehdr *elf)
{
  int		i;
  unsigned char	*strname;
  Elf64_Shdr	*s_elf;

  s_elf = (void*)elf + elf->e_shoff;
  strname = (unsigned char*)((void*)elf + s_elf[elf->e_shstrndx].sh_offset);
  i = 0;
  while (i < elf->e_shnum)
    {
      if (s_elf[i].sh_type != SHT_NOBITS
          && strcmp((char *)&strname[s_elf[i].sh_name], ".strtab") != 0
          && strcmp((char *)&strname[s_elf[i].sh_name], ".shstrtab") != 0
          && s_elf[i].sh_type != SHT_SYMTAB
          && s_elf[i].sh_type != SHT_NULL
	  && s_elf[i].sh_size != 0)
        {
          printf(SECTION, &strname[s_elf[i].sh_name]);
          display_content(&s_elf[i],
                          (unsigned char*)((void*)elf + s_elf[i].sh_offset));
        }
      i++;
    }
}
