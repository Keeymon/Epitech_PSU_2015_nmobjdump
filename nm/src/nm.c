/*
** nm.c for  in /home/picher_y/rendu/PSU_2015_nmobjdump/nm/src
** 
** Made by Yann Pichereau
** Login   <picher_y@epitech.net>
** 
** Started on  Thu Feb 18 16:22:12 2016 Yann Pichereau
** Last update Sun Feb 28 23:13:16 2016 Yann Pichereau
*/

#include <sys/mman.h>
#include <stdlib.h>
#include <unistd.h>
#include "nm.h"

int	nm(char *filename)
{
  int	size;
  int	fd;
  void	*ptr;
  t_elf	*elf;

  if ((elf = malloc(sizeof(t_elf))) == NULL)
    return (1);
  if ((size = open_file(filename, &fd)) == -1)
    return (1);
  if ((ptr = init_map(fd, size)) == NULL)
    return (1);
  close (fd);
  elf->e_elf = ptr;
  elf->e_ptr = ptr;
  if (elf_format(elf->e_elf->e_ident, filename) == 1)
    return (1);
  display_info(elf);
  munmap(ptr, size);
  return (0);
}

int	main(int ac, char **av)
{
  int	i;

  if (ac == 1)
    {
      if (nm(DEFAULT_FILE) == 1)
	return (1);
    }
  else if (ac > 1)
    {
      i = 1;
      while (i < ac)
	{
	  nm(av[i]);
	  i++;
	}
    }
  return (0);
}
