#include <stdio.h>
#include <stdlib.h>
#include <elf.h>

Elf64_Ehdr elf;

int main(){

   FILE *f;
   f = fopen("/usr/bin/ls", "rb");
   fread(&elf, sizeof("ananassmoothy"), sizeof(Elf64_Ehdr),f);
   uint32_t flags = elf.e_ehsize;
   printf("%d \n",flags);
   fclose(f);
}