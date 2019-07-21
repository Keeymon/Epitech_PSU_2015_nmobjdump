/*
** nm.c for  in /home/picher_y/rendu/PSU_2015_nmobjdump/objdump/src
** 
** Made by Yann Pichereau
** Login   <picher_y@epitech.net>
** 
** Started on  Thu Feb 18 16:16:12 2016 Yann Pichereau
** Last update Sun Feb 28 23:39:27 2016 Yann Pichereau
*/

#include <sys/mman.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include "objdump.h"

void	get_flags(char *filename)
{
  int	size;

  size = strlen(filename);
  if (strcmp(filename + (size - 3), ".so") == 0)
    {
      printf(FLAGS, "0x00000150:");
      printf("\nHAS_SYMS, DYNAMIC, D_PAGED");
    }
  else if (strcmp(filename + (size - 2), ".o") == 0)
    {
      printf(FLAGS, "0x00000011:");
      printf("\nHAS_RELOC, HAS_SYMS");
    }
  else
    {
      printf(FLAGS, "0x00000112:");
      printf("\nEXEC_P, HAS_SYMS, D_PAGED");
    }
}

int		objdump(char *filename)
{
  int		size;
  int		fd;
  void		*ptr;
  Elf64_Ehdr	*elf;

  if ((size = open_file(filename, &fd)) == -1)
    return (1);
  if ((ptr = init_map(fd, size)) == NULL)
    return (1);
  close(fd);
  elf = ptr;
  if (elf_format(elf->e_ident, filename) == 1)
    return (1);
  printf(HEADER, filename, get_class(elf->e_ident[EI_CLASS]),
	 get_machine(elf->e_machine));
  printf(ARCHI, get_machine(elf->e_machine));
  get_flags(filename);
  if ((long unsigned int)elf->e_entry == 0)
    printf("\nstart address 0x0000000000000000\n\n");
  else
    printf(BEGIN_PTR, (long unsigned int)elf->e_entry);
  display_section(elf);
  munmap(ptr, size);
  return (0);
}

int	main(int ac, char **av)
{
  int	i;

  if (ac == 1)
    {
      if (objdump(DEFAULT_FILE) == 1)
	return (1);
    }
  else if (ac > 1)
    {
      i = 1;
      while (i < ac)
	{
	  objdump(av[i]);
	  i++;
	}
    }
  return (0);
}
