/*
** sym.c for  in /home/picher_y/rendu/PSU_2015_nmobjdump/nm/src
** 
** Made by Yann Pichereau
** Login   <picher_y@epitech.net>
** 
** Started on  Sun Feb 28 21:20:04 2016 Yann Pichereau
** Last update Sun Feb 28 21:53:55 2016 Yann Pichereau
*/

#include <string.h>
#include <stdlib.h>
#include "nm.h"

int	get_symbis(t_elf *elf, int i)
{
  if (ELF64_ST_BIND(elf->sym_tab[i]->st_info) == STB_WEAK)
    {
      if (!elf->sym_tab[i]->st_value)
        elf->sym_str[i] = (ELF64_ST_TYPE(elf->sym_tab[i]->st_info)
                           == STT_OBJECT ? 'v' : 'w');
      else
        elf->sym_str[i] = (ELF64_ST_TYPE(elf->sym_tab[i]->st_info)
                           == STT_OBJECT ? 'V' : 'W');
    }
  else if (elf->sym_tab[i]->st_shndx == SHN_ABS)
    elf->sym_str[i] = 'A';
  else if (elf->sym_tab[i]->st_shndx == SHN_UNDEF)
    elf->sym_str[i] = 'U';
  else if (elf->sym_tab[i]->st_shndx == SHN_COMMON)
    elf->sym_str[i] = 'C';
  if (elf->sym_str[i] == '?')
    return (1);
  return (0);
}

void	symbole(t_elf *elf, int i)
{
  elf->sym_str[i] = '?';
  if (get_symbis(elf, i) == 0)
    return ;
  if (elf->s_elf[elf->sym_tab[i]->st_shndx].sh_type == SHT_PROGBITS
      && elf->s_elf[elf->sym_tab[i]->st_shndx].sh_flags == SHF_ALLOC)
    elf->sym_str[i] = 'r';
  else if (strcmp(N_SECTION(elf, elf->sym_tab[i]->st_shndx), ".bss") == 0)
    elf->sym_str[i] = 'b';
  else if (ELF64_ST_TYPE(elf->sym_tab[i]->st_info) == STT_FUNC
	   || strcmp(N_SECTION(elf, ITER(elf, i)), ".text") == 0
	   || strncmp(N_SECTION(elf, ITER(elf, i)), ".fini", 5) == 0
	   || strncmp(N_SECTION(elf, ITER(elf, i)), ".init", 5) == 0)
    elf->sym_str[i] = 't';
  else if (ELF64_ST_TYPE(elf->sym_tab[i]->st_info) == STT_OBJECT
	   || ELF64_ST_TYPE(elf->sym_tab[i]->st_info) == STT_NOTYPE
	   || strcmp(N_SECTION(elf, ITER(elf, i)), ".data") == 0
	   || strcmp(N_SECTION(elf, ITER(elf, i)), ".data1") == 0)
    elf->sym_str[i] = 'd';
  if (ELF64_ST_BIND(elf->sym_tab[i]->st_info) != STB_LOCAL)
    elf->sym_str[i] -= 32;
}

int	get_sym(t_elf *elf)
{
  int	i;

  if ((elf->sym_str = malloc(sizeof(char) * (elf->size + 1))) == NULL)
    return (1);
  elf->sym_str[elf->size] = '\0';
  i = 0;
  while (elf->sym_tab[i] != NULL)
    {
      symbole(elf, i);
      i++;
    }
  return (0);
}
