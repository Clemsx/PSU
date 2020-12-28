/*
** elf64.c for ftrace in /home/kelizarov/EPITECH/PSU_2016_ftrace/srcs
**
** Made by Kirill Elizarov
** Login   <kirill.elizarov@epitech.eu>
**
** Started on  Fri May  5 13:07:49 2017 Kirill Elizarov
** Last update Sun May  7 22:18:18 2017 Leo Blouard
*/

#include "ftrace.h"

Elf64_Sym	*get_symbol(t_elf *elf, Elf64_Addr addr)
{
  unsigned int	i;
  unsigned int	j;
  Elf64_Sym	*symtab;

  i = 0;
  while (i < elf->ehdr->e_shnum)
    {
      if (elf->shdr[i].sh_type == SHT_SYMTAB)
	{
	  symtab = (Elf64_Sym*)&elf->mem[elf->shdr[i].sh_offset];
	  j = 0;
	  while (j < elf->shdr[i].sh_size / sizeof(Elf64_Sym))
	    {
	      if (symtab->st_value == addr)
		return (symtab);
	      symtab++;
	      j++;
	    }
	}
      i++;
    }
  return (NULL);
}

char		*get_strtab(t_elf *elf)
{
  unsigned int	i;

  i = 0;
  while (i < elf->ehdr->e_shnum)
    {
      if (elf->shdr[i].sh_type == SHT_SYMTAB)
	return (char*)&elf->mem[elf->shdr[elf->shdr[i].sh_link].sh_offset];
      i++;
    }
  return (NULL);
}

char		*get_symbol_name(t_elf *elf, Elf64_Sym *symtab)
{
  char		*strtab;

  strtab = get_strtab(elf);
  return (&strtab[symtab->st_name]);
}

int		setup_elf(t_elf *elf, char **av)
{
  int		fd;
  struct stat	file_info;

  fd = open(av[1], O_RDONLY);
  if (fd == -1)
    {
      fprintf(stderr, "%s: Cannot open the binary\n", av[0]);
      return (0);
    }
  if (fstat(fd, &file_info) < 0)
    {
      fprintf(stderr, "%s: Failed to load information about the binary\n", av[0]);
      return (0);
    }
  elf->mem = mmap(0, file_info.st_size, PROT_READ, MAP_PRIVATE, fd, 0);
  if (elf->mem == MAP_FAILED)
    {
      fprintf(stderr, "%s: Failed to map the binary into memory\n", av[0]);
      return 0;
    }
  elf->ehdr = (Elf64_Ehdr*)elf->mem;
  elf->phdr = (Elf64_Phdr*)(elf->mem + elf->ehdr->e_phoff);
  elf->shdr = (Elf64_Shdr*)(elf->mem + elf->ehdr->e_shoff);
  close(fd);
  return (1);
}
