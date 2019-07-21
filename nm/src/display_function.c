/*
** display_function.c for  in /home/picher_y/rendu/PSU_2015_nmobjdump/nm/src
** 
** Made by Yann Pichereau
** Login   <picher_y@epitech.net>
** 
** Started on  Sat Feb 20 21:23:25 2016 Yann Pichereau
** Last update Sun Feb 28 21:24:47 2016 Yann Pichereau
*/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "nm.h"

void	display_value(t_elf *elf, int i)
{
  if (elf->sym_tab[i]->st_value != 0)
    printf(VALUE, (unsigned int)elf->sym_tab[i]->st_value);
  else
    printf("%16s", "");
  printf(SYMBOLE, elf->sym_str[i], &elf->strname[elf->sym_tab[i]->st_name]);
}

int	init_symtab(t_elf *elf)
{
  int	i;
  int	j;

  i = 0;
  elf->size = 0;
  while (i < elf->nb_sym)
    {
      if (elf->sym[i].st_name != 0 && elf->sym[i].st_info != STT_FILE)
	elf->size++;
      i++;
    }
  if ((elf->sym_tab = malloc(sizeof(Elf64_Sym) * (elf->size + 1))) == NULL)
    return (1);
  elf->sym_tab[elf->size] = NULL;
  i = 0;
  j = 0;
  while (i < elf->nb_sym)
    {
      if (elf->sym[i].st_name != 0 && elf->sym[i].st_info != STT_FILE)
	elf->sym_tab[j++] = &elf->sym[i];
      i++;
    }
  sort_sym(elf->sym_tab, elf->strname);
  return (0);
}

void	free_elf(t_elf *elf)
{
  free(elf->sym_tab);
  free(elf->sym_str);
  free(elf);
}

int	display_info(t_elf *elf)
{
  int	i;

  elf->s_elf = elf->e_ptr + elf->e_elf->e_shoff;
  elf->section = P_SECTION(elf);
  i = -1;
  while (++i < E_SHNUM(elf))
    {
      if (strcmp(N_SECTION(elf, i), ".strtab") == 0)
	elf->strname = (unsigned char*)elf->e_ptr + SH_OFFSET(elf, i);
      else if (SH_TYPE(elf, i) == SHT_SYMTAB)
	{
	  elf->nb_sym = SH_SIZE(elf, i) / SH_ENTSIZE(elf, i);
	  elf->sym = elf->e_ptr + SH_OFFSET(elf, i);
	}
    }
  if (init_symtab(elf) == 1)
    return (1);
  get_sym(elf);
  i = -1;
  while (++i < elf->size)
    display_value(elf, i);
  free_elf(elf);
  return (0);
}
