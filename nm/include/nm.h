/*
** nm.h for  in /home/picher_y/rendu/PSU_2015_nmobjdump/nm/include
** 
** Made by Yann Pichereau
** Login   <picher_y@epitech.net>
** 
** Started on  Thu Feb 18 16:22:03 2016 Yann Pichereau
** Last update Sun Feb 28 21:40:02 2016 Yann Pichereau
*/

#ifndef NM_H_
# define NM_H_

# include <elf.h>

# define E_SHNUM(e) (e->e_elf->e_shnum)
# define OFFSET(e) (e->s_elf[e->e_elf->e_shstrndx].sh_offset)
# define SH_OFFSET(e, i) (e->s_elf[i].sh_offset)
# define SH_TYPE(e, i) (e->s_elf[i].sh_type)
# define SH_SIZE(e, i) (e->s_elf[i].sh_size)
# define SH_ENTSIZE(e, i) (e->s_elf[i].sh_entsize)
# define P_SECTION(e) ((unsigned char*)(e->e_ptr + OFFSET(e)))
# define N_SECTION(e, i) ((char*)&e->section[e->s_elf[i].sh_name])
# define ITER(e, i) (e->sym_tab[i]->st_shndx)

# define DEFAULT_FILE "a.out"

# define FORMAT "nm: %s: File format not recognized\n"
# define NOFILE "nm: '%s': No such file\n"
# define ERROR "Error: %s\n"
# define VALUE "%016x"
# define SYMBOLE " %c %s\n"

typedef struct	b_elf
{
  void		*e_ptr;
  Elf64_Ehdr	*e_elf;
  Elf64_Shdr	*s_elf;
  Elf64_Sym	**sym_tab;
  Elf64_Sym	*sym;
  int		nb_sym;
  int		size;
  unsigned char	*strname;
  unsigned char	*section;
  char		*sym_str;
}		t_elf;

int	elf_format(unsigned char *ident, char *filename);
int	open_file(char *filename, int *fd);
void	*init_map(int fd, int size);
int	display_info(t_elf *elf);
void	sort_sym(Elf64_Sym **sym_tab, unsigned char *strname);
int	get_sym(t_elf *elf);

#endif /* !NM_H_  */
