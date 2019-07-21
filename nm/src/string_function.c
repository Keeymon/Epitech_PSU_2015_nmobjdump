/*
** string_function.c for  in /home/picher_y/rendu/PSU_2015_nmobjdump/nm/src
** 
** Made by Yann Pichereau
** Login   <picher_y@epitech.net>
** 
** Started on  Mon Feb 22 03:34:02 2016 Yann Pichereau
** Last update Sun Feb 28 21:26:21 2016 Yann Pichereau
*/

#include <string.h>
#include <stdlib.h>
#include "nm.h"

unsigned char	*print_format(unsigned char *str, unsigned char *ret)
{
  int	i;
  int	j;
  int	count;

  i = -1;
  j = 0;
  count = 0;
  while (str[++i] != '\0')
    {
      if ((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z')
          || (str[i] >= '0' && str[i] <= '9'))
        count++;
    }
  if ((ret = malloc(sizeof(unsigned char) * (count + 1))) == NULL)
    return (NULL);
  ret[count] = '\0';
  i = -1;
  while (str[++i])
    {
      if ((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z')
          || (str[i] >= '0' && str[i] <= '9'))
        ret[j++] = str[i];
    }
  return (ret);
}

int		cmp_sym(unsigned char *s1, unsigned char *s2)
{
  unsigned char	*cmp1;
  unsigned char	*cmp2;

  cmp1 = NULL;
  cmp2 = NULL;
  if ((cmp1 = print_format(s1, cmp1)) == NULL)
    return (1);
  if ((cmp2 = print_format(s2, cmp2)) == NULL)
    return (1);
  if (strcasecmp((char*)cmp1, (char*)cmp2) > 0)
    {
      free(cmp1);
      free(cmp2);
      return (1);
    }
  free(cmp1);
  free(cmp2);
  return (0);
}

void		swap_sym(Elf64_Sym **sym_tab, int i)
{
  Elf64_Sym	*tmp;

  tmp = sym_tab[i];
  sym_tab[i] = sym_tab[i + 1];
  sym_tab[i + 1] = tmp;
}

void	sort_sym(Elf64_Sym **sym_tab, unsigned char *strname)
{
  int	sort;
  int	i;

  sort = 1;
  while (sort == 1)
    {
      sort = 0;
      i = 0;
      while (sym_tab[i] != NULL && sym_tab[i + 1] != NULL)
	{
	  if (cmp_sym(&strname[sym_tab[i]->st_name],
		      &strname[sym_tab[i + 1]->st_name]) == 1)
	    {
	      swap_sym(sym_tab, i);
	      sort = 1;
	    }
	  i++;
	}
    }
}
