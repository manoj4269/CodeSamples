//Program to reverse a given string

#include "stdio.h"

int main(void) {
  printf("Hello World\n");
  char s[] = "malayalam";
  int n = strlen(s);
  printf("%d \n", n);
  int i, j;
  char temp;
  for (i=0, j=n;i<(n/2);i++, j--){
    temp = s[i];
    s[i] = s[j-1];
    s[j-1] = temp;
  }
  
  printf("%s", s);
  
  return 0;
}
