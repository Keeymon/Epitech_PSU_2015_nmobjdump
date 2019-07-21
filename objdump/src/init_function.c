/*
** elf_format.c for  in /home/picher_y/rendu/PSU_2015_nmobjdump/objdump/src
** 
** Made by Yann Pichereau
** Login   <picher_y@epitech.net>
** 
** Started on  Thu Feb 18 22:41:18 2016 Yann Pichereau
** Last update Sat Feb 20 20:57:42 2016 Yann Pichereau
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <stdio.h>
#include "objdump.h"

int		open_file(char *filename, int *fd)
{
  struct stat	sb;

  if ((*fd = open(filename, O_RDONLY)) < 0)
    {
      fprintf(stderr, NOFILE, DEFAULT_FILE);
      return (-1);
    }
  if (fstat(*fd, &sb) == -1)
    {
      fprintf(stderr, ERROR, "stat");
      return (-1);
    }
  return (sb.st_size);
}

void	*init_map(int fd, int size)
{
  void	*ptr;

  if ((ptr = mmap(NULL, size, PROT_READ, MAP_PRIVATE, fd, 0)) == MAP_FAILED)
    {
      fprintf(stderr, ERROR, "mmap");
      return (NULL);
    }
  return (ptr);
}

int	elf_format(unsigned char *ident, char *filename)
{
  if (ident[EI_MAG0] == ELFMAG0
      && ident[EI_MAG1] == ELFMAG1
      && ident[EI_MAG2] == ELFMAG2
      && ident[EI_MAG3] == ELFMAG3)
    return (0);
  fprintf(stderr, FORMAT, filename);
  return (1);
}
