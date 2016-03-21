/* gcc -m32 -fno-stack-protector binexp200.c -o binexp200.out */

#include <stdio.h>

int main() {
  int authenticated = 0;
  char password[16];

  fgets(password, 24, stdin);

  if (authenticated) {
    printf("CTFIME{%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c}\n",
           98, 117, 102, 102, 51, 114, 48, 118, 51, 114, 102, 108, 48,
           119, 49, 115, 110, 48, 116, 115, 48, 104, 52, 114, 100);
  } else {
    printf("Access Denied!\n");
  }

  return 0;
}
