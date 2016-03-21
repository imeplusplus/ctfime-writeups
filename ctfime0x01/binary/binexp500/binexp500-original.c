// gcc -m32 -fno-stack-protector binexp500.c -o binexp500.out

#include <stdio.h>
#include <string.h>

void print_flag() {
  printf("CTFIME{%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c}\n",
         110, 105, 99, 101, 95, 106, 111, 98, 95, 99, 111, 110, 116,
         114, 111, 108, 108, 105, 110, 103, 95, 101, 105, 112);
}

int main(int argc, char** argv) {
  if (argc < 2)
    return 1;

  char buffer[32];
  strcpy(buffer, argv[1]);

  return 0;
}
