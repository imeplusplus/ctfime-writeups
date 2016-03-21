/* gcc -m32 -fno-stack-protector binexp200.c -o binexp200.out */

#include <stdio.h>

int main() {
  int authenticated = 0;
  char password[16];

  fgets(password, 24, stdin);

  if (authenticated) {
    printf("CTFIME{FLAG_GOES_HERE}\n");
  } else {
    printf("Access Denied!\n");
  }

  return 0;
}
