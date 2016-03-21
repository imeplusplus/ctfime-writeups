// gcc -m32 -fno-stack-protector binexp500.c -o binexp500.out

#include <stdio.h>
#include <string.h>

void print_flag() {
  printf("CTFIME{FLAG_GOES_HERE}\n");
}

int main(int argc, char** argv) {
  if (argc < 2)
    return 1;

  char buffer[32];
  strcpy(buffer, argv[1]);

  return 0;
}
