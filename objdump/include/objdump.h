/*
** nm.h for  in /home/picher_y/rendu/PSU_2015_nmobjdump/objdump/include
** 
** Made by Yann Pichereau
** Login   <picher_y@epitech.net>
** 
** Started on  Thu Feb 18 16:15:55 2016 Yann Pichereau
** Last update Sun Feb 28 22:43:08 2016 Yann Pichereau
*/

#ifndef OBJDUMP_H_
# define OBJDUMP_H_

# include <elf.h>

# define NONE_MACH 0x00
# define S_NONE_MACH "none mach"
# define SPARC 0x02
# define S_SPARC "SPARC"
# define X86 0x03
# define S_X86 "x86"
# define MIPS 0x08
# define S_MIPS "MIPS"
# define POWERPC 0x14
# define S_POWERPC "PowerPC"
# define ARM 0x28
# define S_ARM "ARM"
# define SUPERH 0x2A
# define S_SUPERH "SuperH"
# define IA64 0x32
# define S_IA64 "IA-64"
# define X8664 0x3E
# define S_X8664 "x86-64"
# define AARCH64 0xB7
# define S_AARCH64 "AArch64"

# define CLASS_32 "elf32"
# define CLASS_64 "elf64"
# define CLASS_NONE "unknow"

# define DEFAULT_FILE "a.out"

# define HEADER "\n%s:     format file %s-%s"
# define ARCHI "\narchitecture: i386:%s"
# define FLAGS ", flags %s"
# define BEGIN_PTR "\nstart address %#018lx\n\n"
# define FORMAT "objdump: %s: File format not recognized\n"
# define NOFILE "objdump: '%s': No such file\n"
# define SECTION "Contents of section %s:\n"
# define ERROR "Error: %s\n"

# define BUFF 16

# define ADR " %04lx "
# define HEXA "%02x"
# define STR " %s\n"

typedef struct	b_elf
{
  void		*e_ptr;
  Elf32_Ehdr	*elf32;
  Elf64_Ehdr	*elf64;
  Elf32_Sym	*elf32_s;
  Elf64_Sym	*elf64_s;
}		t_elf;

int	elf_format(unsigned char *ident, char *filename);
int	open_file(char *filename, int *fd);
void	*init_map(int fd, int size);
char	*get_class(int class);
char	*get_machine(int machine);
char	display_hexa(unsigned char c);
void	display_content(Elf64_Shdr *s_elf, unsigned char *str);
void	display_section(Elf64_Ehdr *elf);

#endif /* !OBJDUMP_H_ */
