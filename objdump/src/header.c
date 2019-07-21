/*
** header.c for  in /home/picher_y/rendu/PSU_2015_nmobjdump/objdump/src
** 
** Made by Yann Pichereau
** Login   <picher_y@epitech.net>
** 
** Started on  Thu Feb 18 23:52:38 2016 Yann Pichereau
** Last update Sat Feb 20 20:50:08 2016 Yann Pichereau
*/

#include <stdio.h>
#include "objdump.h"

char	*get_class(int class)
{
  if (class == ELFCLASS32)
    return (CLASS_32);
  else if (class == ELFCLASS64)
    return (CLASS_64);
  return (CLASS_NONE);
}

char	*get_machine(int machine)
{
  if (machine == NONE_MACH)
    return (S_NONE_MACH);
  else if (machine == SPARC)
    return (S_SPARC);
  else if (machine == X86)
    return (S_X86);
  else if (machine == MIPS)
    return (S_MIPS);
  else if (machine == POWERPC)
    return (S_POWERPC);
  else if (machine == ARM)
    return (S_ARM);
  else if (machine == SUPERH)
    return (S_SUPERH);
  else if (machine == IA64)
    return (S_IA64);
  else if (machine == X8664)
    return (S_X8664);
  else if (machine == AARCH64)
    return (S_AARCH64);
  return ("none");
}
